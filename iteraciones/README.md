# Iteración 3 — Desarrollo e Integración Electrónica

## Información General

**Versión:** Etapa de integración del prototipo  
**Estado:** En desarrollo  
**Avance asociado:** Prototipo Alpha IoT

---

## Descripción

Esta etapa se enfoca en incorporar el funcionamiento electrónico al pastillero inteligente, complementando el diseño físico desarrollado en las iteraciones anteriores.

El objetivo es implementar un sistema capaz de detectar interacciones mediante un sensor y generar alertas visuales y sonoras para apoyar la organización de medicamentos.

---

## Componentes Electrónicos

### Hardware

El sistema utiliza los siguientes componentes:

- ESP8266 NodeMCU.
- Sensor o microinterruptor.
- LED.
- Buzzer pasivo.
- Resistencia para el LED.
- Protoboard.
- Cables Dupont.
- Alimentación mediante USB.

### Conexiones

| Componente | Pin ESP8266 | Función |
|---|---|---|
| Sensor | D2 / GPIO4 | Detectar interacción |
| LED | D5 / GPIO14 | Alerta visual |
| Buzzer | D6 / GPIO12 | Alerta sonora |
| GND | GND | Tierra común |

---

## Desarrollo del Software

El código fue desarrollado mediante Arduino IDE para controlar el funcionamiento del sensor y los actuadores.

### Funcionalidades Implementadas en el Código

1. Lectura del sensor mediante `digitalRead()`.
2. Detección de una nueva interacción.
3. Activación del LED.
4. Activación del buzzer mediante `tone()`.
5. Desactivación de las alertas ante una segunda interacción.
6. Visualización del estado del sistema mediante el Monitor Serial.

El código fuente se encuentra disponible en la carpeta [`../../software/src/`](../../software/src/).

---

## Pruebas y Modificaciones

### Prueba del LED

Se cuenta con evidencia fotográfica de un LED encendido durante el desarrollo electrónico del prototipo.

Las fotografías se encuentran disponibles en [`../../hardware/fotos/`](../../hardware/fotos/).

### Funcionamiento del Buzzer

Durante el desarrollo se identificó que el buzzer utilizado es pasivo y requiere una señal de frecuencia para generar sonido.

Por esta razón, se incorporó la función `tone()` para activar la alerta sonora y `noTone()` para detenerla.

### Integración del Sistema

El código contempla el funcionamiento conjunto del sensor, LED y buzzer.

La validación física del sistema integrado y su funcionamiento continuo requieren evidencia adicional.

---

## Integración con la Aplicación Pill Up

Como complemento del prototipo se está desarrollando Pill Up, una aplicación móvil en Flutter para organizar medicamentos y sus horarios.

La comunicación entre la aplicación y la ESP8266 todavía no se encuentra implementada.

La placa dispone de conectividad WiFi, que podrá considerarse para futuras etapas de integración.

---

## Mejoras Pendientes

- Integrar los componentes electrónicos dentro del encapsulado.
- Implementar alertas asociadas a horarios de medicamentos.
- Desarrollar la comunicación con Pill Up.
- Registrar las interacciones del usuario.
- Realizar pruebas de funcionamiento continuo.
- Evaluar la facilidad de uso del dispositivo.

---

## Evidencias y Documentación

La documentación del sistema se encuentra disponible en las siguientes carpetas:

- [`../../hardware/`](../../hardware/): componentes, conexiones y fotografías.
- [`../../software/`](../../software/): código y funcionamiento del programa.
- [`../../testing/`](../../testing/): pruebas y errores documentados.
- [`../../diseno_3d/`](../../diseno_3d/): archivos del encapsulado.

Esta etapa continúa en desarrollo y permitirá incorporar nuevas mejoras hasta completar el funcionamiento del pastillero inteligente.