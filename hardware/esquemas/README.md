# Esquemas del Circuito

## 1. Descripción

Esta carpeta contiene la documentación correspondiente al circuito electrónico del pastillero inteligente.

El sistema utiliza una **ESP32** como unidad principal de procesamiento y conectividad.

El circuito integra:

- Pulsador o sensor de interacción.
- LED rojo.
- Buzzer pasivo.
- Transistor BC547.
- Resistencias.
- Protoboard.
- Alimentación mediante USB-C.

---

## 2. Conexiones Definitivas

| Componente | Pin ESP32 | Conexión |
|---|---:|---|
| LED rojo | GPIO25 | Resistencia de 300 Ω en serie |
| Pulsador / sensor | GPIO27 | Segundo terminal conectado a GND |
| Buzzer pasivo | GPIO26 | Control mediante resistencia de 1 kΩ y transistor BC547 |
| Tierra | GND | Tierra común |
| Alimentación | USB-C | Alimentación y programación |

---

## 3. Sensor / Pulsador

El pulsador permite detectar la interacción física del usuario con el pastillero.

La conexión utilizada es:

`GPIO27 → pulsador → GND`

El GPIO27 se configura mediante:

`INPUT_PULLUP`

Por lo tanto:

- Sin pulsar: `HIGH`.
- Pulsado: `LOW`.

Esta configuración utiliza la resistencia pull-up interna de la ESP32 y simplifica el circuito.

---

## 4. LED

El LED rojo funciona como alerta visual.

La señal de control proviene de:

`GPIO25`

El LED incorpora una resistencia de **300 Ω** en serie.

Flujo simplificado:

`GPIO25 → resistencia 300 Ω → LED → GND`

Cuando GPIO25 se encuentra en estado `HIGH`, el LED se enciende.

---

## 5. Buzzer Pasivo

El buzzer funciona como alerta sonora.

La señal de control se genera desde:

`GPIO26`

La salida controla el buzzer mediante una etapa formada por:

- Resistencia de 1 kΩ.
- Transistor NPN BC547.
- Buzzer pasivo.

Flujo de control:

`GPIO26 → resistencia 1 kΩ → base BC547`

El transistor controla el paso de corriente hacia el buzzer.

Esta configuración evita utilizar directamente el GPIO de la ESP32 como fuente de corriente para el actuador.

---

## 6. Transistor BC547

El BC547 funciona como elemento de conmutación.

Conexión funcional:

- Base: recibe la señal desde GPIO26 mediante resistencia de 1 kΩ.
- Emisor: conectado a GND.
- Colector: conectado al circuito del buzzer.

Todos los elementos utilizan una referencia GND común.

---

## 7. Tierra Común

Los siguientes elementos comparten la misma conexión a tierra:

- ESP32.
- Pulsador.
- LED.
- Transistor.
- Buzzer.

Mantener GND común es necesario para asegurar referencias eléctricas correctas entre sensores, actuadores y microcontrolador.

---

## 8. Alimentación

Durante las pruebas, la ESP32 se alimenta mediante USB-C.

El cable USB permite simultáneamente:

- Alimentar la placa.
- Programar el firmware.
- Utilizar el Monitor Serial.

---

## 9. Flujo del Sistema

El flujo electrónico de alerta es:

ESP32  
↓  
GPIO25 → LED  
↓  
GPIO26 → resistencia 1 kΩ → BC547 → buzzer

El flujo de interacción es:

Usuario  
↓  
Pulsador / sensor  
↓  
GPIO27  
↓  
ESP32  
↓  
Procesamiento del evento  
↓  
Registro de interacción  
↓  
Desactivación de la alerta

---

## 10. Función de la ESP32

La ESP32 se encarga de:

- Leer el pulsador.
- Detectar cambios de estado.
- Controlar el LED.
- Controlar la señal del buzzer.
- Procesar eventos.
- Registrar información.
- Gestionar conectividad WiFi.
- Ejecutar el servidor web.
- Actualizar el dashboard.

---

## 11. Montaje

El montaje se realiza sobre protoboard para permitir modificaciones y reparación durante el desarrollo.

La distribución debe mantener:

- Conexiones cortas y ordenadas.
- GND común.
- Separación entre alimentación y señales.
- Acceso a la ESP32.
- Acceso al pulsador.
- Acceso al buzzer y transistor.

---

## 12. Reparabilidad

El circuito se integra dentro de un encapsulado que puede abrirse sin destruirse.

Esto permite:

- Revisar conexiones.
- Sustituir la ESP32.
- Sustituir el pulsador.
- Cambiar el LED.
- Sustituir el transistor.
- Sustituir el buzzer.
- Revisar el cableado.

---

## 13. Archivos del Esquema

Esta carpeta debe conservar la documentación gráfica utilizada para representar el circuito.

Nombres utilizados:

`esquema_circuito.png`

`circuito_completo.fzz`

También puede conservarse una fotografía del montaje real:

`montaje_real.jpg`

---

## 14. Nomenclatura

Para documentar versiones anteriores del esquema pueden utilizarse nombres como:

`v1_esquema_inicial.png`

`v2_esquema_pruebas.png`

`v3_esquema_final.png`

La versión presentada como definitiva debe coincidir con las conexiones utilizadas físicamente en el prototipo.

---

## 15. Configuración Final del Circuito

La configuración documentada para el sistema es:

- ESP32.
- LED rojo en GPIO25.
- Resistencia de LED de 300 Ω.
- Pulsador en GPIO27.
- Buzzer pasivo controlado desde GPIO26.
- Resistencia de base de 1 kΩ.
- Transistor BC547.
- GND común.
- Alimentación USB-C.

Esta configuración corresponde a la utilizada para documentar el firmware y el montaje electrónico de la entrega.