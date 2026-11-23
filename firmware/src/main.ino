#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>

// ======================================================
// PASTILLERO INTELIGENTE - TEI201
// ENTREGA FINAL
//
// Microcontrolador: ESP32
//
// CONEXIONES:
// Sensor / botón  -> GPIO27
// LED rojo        -> GPIO25 + resistencia 300 ohm
// Buzzer pasivo   -> GPIO26
//                   mediante resistencia 1 kOhm
//                   y transistor BC547
// GND             -> Tierra común
//
// FUNCIONES:
// - Genera alerta visual y sonora.
// - Detecta interacción con el pastillero.
// - Registra eventos.
// - Mantiene historial en memoria LittleFS.
// - Calcula indicadores de cumplimiento.
// - Crea dashboard web local.
// ======================================================


// ======================================================
// 1. PINES
// ======================================================

const int PIN_SENSOR = 27;
const int PIN_LED = 25;
const int PIN_BUZZER = 26;


// ======================================================
// 2. CONFIGURACIÓN WIFI
// ======================================================

// La ESP32 crea su propia red WiFi.

const char* WIFI_NOMBRE = "Pastillero-IoT";
const char* WIFI_PASSWORD = "pastillero123";


// ======================================================
// 3. CONFIGURACIÓN DE ALERTAS
// ======================================================

// Para la demostración final se utiliza un intervalo
// acelerado para no esperar horas reales.
//
// Primera alerta: 15 segundos después del encendido.
// Alertas siguientes: cada 60 segundos.

const unsigned long PRIMERA_ALERTA_MS = 15000;
const unsigned long INTERVALO_ALERTA_MS = 60000;

// Frecuencia del buzzer pasivo.

const int FRECUENCIA_BUZZER = 1000;


// ======================================================
// 4. VARIABLES
// ======================================================

bool alarmaActiva = false;

bool estadoAnteriorSensor = HIGH;

unsigned long inicioSistema = 0;
unsigned long ultimaAlerta = 0;
unsigned long inicioAlarma = 0;

unsigned long ultimoCambioSensor = 0;

const unsigned long DEBOUNCE_MS = 200;

unsigned long dosisProgramadas = 0;
unsigned long dosisTomadas = 0;
unsigned long ultimaLatenciaSeg = 0;


// ======================================================
// 5. SERVIDOR WEB
// ======================================================

WebServer server(80);


// ======================================================
// 6. DASHBOARD
// ======================================================

const char PAGINA_WEB[] PROGMEM = R"rawliteral(

<!DOCTYPE html>

<html lang="es">

<head>

<meta charset="UTF-8">

<meta name="viewport"
content="width=device-width, initial-scale=1.0">

<title>Pastillero Inteligente</title>

<style>

body {
    font-family: Arial, sans-serif;
    background: #f4f6f8;
    margin: 0;
    padding: 20px;
    color: #1f2937;
}

.container {
    max-width: 900px;
    margin: auto;
}

h1 {
    margin-bottom: 5px;
}

.subtitulo {
    color: #6b7280;
    margin-bottom: 25px;
}

.estado {
    padding: 14px;
    border-radius: 10px;
    font-weight: bold;
    text-align: center;
    margin-bottom: 20px;
}

.ok {
    background: #dcfce7;
    color: #166534;
}

.alerta {
    background: #fee2e2;
    color: #991b1b;
}

.grid {
    display: grid;
    grid-template-columns:
        repeat(auto-fit, minmax(180px, 1fr));
    gap: 15px;
}

.card {
    background: white;
    padding: 20px;
    border-radius: 14px;
    box-shadow:
        0 2px 8px rgba(0,0,0,0.08);
}

.valor {
    font-size: 30px;
    font-weight: bold;
    margin-top: 8px;
}

button {
    border: none;
    border-radius: 9px;
    padding: 12px 18px;
    margin-top: 20px;
    cursor: pointer;
    font-size: 15px;
}

.btn-alerta {
    background: #111827;
    color: white;
}

.btn-borrar {
    background: #e5e7eb;
    color: #111827;
    margin-left: 8px;
}

table {
    width: 100%;
    border-collapse: collapse;
    margin-top: 15px;
    background: white;
}

th,
td {
    padding: 9px;
    border-bottom:
        1px solid #e5e7eb;
    text-align: left;
    font-size: 14px;
}

th {
    background: #f9fafb;
}

</style>

</head>

<body>

<div class="container">

<h1>Pastillero Inteligente</h1>

<div class="subtitulo">
TEI201 · Monitoreo de toma de medicamentos
</div>

<div
id="estadoSistema"
class="estado ok">

Sistema conectado

</div>


<div class="grid">

<div class="card">

<div>Dosis programadas</div>

<div
class="valor"
id="programadas">

0

</div>

</div>


<div class="card">

<div>Dosis tomadas</div>

<div
class="valor"
id="tomadas">

0

</div>

</div>


<div class="card">

<div>Dosis pendientes</div>

<div
class="valor"
id="pendientes">

0

</div>

</div>


<div class="card">

<div>Cumplimiento</div>

<div
class="valor"
id="cumplimiento">

0 %

</div>

</div>


<div class="card">

<div>Último tiempo de respuesta</div>

<div
class="valor"
id="latencia">

0 s

</div>

</div>


<div class="card">

<div>Tiempo del sistema</div>

<div
class="valor"
id="tiempo">

0 s

</div>

</div>

</div>


<button
class="btn-alerta"
onclick="activarAlerta()">

Activar alerta de prueba

</button>


<button
class="btn-borrar"
onclick="borrarDatos()">

Borrar historial

</button>


<h2>Historial de eventos</h2>


<table>

<thead>

<tr>

<th>Tiempo</th>
<th>Evento</th>
<th>Valor</th>

</tr>

</thead>


<tbody id="historial">

</tbody>

</table>

</div>


<script>

async function actualizarEstado() {

    try {

        const respuesta =
            await fetch('/api/status');

        const datos =
            await respuesta.json();


        document.getElementById(
            "programadas"
        ).innerText =
            datos.programadas;


        document.getElementById(
            "tomadas"
        ).innerText =
            datos.tomadas;


        document.getElementById(
            "pendientes"
        ).innerText =
            datos.pendientes;


        document.getElementById(
            "cumplimiento"
        ).innerText =
            datos.cumplimiento + " %";


        document.getElementById(
            "latencia"
        ).innerText =
            datos.latencia + " s";


        document.getElementById(
            "tiempo"
        ).innerText =
            datos.tiempo + " s";


        const estado =
            document.getElementById(
                "estadoSistema"
            );


        if (datos.alarma) {

            estado.innerText =
                "ALERTA ACTIVA: DOSIS PENDIENTE";

            estado.className =
                "estado alerta";

        } else {

            estado.innerText =
                "SISTEMA ACTIVO: SIN ALERTA";

            estado.className =
                "estado ok";
        }

    }

    catch(error) {

        document.getElementById(
            "estadoSistema"
        ).innerText =
            "Sin conexión con el dispositivo";
    }
}



async function actualizarHistorial() {

    try {

        const respuesta =
            await fetch(
                '/api/historial'
            );

        const texto =
            await respuesta.text();


        const lineas =
            texto.trim().split("\n");


        let html = "";


        for (
            let i = lineas.length - 1;
            i >= 1 &&
            i >= lineas.length - 20;
            i--
        ) {

            const columnas =
                lineas[i].split(",");


            if (
                columnas.length >= 3
            ) {

                html +=
                    "<tr>" +
                    "<td>" +
                    columnas[0] +
                    " s</td>" +
                    "<td>" +
                    columnas[1] +
                    "</td>" +
                    "<td>" +
                    columnas[2] +
                    "</td>" +
                    "</tr>";
            }
        }


        document.getElementById(
            "historial"
        ).innerHTML =
            html;

    }

    catch(error) {

    }
}



async function activarAlerta() {

    await fetch(
        '/api/alerta'
    );

    actualizarEstado();
    actualizarHistorial();
}



async function borrarDatos() {

    if (
        confirm(
            "¿Borrar todo el historial?"
        )
    ) {

        await fetch(
            '/api/borrar'
        );

        actualizarEstado();
        actualizarHistorial();
    }
}



setInterval(
    function() {

        actualizarEstado();
        actualizarHistorial();

    },
    2000
);


actualizarEstado();
actualizarHistorial();

</script>

</body>

</html>

)rawliteral";


// ======================================================
// 7. REGISTRAR EVENTO
// ======================================================

void registrarEvento(
    String evento,
    unsigned long valor
) {

    File archivo =
        LittleFS.open(
            "/eventos.csv",
            FILE_APPEND
        );


    if (!archivo) {

        Serial.println(
            "ERROR: no se pudo abrir eventos.csv"
        );

        return;
    }


    unsigned long tiempo =
        millis() / 1000;


    archivo.print(tiempo);

    archivo.print(",");

    archivo.print(evento);

    archivo.print(",");

    archivo.println(valor);


    archivo.close();
}


// ======================================================
// 8. CREAR ARCHIVO DE DATOS
// ======================================================

void iniciarArchivo() {

    if (
        !LittleFS.exists(
            "/eventos.csv"
        )
    ) {

        File archivo =
            LittleFS.open(
                "/eventos.csv",
                FILE_WRITE
            );


        if (archivo) {

            archivo.println(
                "segundos,evento,valor"
            );

            archivo.close();
        }
    }
}


// ======================================================
// 9. RECUPERAR DATOS ANTERIORES
// ======================================================

void cargarEstadisticas() {

    dosisProgramadas = 0;
    dosisTomadas = 0;
    ultimaLatenciaSeg = 0;


    File archivo =
        LittleFS.open(
            "/eventos.csv",
            FILE_READ
        );


    if (!archivo) {

        return;
    }


    // Saltar encabezado CSV

    archivo.readStringUntil('\n');


    while (
        archivo.available()
    ) {

        String linea =
            archivo.readStringUntil(
                '\n'
            );


        linea.trim();


        if (
            linea.length() == 0
        ) {

            continue;
        }


        int primeraComa =
            linea.indexOf(',');


        int segundaComa =
            linea.indexOf(
                ',',
                primeraComa + 1
            );


        if (
            primeraComa < 0 ||
            segundaComa < 0
        ) {

            continue;
        }


        String evento =
            linea.substring(
                primeraComa + 1,
                segundaComa
            );


        String valor =
            linea.substring(
                segundaComa + 1
            );


        if (
            evento ==
            "ALERTA_ACTIVADA"
        ) {

            dosisProgramadas++;
        }


        if (
            evento ==
            "DOSIS_CONFIRMADA"
        ) {

            dosisTomadas++;

            ultimaLatenciaSeg =
                valor.toInt();
        }
    }


    archivo.close();
}


// ======================================================
// 10. ACTIVAR ALARMA
// ======================================================

void activarAlarma() {

    if (
        alarmaActiva
    ) {

        return;
    }


    alarmaActiva = true;


    inicioAlarma =
        millis();


    dosisProgramadas++;


    digitalWrite(
        PIN_LED,
        HIGH
    );


    // Buzzer pasivo

    tone(
        PIN_BUZZER,
        FRECUENCIA_BUZZER
    );


    registrarEvento(
        "ALERTA_ACTIVADA",
        0
    );


    Serial.println(
        "ALERTA ACTIVADA - DOSIS PENDIENTE"
    );
}


// ======================================================
// 11. CONFIRMAR DOSIS
// ======================================================

void confirmarDosis() {

    // Si se pulsa el sensor sin que exista
    // una alerta, también se registra.

    if (
        !alarmaActiva
    ) {

        registrarEvento(
            "INTERACCION_SIN_ALERTA",
            0
        );


        Serial.println(
            "Interaccion detectada sin alerta activa"
        );


        return;
    }


    unsigned long tiempoRespuesta =
        (
            millis() -
            inicioAlarma
        ) / 1000;


    ultimaLatenciaSeg =
        tiempoRespuesta;


    dosisTomadas++;


    alarmaActiva =
        false;


    digitalWrite(
        PIN_LED,
        LOW
    );


    noTone(
        PIN_BUZZER
    );


    registrarEvento(
        "DOSIS_CONFIRMADA",
        tiempoRespuesta
    );


    Serial.print(
        "DOSIS CONFIRMADA - Tiempo de respuesta: "
    );


    Serial.print(
        tiempoRespuesta
    );


    Serial.println(
        " segundos"
    );
}


// ======================================================
// 12. API ESTADO
// ======================================================

void enviarEstado() {

    unsigned long pendientes =
        0;


    if (
        dosisProgramadas >
        dosisTomadas
    ) {

        pendientes =
            dosisProgramadas -
            dosisTomadas;
    }


    float cumplimiento =
        0.0;


    if (
        dosisProgramadas > 0
    ) {

        cumplimiento =
            (
                (float)dosisTomadas /
                (float)dosisProgramadas
            )
            * 100.0;
    }


    String json =
        "{";


    json +=
        "\"programadas\":" +
        String(
            dosisProgramadas
        ) +
        ",";


    json +=
        "\"tomadas\":" +
        String(
            dosisTomadas
        ) +
        ",";


    json +=
        "\"pendientes\":" +
        String(
            pendientes
        ) +
        ",";


    json +=
        "\"cumplimiento\":" +
        String(
            cumplimiento,
            1
        ) +
        ",";


    json +=
        "\"latencia\":" +
        String(
            ultimaLatenciaSeg
        ) +
        ",";


    json +=
        "\"tiempo\":" +
        String(
            millis() / 1000
        ) +
        ",";


    json +=
        "\"alarma\":" +
        String(
            alarmaActiva
            ? "true"
            : "false"
        );


    json +=
        "}";


    server.send(
        200,
        "application/json",
        json
    );
}


// ======================================================
// 13. API HISTORIAL
// ======================================================

void enviarHistorial() {

    File archivo =
        LittleFS.open(
            "/eventos.csv",
            FILE_READ
        );


    if (!archivo) {

        server.send(
            500,
            "text/plain",
            "Error al abrir historial"
        );

        return;
    }


    server.streamFile(
        archivo,
        "text/csv"
    );


    archivo.close();
}


// ======================================================
// 14. BORRAR DATOS
// ======================================================

void borrarHistorial() {

    LittleFS.remove(
        "/eventos.csv"
    );


    iniciarArchivo();


    dosisProgramadas = 0;
    dosisTomadas = 0;
    ultimaLatenciaSeg = 0;


    alarmaActiva =
        false;


    digitalWrite(
        PIN_LED,
        LOW
    );


    noTone(
        PIN_BUZZER
    );


    server.send(
        200,
        "text/plain",
        "Historial eliminado"
    );


    Serial.println(
        "Historial eliminado"
    );
}


// ======================================================
// 15. CONFIGURACIÓN
// ======================================================

void setup() {

    Serial.begin(
        115200
    );


    delay(
        500
    );


    // --------------------------------------------------
    // Pines
    // --------------------------------------------------

    pinMode(
        PIN_SENSOR,
        INPUT_PULLUP
    );


    pinMode(
        PIN_LED,
        OUTPUT
    );


    pinMode(
        PIN_BUZZER,
        OUTPUT
    );


    digitalWrite(
        PIN_LED,
        LOW
    );


    noTone(
        PIN_BUZZER
    );


    // --------------------------------------------------
    // LittleFS
    // --------------------------------------------------

    if (
        !LittleFS.begin(true)
    ) {

        Serial.println(
            "ERROR AL INICIAR LITTLEFS"
        );

    } else {

        Serial.println(
            "LittleFS iniciado correctamente"
        );


        iniciarArchivo();


        cargarEstadisticas();
    }


    // --------------------------------------------------
    // WiFi Access Point
    // --------------------------------------------------

    WiFi.mode(
        WIFI_AP
    );


    WiFi.softAP(
        WIFI_NOMBRE,
        WIFI_PASSWORD
    );


    Serial.println();

    Serial.println(
        "================================"
    );

    Serial.println(
        "PASTILLERO INTELIGENTE"
    );

    Serial.println(
        "ESP32 INICIADA"
    );

    Serial.println(
        "================================"
    );


    Serial.print(
        "Red WiFi: "
    );

    Serial.println(
        WIFI_NOMBRE
    );


    Serial.print(
        "Direccion IP: "
    );

    Serial.println(
        WiFi.softAPIP()
    );


    Serial.println(
        "Abrir en navegador:"
    );


    Serial.println(
        "http://192.168.4.1"
    );


    // --------------------------------------------------
    // Servidor
    // --------------------------------------------------

    server.on(
        "/",
        []() {

            server.send_P(
                200,
                "text/html",
                PAGINA_WEB
            );
        }
    );


    server.on(
        "/api/status",
        enviarEstado
    );


    server.on(
        "/api/historial",
        enviarHistorial
    );


    server.on(
        "/api/alerta",
        []() {

            activarAlarma();


            server.send(
                200,
                "text/plain",
                "Alerta activada"
            );
        }
    );


    server.on(
        "/api/borrar",
        borrarHistorial
    );


    server.begin();


    Serial.println(
        "Servidor web iniciado"
    );


    inicioSistema =
        millis();


    ultimaAlerta =
        millis();
}


// ======================================================
// 16. LOOP PRINCIPAL
// ======================================================

void loop() {

    // Mantener servidor web activo

    server.handleClient();


    unsigned long ahora =
        millis();


    // --------------------------------------------------
    // PRIMERA ALERTA
    // --------------------------------------------------

    if (
        dosisProgramadas == 0 &&
        !alarmaActiva &&
        ahora - inicioSistema >=
        PRIMERA_ALERTA_MS
    ) {

        activarAlarma();


        ultimaAlerta =
            ahora;
    }


    // --------------------------------------------------
    // ALERTAS SIGUIENTES
    // --------------------------------------------------

    if (
        !alarmaActiva &&
        dosisProgramadas > 0 &&
        ahora - ultimaAlerta >=
        INTERVALO_ALERTA_MS
    ) {

        activarAlarma();


        ultimaAlerta =
            ahora;
    }


    // --------------------------------------------------
    // LEER SENSOR
    // --------------------------------------------------

    bool estadoSensor =
        digitalRead(
            PIN_SENSOR
        );


    // Detectar cambio HIGH -> LOW

    if (
        estadoAnteriorSensor == HIGH &&
        estadoSensor == LOW &&
        ahora - ultimoCambioSensor >=
        DEBOUNCE_MS
    ) {

        ultimoCambioSensor =
            ahora;


        confirmarDosis();
    }


    estadoAnteriorSensor =
        estadoSensor;
}