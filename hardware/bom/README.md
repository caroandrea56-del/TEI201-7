# BOM – Lista de Materiales

## 1. Descripción

Esta sección documenta los componentes utilizados en el prototipo del pastillero inteligente.

La lista incluye los elementos electrónicos principales, su función y un costo comercial de referencia en Chile.

---

## 2. Lista de Materiales

| Cantidad | Componente | Especificación / Modelo | Función | Precio de referencia |
|---:|---|---|---|---:|
| 1 | ESP32 | ESP32-DevKitC-V4, 38 pines, USB-C | Procesamiento y conectividad WiFi | $9.246 |
| 1 | Pulsador / sensor | Pulsador blanco no retentivo | Detectar interacción del usuario | $609 |
| 1 pack | LED rojo | Pack 10 LED 5 mm | Alerta visual | $506 |
| 1 pack | Resistencia LED | 300 Ω | Limitar corriente del LED | $500 |
| 1 | Buzzer pasivo | BZ12-5, 12 mm, 3–12 VDC | Alerta sonora | $402 |
| 1 pack | Resistencia buzzer | 1 kΩ | Limitar corriente hacia base del transistor | $500 |
| 1 | Transistor | BC547 NPN, TO-92 | Accionamiento del buzzer | $290 |
| 1 | Protoboard | MB-102, 830 puntos | Montaje del circuito | $2.930 |
| 1 pack | Cables Dupont | 40 jumper macho-macho | Interconexión del circuito | $3.251 |
| 1 | Cable USB-C | USB-A a USB-C, datos y alimentación | Programación y alimentación | $1.847 |
| 1 | Encapsulado | Pieza impresa en 3D en PLA | Integración física del sistema | Fabricación propia |

---

## 3. Costo de Referencia

Considerando los componentes comerciales de la tabla, sin asignar un valor independiente al encapsulado fabricado en el proyecto, el costo de referencia es:

**$20.081 CLP**

Este valor corresponde al costo de compra de las unidades o packs comerciales indicados y no necesariamente al costo exacto de material consumido por una sola unidad del prototipo.

---

## 4. ESP32

La ESP32 constituye la unidad principal de procesamiento.

Funciones:

- Lectura del sensor.
- Control del LED.
- Control del buzzer.
- Registro de eventos.
- Procesamiento de información.
- Conectividad WiFi.
- Ejecución del servidor web.
- Visualización mediante dashboard.

La placa utilizada corresponde a una ESP32 de 38 pines con conexión USB-C.

---

## 5. Sensor / Pulsador

El pulsador se utiliza como elemento de detección de interacción.

Conexión:

- GPIO27.
- GND.

La entrada se configura mediante `INPUT_PULLUP`.

Estados:

- Sin interacción: `HIGH`.
- Pulsado: `LOW`.

---

## 6. LED Rojo

El LED constituye la alerta visual del sistema.

Conexión:

- GPIO25.
- Resistencia de 300 Ω en serie.

La resistencia limita la corriente que circula por el LED y protege la salida de la ESP32.

---

## 7. Buzzer Pasivo

El buzzer constituye la alerta sonora del sistema.

Conexión de control:

- GPIO26.
- Resistencia de 1 kΩ.
- Transistor BC547.

Al tratarse de un buzzer pasivo, requiere una señal periódica para producir sonido.

---

## 8. Transistor BC547

El transistor BC547 se utiliza como etapa de conmutación para controlar el buzzer desde la señal generada por la ESP32.

Características principales:

- Tipo: NPN.
- Encapsulado: TO-92.
- Corriente máxima de colector aproximada: 100 mA.
- Tensión colector-emisor máxima aproximada: 45 V.

La resistencia de 1 kΩ limita la corriente aplicada a la base del transistor.

---

## 9. Protoboard y Cableado

La protoboard permite desarrollar y modificar el circuito sin realizar soldaduras permanentes.

Los cables Dupont se utilizan para conectar:

- ESP32.
- Pulsador.
- LED.
- Buzzer.
- Transistor.
- Alimentación y GND.

---

## 10. Alimentación

Durante las pruebas el sistema se alimenta mediante USB-C.

El cable permite:

- Alimentar la ESP32.
- Programar el dispositivo.
- Utilizar comunicación serial durante el desarrollo.

---

## 11. Encapsulado

El encapsulado se fabrica mediante impresión 3D.

El diseño considera:

- Ocho compartimientos.
- Distribución 4 × 2.
- Integración de los componentes electrónicos.
- Acceso a la ESP32.
- Acceso al cable USB-C.
- Apertura para mantenimiento.
- Reparabilidad y sustitución de componentes.

---

## 12. Criterios de Selección

Los componentes fueron seleccionados considerando:

- Compatibilidad con ESP32.
- Disponibilidad.
- Bajo costo.
- Tamaño.
- Facilidad de montaje.
- Facilidad de reemplazo.
- Conectividad.
- Capacidad de reparación.

La utilización de ESP32 permite integrar procesamiento y conectividad WiFi sin incorporar un módulo inalámbrico independiente.

---

## 13. Fuentes de Precios

Los precios de referencia corresponden a consultas comerciales realizadas en Chile.

Principales proveedores utilizados como referencia:

- Altronics Chile.
- Pinout.cl.
- Triacs Chile.

Los precios pueden variar posteriormente según disponibilidad comercial.