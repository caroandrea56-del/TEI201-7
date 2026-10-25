# Documentación de Software

## Contenido

Esta carpeta reúne la documentación técnica del software utilizado en el pastillero inteligente. El sistema está desarrollado en Arduino IDE y utiliza una ESP8266 NodeMCU para procesar la señal de un sensor y controlar las alertas visuales y sonoras.

### Diagramas de Flujo

El funcionamiento del programa sigue la siguiente secuencia:

1. Se inicia la ESP8266 y se configuran los pines.
2. El sistema permanece leyendo el estado del sensor.
3. Cuando se detecta una activación, cambia el estado de la alarma.
4. Si la alarma se activa, se enciende el LED y comienza a sonar el buzzer.
5. Ante una nueva activación del sensor, el LED y el buzzer se apagan.
6. El programa continúa ejecutándose y queda disponible para una nueva interacción.

Este funcionamiento está implementado en el archivo principal de Arduino.

### Documentación de Funciones

#### Funciones Principales

**`setup()`**

- **Propósito:** Inicializar la configuración del sistema.
- **Parámetros:** No recibe parámetros.
- **Retorna:** No retorna valores.
- **Funcionamiento:** Configura los pines, establece el estado inicial del LED e inicia la comunicación serial a 115200 baudios.

**`loop()`**

- **Propósito:** Ejecutar continuamente la lógica de funcionamiento del pastillero.
- **Parámetros:** No recibe parámetros.
- **Retorna:** No retorna valores.
- **Funcionamiento:** Lee el sensor, detecta las interacciones y controla el encendido y apagado de la alarma.

**Funciones utilizadas dentro del programa:**

| Función | Uso |
|---|---|
| `pinMode()` | Configura los pines de entrada y salida |
| `digitalRead()` | Lee el estado del sensor |
| `digitalWrite()` | Controla el encendido y apagado del LED |
| `tone()` | Genera la señal sonora del buzzer pasivo |
| `noTone()` | Detiene la señal sonora |
| `Serial.println()` | Muestra mensajes del estado del sistema |
| `delay()` | Introduce una pausa breve después de detectar una interacción |

---

## Manual de Instalación

### Configuración de Arduino IDE

1. Instalar Arduino IDE en el computador.
2. Instalar el soporte para placas ESP8266.
3. Conectar la ESP8266 NodeMCU mediante USB.
4. Seleccionar la placa y el puerto correspondiente.
5. Abrir el archivo principal `.ino` del proyecto.
6. Verificar que el programa compile correctamente.
7. Cargar el código a la placa.
8. Abrir el Monitor Serial a 115200 baudios para observar los mensajes del sistema.

### Conexiones Utilizadas

| Componente | Pin ESP8266 |
|---|---|
| Sensor / microinterruptor | D2 / GPIO4 |
| LED | D5 / GPIO14 |
| Buzzer pasivo | D6 / GPIO12 |
| Tierra común | GND |

El sensor utiliza la configuración `INPUT_PULLUP`. El LED incorpora una resistencia para limitar la corriente.

---

## Manual de Operación

### Encendido del Sistema

1. Conectar la ESP8266 a una fuente de alimentación USB adecuada.
2. Comprobar que las conexiones del sensor, LED y buzzer estén correctamente instaladas.
3. Al iniciar, el programa configura los componentes y muestra el mensaje `PASTILLERO LISTO` en el Monitor Serial.

### Operación Normal

1. El sistema permanece a la espera de una interacción con el sensor.
2. Cuando el usuario activa el sensor, la ESP8266 detecta el cambio de estado.
3. Se enciende el LED y se activa el buzzer.
4. Una segunda interacción desactiva ambas alertas.
5. El sistema vuelve a quedar disponible para una nueva activación.

### Apagado del Sistema

Para detener completamente el sistema, se desconecta la alimentación USB de la ESP8266.

---

## Troubleshooting

### Problemas Comunes

| Problema | Posible causa | Solución o procedimiento de revisión |
|---|---|---|
| El código no se carga a la placa | Puerto o modelo de placa incorrecto | Verificar la configuración de Arduino IDE y la conexión USB |
| El sensor no responde | Cableado incorrecto o configuración del pin | Revisar la conexión a GPIO4 y la configuración `INPUT_PULLUP` |
| El LED no enciende | Polaridad incorrecta, resistencia o conexión equivocada | Revisar la conexión a GPIO14 y la polaridad del LED |
| El buzzer no emite sonido | Uso de un buzzer pasivo sin señal de frecuencia | Utilizar `tone()` para generar el sonido |
| La alarma no se desactiva | No se detecta correctamente la segunda interacción | Revisar el estado anterior del sensor y la lógica del programa |
| No aparecen mensajes en el Monitor Serial | Velocidad de comunicación incorrecta | Configurar el Monitor Serial a 115200 baudios |
| El dispositivo no se comunica con Pill Up | La comunicación entre la aplicación y el hardware aún no está implementada | Desarrollar y validar un mecanismo de comunicación compatible |

### Conectividad

La ESP8266 NodeMCU cuenta con conectividad WiFi, pero no dispone de Bluetooth integrado.

Actualmente, el código se centra en la lectura del sensor y el control de las alertas. La comunicación inalámbrica con Pill Up todavía no está implementada.

Para integrar ambos sistemas será necesario definir el mecanismo de comunicación, considerando las capacidades de la placa utilizada.

---

## Mejoras Futuras

- Incorporar horarios programados para las alertas.
- Implementar comunicación entre el pastillero y Pill Up.
- Registrar eventos de interacción con el dispositivo.
- Incorporar un mecanismo de seguimiento de dosis.
- Realizar pruebas de funcionamiento del sistema integrado.