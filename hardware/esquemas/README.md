# Esquemas del Circuito

## 1. Descripción

Esta carpeta contiene la documentación correspondiente al circuito electrónico del pastillero inteligente.

El sistema utiliza una **ESP32** como unidad principal de procesamiento y conectividad, junto con un sensor o microinterruptor, un LED y un buzzer pasivo.

El circuito permite detectar la interacción del usuario con el pastillero y generar alertas visuales y sonoras asociadas a la toma de medicamentos.

---

## 2. Archivos del esquema

Los archivos correspondientes al circuito deberán almacenarse en esta carpeta.

### Fritzing

Archivos recomendados:

- `circuito_completo.fzz` — archivo editable del circuito.
- `esquema_circuito.png` — imagen del montaje electrónico.
- `esquematico_final.png` — esquema eléctrico final.

### Wokwi

Si se utiliza Wokwi para complementar la documentación:

- `wokwi_diagram.json`
- `wokwi_screenshot.png`
- `wokwi_link.txt`

---

## 3. Componentes del circuito

El prototipo está compuesto por:

- ESP32.
- Sensor o microinterruptor.
- LED indicador.
- Resistencia limitadora para LED.
- Buzzer pasivo.
- Protoboard.
- Cables Dupont.
- Cable USB de alimentación y programación.

Todos los elementos electrónicos comparten una tierra común (**GND**).

---

## 4. Conexiones generales

| Componente | Conexión ESP32 | Función |
|---|---|---|
| Sensor / microinterruptor | GPIO digital | Detectar apertura o interacción con el pastillero |
| LED | GPIO de salida | Alerta visual |
| Buzzer pasivo | GPIO de salida PWM | Alerta sonora |
| Sensor | GND | Referencia eléctrica |
| LED | GND mediante circuito correspondiente | Retorno eléctrico |
| Buzzer | GND | Retorno eléctrico |
| ESP32 | USB / 5 V | Alimentación y programación |

**Nota:** la numeración definitiva de los GPIO se actualizará después de comprobar físicamente las conexiones realizadas en la ESP32.

No se fija en esta documentación una numeración de GPIO sin verificarla directamente en el montaje final.

---

## 5. Sensor / microinterruptor

El microinterruptor funciona como entrada digital del sistema.

Su objetivo es detectar una interacción física del usuario con el pastillero.

La configuración prevista utiliza la resistencia interna de la ESP32 mediante:

`INPUT_PULLUP`

En esta configuración:

- Estado normal del sensor: `HIGH`.
- Sensor activado: `LOW`.

Esto permite reducir la cantidad de componentes externos necesarios para la lectura digital.

---

## 6. LED de alerta

El LED funciona como indicador visual.

Cuando el sistema detecta una condición de alerta asociada a una dosis pendiente, la ESP32 activa el LED.

El LED se conecta mediante una resistencia limitadora de corriente.

Para el prototipo se considera una resistencia de:

**220 Ω**

La resistencia protege tanto el LED como la salida digital utilizada.

---

## 7. Buzzer pasivo

El buzzer entrega la alerta sonora del sistema.

El componente utilizado corresponde a un **buzzer pasivo**, por lo que no basta únicamente con mantener una salida digital en nivel alto.

Debe utilizarse una señal periódica o PWM con una frecuencia adecuada para generar sonido.

La ESP32 genera esta señal mediante una de sus salidas compatibles.

Cuando la dosis es confirmada, la señal sonora se detiene.

---

## 8. ESP32

La ESP32 corresponde al controlador principal del dispositivo.

Sus funciones dentro del prototipo son:

- Leer el estado del sensor.
- Procesar la interacción del usuario.
- Activar el LED.
- Controlar el buzzer.
- Gestionar las alertas.
- Registrar eventos.
- Procesar información de cumplimiento.
- Establecer comunicación mediante WiFi.
- Permitir la conexión con el sistema de visualización de datos.

La conectividad WiFi integrada evita la necesidad de incorporar un módulo inalámbrico independiente.

---

## 9. Flujo electrónico del sistema

El funcionamiento general del circuito corresponde a:

Sensor / microinterruptor  
↓  
ESP32  
↓  
Procesamiento del evento  
↓  
Registro de información  
↓  
LED + buzzer  
↓  
Alerta al usuario

Cuando existe una alerta y el usuario interactúa con el pastillero:

Alerta activa  
↓  
Usuario abre o interactúa con el pastillero  
↓  
Microinterruptor cambia de estado  
↓  
ESP32 detecta el evento  
↓  
Se registra la interacción  
↓  
LED y buzzer se desactivan  
↓  
El sistema actualiza el estado de la dosis

---

## 10. Alimentación

Durante el desarrollo y las pruebas, la ESP32 se alimenta mediante conexión USB.

La alimentación USB permite simultáneamente:

- Energizar el microcontrolador.
- Programar el firmware.
- Visualizar información mediante el monitor serial.
- Realizar pruebas del sistema.

Los sensores y actuadores deben conectarse respetando los niveles eléctricos compatibles con la ESP32.

---

## 11. Tierra común

Todos los componentes deben compartir una conexión común a GND.

Esto incluye:

- ESP32.
- Sensor.
- LED.
- Buzzer.

La utilización de una referencia de tierra común es necesaria para asegurar una lectura y activación correcta de los elementos electrónicos.

---

## 12. Consideraciones de montaje

Durante el armado del circuito se debe verificar:

- Polaridad correcta del LED.
- Valor correcto de la resistencia.
- Conexión correcta del sensor.
- Conexión correcta del buzzer.
- Continuidad de GND.
- Ausencia de cables sueltos.
- Ausencia de cortocircuitos.
- Correcta alimentación de la ESP32.
- Correspondencia entre los GPIO utilizados físicamente y los definidos en el firmware.

---

## 13. Integración con el encapsulado

El circuito electrónico debe integrarse dentro del encapsulado diseñado para el pastillero.

El diseño debe permitir:

- Acceso a la ESP32.
- Acceso al cable USB.
- Acceso al buzzer.
- Reemplazo del sensor.
- Revisión de las conexiones.
- Apertura del dispositivo sin destruir el encapsulado.
- Reparación y mantenimiento de los componentes.

El sistema electrónico no debe quedar sellado permanentemente dentro de la estructura.

---

## 14. Documentación gráfica requerida

La versión final deberá incluir al menos:

1. Esquema completo del circuito.
2. Imagen del montaje real.
3. Identificación de la ESP32.
4. Identificación del sensor.
5. Identificación del LED.
6. Identificación del buzzer.
7. Identificación de alimentación y GND.
8. GPIO definitivo de cada componente.

---

## 15. Nomenclatura de archivos

Para mantener un registro ordenado de las iteraciones se utilizarán nombres descriptivos.

Ejemplos:

`v1_esquema_inicial.png`

`v2_esquema_pruebas.png`

`v3_esquema_final.png`

También puede utilizarse fecha en formato:

`YYYYMMDD_descripcion`

Ejemplo:

`20261122_esquema_pastillero_final.png`

---

## 16. Estado actual

La arquitectura electrónica general del prototipo está definida utilizando una ESP32 como unidad principal.

Se ha definido la integración de:

- Sensor o microinterruptor.
- LED.
- Buzzer pasivo.
- ESP32.
- Alimentación USB.

Antes de cerrar la documentación final se debe verificar físicamente la numeración exacta de los GPIO utilizados en el prototipo.

Una vez confirmados esos GPIO, deberán incorporarse tanto en este documento como en el archivo principal de firmware.