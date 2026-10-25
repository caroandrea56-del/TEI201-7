# Librerías

## Librerías Estándar (Arduino IDE)

El programa del pastillero inteligente utiliza funciones incluidas en el entorno Arduino.

Actualmente no requiere instalar librerías externas adicionales mediante el administrador de librerías de Arduino IDE.

Las principales funciones utilizadas son:

- `pinMode()`: Configuración de pines.
- `digitalRead()`: Lectura del sensor.
- `digitalWrite()`: Control del LED.
- `tone()` y `noTone()`: Control del buzzer pasivo.
- `Serial.begin()` y `Serial.println()`: Comunicación mediante Monitor Serial.

Para compilar el programa se necesita tener instalado el soporte de placas ESP8266 en Arduino IDE.

---

## Librerías Personalizadas/Modificadas

El código actual no utiliza librerías personalizadas ni modificadas.

La programación del sensor y de las alertas se encuentra directamente en el archivo principal.

---

## Dependencias Completas

| Dependencia | Uso | Estado |
|---|---|---|
| Arduino IDE | Desarrollo y carga del programa | Utilizado |
| Soporte de placas ESP8266 | Compilación para ESP8266 NodeMCU | Necesario |
| Funciones nativas Arduino | Lectura del sensor y control de actuadores | Utilizadas |
| Librerías externas adicionales | Funcionalidades complementarias | No requeridas actualmente |

La versión exacta del soporte de ESP8266 deberá registrarse si se necesita reproducir el entorno de compilación.

---

## Futuras Dependencias

La incorporación de conectividad WiFi y comunicación con Pill Up podría requerir nuevas dependencias, las cuales se documentarán cuando se implementen.