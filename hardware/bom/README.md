# BOM – Lista de materiales

## 1. Objetivo

Esta sección contiene la lista de materiales utilizados como referencia para la construcción del prototipo del pastillero inteligente.

La BOM permite identificar los principales componentes electrónicos y mecánicos del sistema, sus características técnicas, cantidades, precios de referencia y proveedores.

Los precios indicados corresponden a valores comerciales consultados en Chile para componentes equivalentes a los utilizados en el prototipo.

---

## 2. Lista de materiales

| Cantidad | Componente | Especificación | Modelo / Referencia | Proveedor | Precio unitario / pack | Precio total |
|---:|---|---|---|---|---:|---:|
| 1 | Microcontrolador | ESP32, WiFi/Bluetooth, 38 pines, 4 MB Flash | ESP32-DevkitC-V4 | Altronics | $9.246 | $9.246 |
| 1 | Microinterruptor | Microswitch SPDT para detección mecánica | VS10N00-1C2 | Altronics | $2.916 | $2.916 |
| 1 pack | LED rojo | Pack de 10 LED de 5 mm | LED-5MM-R | Altronics | $506 | $506 |
| 1 pack | Resistencias | Pack de 10 resistencias de 220 Ω, 0,25 W, 1 % | 220 Ω / 0,25 W | Altronics | $413 | $413 |
| 1 | Buzzer pasivo | Buzzer pasivo de 12 mm, rango 3–12 VDC | BZ12-5 | Altronics | $402 | $402 |
| 1 | Protoboard | Breadboard de 830 puntos | MB-102 | Altronics | $2.930 | $2.930 |
| 1 pack | Cables Dupont | 40 cables jumper macho-macho de 30 cm | Dupont 2,54 mm | Altronics | $3.251 | $3.251 |
| 1 | Cable USB | USB-A a USB-C para datos y alimentación | USBC-DCH150 | Altronics | $1.847 | $1.847 |
| 1 | Filamento PLA | PLA 1,75 mm, rollo de 1 kg | Filamento PLA 1,75 mm | Mercado Libre Chile | $12.290 | $12.290 |

### Costo total de referencia

**$33.801 CLP**

---

## 3. Detalle de componentes

### ESP32

La placa utilizada como referencia corresponde a una ESP32-DevkitC-V4 de 38 pines.

Características principales:

- Microcontrolador ESP32.
- Procesador dual core de 32 bits.
- Frecuencia máxima de 240 MHz.
- 4 MB de memoria Flash.
- Conectividad WiFi.
- Bluetooth.
- Alimentación mediante USB de 5 V.
- Interfaces UART, SPI, I2C, ADC, DAC y GPIO.

La ESP32 fue seleccionada debido a que permite integrar adquisición de datos, procesamiento y conectividad IoT en una única placa.

---

### Microinterruptor

Se utiliza un microswitch como elemento de detección mecánica.

Su función dentro del sistema es detectar la interacción del usuario con el pastillero.

Como referencia comercial se utiliza el modelo VS10N00-1C2, que dispone de:

- Contacto SPDT.
- Terminal común.
- Contacto normalmente abierto.
- Contacto normalmente cerrado.
- Activación mecánica.

La señal del microinterruptor es procesada por la ESP32 como una entrada digital.

---

### LED

El LED funciona como indicador visual del sistema.

Cuando existe una dosis pendiente, el dispositivo puede activar el LED para alertar al usuario.

Se considera un LED rojo estándar de 5 mm.

---

### Resistencia de 220 Ω

La resistencia se conecta en serie con el LED para limitar la corriente eléctrica y proteger tanto el LED como la salida de la ESP32.

Valor utilizado como referencia:

**220 Ω, 0,25 W, tolerancia 1 %.**

---

### Buzzer pasivo

El buzzer permite generar la alerta sonora del dispositivo.

El modelo de referencia BZ12-5 presenta:

- Tipo pasivo.
- Voltaje de operación entre 3 y 12 VDC.
- Frecuencia de trabajo entre 2 y 5 kHz.
- Diámetro aproximado de 12 mm.

Debido a que es un buzzer pasivo, necesita una señal con frecuencia para producir sonido.

---

### Protoboard

La protoboard permite desarrollar y probar el circuito electrónico sin necesidad de soldar los componentes.

El modelo de referencia corresponde a una breadboard MB-102 de 830 puntos.

---

### Cables Dupont

Los cables jumper permiten conectar físicamente la ESP32 con el sensor, LED, buzzer y protoboard.

Para el cálculo de costos se considera un pack de 40 cables Dupont macho-macho de 30 cm.

---

### Cable USB

El cable USB permite:

- Alimentar la ESP32.
- Programar el microcontrolador.
- Cargar el firmware desde Arduino IDE.
- Utilizar el monitor serial durante las pruebas.

Se considera como referencia un cable USB-A a USB-C compatible con transmisión de datos y alimentación.

---

### Filamento PLA

El encapsulado físico del dispositivo se fabrica mediante impresión 3D.

Como referencia de material se considera:

- PLA.
- Diámetro de 1,75 mm.
- Rollo de 1 kg.

El material permite fabricar el encapsulado, tapas y elementos estructurales diseñados para el prototipo.

---

## 4. Función de los componentes en el sistema

### ESP32

La ESP32 corresponde al núcleo del sistema.

Sus principales funciones son:

- Leer el estado del microinterruptor.
- Procesar los eventos del dispositivo.
- Activar el LED.
- Activar el buzzer.
- Gestionar la conectividad WiFi.
- Registrar información.
- Comunicarse con el sistema de visualización de datos.
- Ejecutar la lógica del pastillero inteligente.

---

### Microinterruptor

Permite detectar una interacción física con el pastillero.

Esta información puede utilizarse para registrar una apertura o confirmar una interacción asociada a una toma de medicamento.

---

### LED

Entrega una señal visual para indicar que existe una alerta activa.

---

### Buzzer

Entrega una señal sonora para llamar la atención del usuario cuando corresponde una toma.

---

### Estructura impresa en 3D

El encapsulado tiene como finalidad:

- Contener los componentes.
- Proteger las conexiones.
- Facilitar el transporte.
- Integrar físicamente el sistema electrónico con el pastillero.
- Permitir apertura y desmontaje para mantenimiento.
- Facilitar reparación o reemplazo de componentes.

---

## 5. Justificación de selección

Los componentes se seleccionaron considerando principalmente:

- Compatibilidad con la ESP32.
- Bajo costo.
- Disponibilidad comercial.
- Facilidad de programación.
- Facilidad de montaje.
- Tamaño apropiado para el prototipo.
- Posibilidad de reparación.
- Facilidad de reemplazo.
- Capacidad de conexión inalámbrica.
- Simplicidad de integración.

La ESP32 resulta especialmente adecuada debido a su conectividad WiFi integrada, lo que permite desarrollar el componente IoT del proyecto sin utilizar un módulo adicional.

El microinterruptor constituye una solución simple y robusta para detectar una interacción física.

El uso combinado de LED y buzzer permite entregar alertas mediante dos canales diferentes: visual y auditivo.

---

## 6. Costos

El costo comercial de referencia del conjunto de materiales es:

**$33.801 CLP**

Este valor considera la compra de unidades o packs comerciales completos y no solamente la fracción de material efectivamente consumida durante la fabricación.

Por esta razón, el costo real de material utilizado directamente en una sola unidad del prototipo puede ser inferior.

---

## 7. Fuentes comerciales

Los valores de referencia utilizados en esta BOM fueron consultados en proveedores disponibles en Chile:

- Altronics Chile.
- Mercado Libre Chile.

Los precios corresponden a valores comerciales consultados durante el desarrollo de la entrega y pueden variar posteriormente según disponibilidad o proveedor.