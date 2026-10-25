# Pastillero Inteligente

Sistema IoT para apoyar la correcta administración de medicamentos mediante alertas visuales y sonoras, detección de interacción con el dispositivo y organización de dosis en compartimientos independientes.

El proyecto busca disminuir olvidos, confusiones de horario y dificultades en el seguimiento de tratamientos farmacológicos diarios.

---

## Equipo

| Integrante | Rol | GitHub |
|---|---|---|
| Greta Ferrer | Diseño 3D e integración | @usuario |
| Carolina Gallardo | Hardware | @usuario |
| Martina Penschke | Software / Firmware | @usuario |
| Estela Pérez | Testing e iteración | @usuario |

---

## Descripción del problema

Las personas que siguen tratamientos farmacológicos diarios pueden olvidar la hora de tomar sus medicamentos, confundirse respecto de las dosis o no tener claridad sobre si una dosis ya fue tomada.

Esto puede generar interrupciones en el tratamiento y aumentar la necesidad de supervisión por parte de familiares o cuidadores.

Nuestro proyecto se relaciona con el **ODS 3: Salud y Bienestar**, ya que busca facilitar el seguimiento y organización de la toma diaria de medicamentos.

---

## Arquitectura del sistema

Sensor / microinterruptor → ESP8266 → procesamiento de la señal → LED + buzzer → interacción del usuario

El sistema funciona actualmente de la siguiente manera:

1. El sensor detecta una interacción.
2. La ESP8266 recibe y procesa la señal.
3. Se enciende un LED como alerta visual.
4. Se activa un buzzer como alerta sonora.
5. Una nueva interacción permite apagar la alerta.

### Conexiones actuales

- Sensor → D2 / GPIO4
- LED → D5 / GPIO14
- Buzzer → D6 / GPIO12
- Todos los componentes comparten GND.

---

## Instrucciones de uso

### Cargar el firmware

1. Abrir el proyecto en **Arduino IDE**.
2. Conectar la ESP8266 al computador mediante USB.
3. Seleccionar la placa ESP8266 correspondiente.
4. Seleccionar el puerto correcto.
5. Abrir el archivo `.ino` del proyecto.
6. Compilar el programa.
7. Cargar el código en la ESP8266.

### Probar el sistema

1. Conectar el sensor, LED y buzzer según las conexiones indicadas.
2. Alimentar la ESP8266 mediante USB.
3. Activar el sensor.
4. Verificar que el LED se encienda.
5. Verificar que el buzzer emita sonido.
6. Activar nuevamente el sensor para apagar la alerta.

---

## Prototipo físico

El prototipo actual corresponde a un pastillero rectangular de:

- 10 cm de ancho.
- 8 cm de fondo.
- 3 cm de alto.
- 8 compartimientos independientes.
- Distribución de 4 x 2.
- Tapas individuales.
- Bisagras ubicadas sobre una línea central.
- Diseño compacto y portátil.

El modelo fue desarrollado mediante **OpenSCAD** y preparado para fabricación mediante impresión 3D.

---

## Proceso de iteración

El primer prototipo tenía una forma circular y utilizaba un mecanismo más complejo.

Al imprimirlo, detectamos que:

- el tamaño era mayor de lo esperado;
- no cumplía con nuestras expectativas de portabilidad;
- el mecanismo era más complejo de lo necesario.

A partir de esa prueba realizamos distintas iteraciones:

- cambio de diseño circular a rectangular;
- simplificación del mecanismo;
- reducción de la altura;
- incorporación de 8 compartimientos;
- modificación del sistema de apertura;
- ubicación de las bisagras en una línea central;
- corrección de los ejes de giro;
- separación de las piezas para facilitar la impresión 3D;
- integración progresiva del sensor, LED y buzzer.

---

## Testing y Debugging

El sistema fue probado de manera incremental.

Se realizaron pruebas de:

- funcionamiento del sensor;
- encendido y apagado del LED;
- funcionamiento del buzzer;
- interacción entre sensor y actuadores;
- dimensiones del prototipo;
- apertura de las tapas;
- diseño de bisagras;
- impresión 3D de las piezas.

Uno de los principales aprendizajes fue que el buzzer utilizado es pasivo, por lo que fue necesario utilizar `tone()` para generar el sonido correctamente.

También se realizaron distintas pruebas del diseño 3D hasta conseguir que las tapas se abrieran correctamente desde la línea central.

---

## Estructura del repositorio

- `diseno-3d/` — Archivos OpenSCAD, STL, renders y modelos del pastillero.
- `docs/` — Presentaciones y documentación del proyecto.
- `hardware/` — Circuito, conexiones y componentes electrónicos.
- `iteraciones/` — Evidencia del desarrollo y evolución del prototipo.
- `software/` — Código fuente para la ESP8266.
- `testing/` — Pruebas realizadas, errores encontrados y soluciones.
- `FUENTES.md` — Bibliografía, referencias y fuentes utilizadas.

---

## Tecnologías utilizadas

- ESP8266 NodeMCU
- Arduino IDE
- C++ / Arduino
- OpenSCAD
- Impresión 3D
- GitHub
- GitHub Desktop

---

## Componentes utilizados

- ESP8266 NodeMCU
- Sensor / microinterruptor
- LED
- Resistencia
- Buzzer pasivo
- Protoboard
- Cables Dupont
- Cable USB

---

## Próximos pasos

- Integrar completamente la electrónica dentro del encapsulado.
- Incorporar programación de horarios.
- Mejorar el sistema de alertas.
- Incorporar conectividad mediante WiFi.
- Realizar pruebas con usuarios.
- Evaluar facilidad de uso, portabilidad y confiabilidad.
- Continuar mejorando el diseño físico del pastillero.