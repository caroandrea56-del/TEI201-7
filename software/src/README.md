# Código Fuente

## Archivos Principales

### `main.ino`

Archivo principal del programa del pastillero inteligente, desarrollado para ESP8266 NodeMCU mediante Arduino IDE.

**Estructura:**

- `setup()`: Inicializa la configuración de los pines y la comunicación serial.
- `loop()`: Lee continuamente el estado del sensor y controla las alertas del sistema.

### Variables Principales

| Variable | Función |
|---|---|
| `pinSensor` | Define el pin GPIO4 utilizado para leer el sensor |
| `pinLed` | Define el pin GPIO14 utilizado para controlar el LED |
| `pinBuzzer` | Define el pin GPIO12 utilizado para controlar el buzzer |
| `alarmaActiva` | Almacena el estado actual de la alarma |
| `estadoAnteriorSensor` | Permite identificar una nueva activación del sensor |

El programa utiliza estas variables para controlar el comportamiento del sistema.

---

## Estándares de Código

### Comentarios

El código contiene comentarios que explican el funcionamiento de la detección del sensor, los cambios de estado de la alarma y la activación del buzzer pasivo.

### Nombres de Variables

Se utilizan nombres descriptivos, como `pinSensor`, `pinLed` y `alarmaActiva`, para facilitar la lectura y comprensión del programa.

### Organización

El programa concentra su funcionamiento en las funciones principales `setup()` y `loop()`.

En esta versión no se han separado los sensores, actuadores y comunicaciones en archivos adicionales.

---

## Testing y Debugging

### Monitor Serial

El programa utiliza una velocidad de comunicación de 115200 baudios.

**Mensajes utilizados:**

- `PASTILLERO LISTO`: Inicialización del sistema.
- `ALARMA ACTIVADA`: Activación de las alertas.
- `ALARMA APAGADA`: Desactivación de las alertas.

Estos mensajes permiten observar los cambios de estado durante las pruebas.

### Control del Sensor

El programa compara el estado actual del sensor con su estado anterior para detectar una nueva activación.

También incorpora una pausa de 250 milisegundos después de cada activación detectada.

### Control del Buzzer

El buzzer utilizado es pasivo. Por ello, el programa utiliza `tone()` para generar la alerta sonora y `noTone()` para detenerla.

---

## Estado del Desarrollo

La versión actual implementa la detección de interacción y el control del LED y buzzer.

Las funciones de programación de horarios, comunicación WiFi y conexión con la aplicación Pill Up corresponden a futuras etapas de desarrollo.