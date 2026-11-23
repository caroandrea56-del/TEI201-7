# Iteración 3 — Desarrollo e Integración Electrónica

## Información General

**Versión:** Etapa de integración del prototipo  
**Estado:** En desarrollo  
**Avance asociado:** Prototipo IoT final

---

## 1. Descripción

Esta iteración corresponde a la integración del sistema electrónico con el pastillero inteligente.

El objetivo de esta etapa es transformar el prototipo físico en un sistema funcional capaz de:

- Detectar interacciones mediante un sensor.
- Generar alertas visuales.
- Generar alertas sonoras.
- Registrar eventos.
- Procesar información relacionada con la toma de medicamentos.
- Incorporar conectividad WiFi.
- Visualizar información mediante un dashboard.

Esta etapa representa la transición desde un prototipo físico hacia un dispositivo IoT funcional.

---

## 2. Componentes Electrónicos

### Hardware utilizado

El sistema utiliza los siguientes componentes:

- ESP32.
- Sensor o microinterruptor.
- LED.
- Buzzer pasivo.
- Resistencia de 220 Ω para el LED.
- Protoboard.
- Cables Dupont.
- Alimentación mediante USB.

---

## 3. Microcontrolador

La unidad principal del sistema corresponde a una ESP32.

La ESP32 fue seleccionada debido a que permite integrar en una sola placa:

- Procesamiento.
- Entradas y salidas digitales.
- Conectividad WiFi.
- Comunicación con sistemas externos.
- Registro y procesamiento de eventos.

Su conectividad permite desarrollar el componente IoT del pastillero sin utilizar un módulo WiFi independiente.

---

## 4. Conexiones

Las conexiones definitivas de GPIO serán documentadas una vez verificadas directamente en el prototipo físico.

La arquitectura general corresponde a:

| Componente | Conexión ESP32 | Función |
|---|---|---|
| Sensor / microinterruptor | GPIO digital | Detectar interacción |
| LED | GPIO de salida | Alerta visual |
| Buzzer pasivo | GPIO de salida compatible | Alerta sonora |
| GND | GND | Tierra común |
| ESP32 | USB | Alimentación y programación |

Todos los elementos comparten una referencia de tierra común.

---

## 5. Desarrollo del Firmware

El firmware se desarrolla utilizando Arduino IDE y lenguaje C/C++.

El código fuente principal se encuentra en:

`../../firmware/src/main.ino`

La estructura del firmware permite controlar el sensor, los actuadores y la conectividad del sistema.

---

## 6. Funcionalidades del Firmware

El firmware contempla las siguientes funciones:

1. Lectura del sensor.
2. Detección de interacción del usuario.
3. Activación del LED.
4. Activación del buzzer pasivo.
5. Desactivación de alertas.
6. Registro de eventos.
7. Procesamiento del estado de una dosis.
8. Registro de dosis programadas.
9. Registro de dosis confirmadas.
10. Registro de dosis pendientes.
11. Cálculo de porcentaje de cumplimiento.
12. Registro del tiempo de respuesta.
13. Comunicación mediante WiFi.
14. Visualización de información mediante dashboard.

---

## 7. Funcionamiento del Sensor

El microinterruptor funciona como entrada digital.

El sistema detecta una interacción cuando el sensor cambia de estado.

La configuración prevista utiliza:

`INPUT_PULLUP`

De esta forma:

- Estado normal: HIGH.
- Sensor activado: LOW.

La interacción puede utilizarse para registrar la apertura o manipulación del pastillero.

---

## 8. Funcionamiento del LED

El LED funciona como alerta visual.

Cuando existe una dosis pendiente, el sistema activa el LED.

Una vez confirmada la interacción correspondiente, el LED se apaga.

Durante el desarrollo se realizaron pruebas de funcionamiento y se obtuvo evidencia fotográfica del LED encendido.

La evidencia se encuentra en:

`../../hardware/fotos/`

---

## 9. Funcionamiento del Buzzer

El buzzer utilizado corresponde a un buzzer pasivo.

Durante las primeras pruebas se observó que el componente no generaba sonido utilizando solamente una señal digital fija.

A partir de esta prueba se identificó que el buzzer necesita recibir una señal de frecuencia.

Esta modificación permitió activar correctamente la alerta sonora.

El buzzer se utiliza junto con el LED para generar una alerta combinada visual y auditiva.

---

## 10. Evolución de la Lógica del Sistema

En las primeras pruebas, la interacción con el sensor activaba y desactivaba directamente las alertas.

Esta lógica fue modificada para representar mejor el funcionamiento real del pastillero.

La lógica propuesta actualmente es:

1. El sistema genera una alerta asociada a una dosis.
2. Se activa el LED.
3. Se activa el buzzer.
4. El usuario interactúa con el pastillero.
5. El sensor detecta la interacción.
6. La ESP32 procesa el evento.
7. La dosis se registra como confirmada.
8. El LED se apaga.
9. El buzzer se desactiva.
10. El sistema actualiza la información registrada.

---

## 11. Registro de Datos

El sistema está siendo desarrollado para registrar eventos generados durante el funcionamiento.

Entre los datos considerados se encuentran:

- Activación de una alerta.
- Interacción con el sensor.
- Dosis programada.
- Dosis confirmada.
- Dosis pendiente.
- Tiempo de respuesta.
- Historial de eventos.

El objetivo es mantener información que posteriormente pueda ser visualizada y analizada.

---

## 12. Dashboard

El sistema incorpora una interfaz de visualización para presentar la información generada por el dispositivo.

El dashboard considera indicadores como:

- Dosis programadas.
- Dosis tomadas.
- Dosis pendientes.
- Porcentaje de cumplimiento.
- Estado de la alarma.
- Tiempo de respuesta.
- Historial de eventos.

El objetivo del dashboard es transformar los datos registrados por el dispositivo en información comprensible para el usuario.

---

## 13. Integración IoT

La ESP32 permite incorporar conectividad WiFi al prototipo.

El flujo general del sistema corresponde a:

Sensor  
↓  
ESP32  
↓  
Procesamiento  
↓  
Registro de datos  
↓  
Generación de indicadores  
↓  
Dashboard  
↓  
Información para el usuario

De esta forma, el dispositivo evoluciona desde una alarma electrónica básica hacia un sistema IoT capaz de registrar y visualizar información.

---

## 14. Integración con Pill Up

Como complemento del dispositivo físico se ha considerado el desarrollo de Pill Up, una aplicación destinada a apoyar la organización de medicamentos y horarios.

La integración directa entre Pill Up y la ESP32 no constituye actualmente la función principal del prototipo.

La prioridad de esta iteración corresponde a completar el ciclo funcional:

**captura de datos → registro → procesamiento → visualización**

La aplicación puede considerarse como una futura extensión del sistema.

---

## 15. Pruebas Realizadas

Hasta el momento se han realizado pruebas relacionadas con:

- Lectura del sensor.
- Activación del LED.
- Activación del buzzer.
- Funcionamiento conjunto de los actuadores.
- Respuesta frente a la interacción del usuario.

También se identificó y solucionó el problema asociado al funcionamiento del buzzer pasivo.

---

## 16. Pruebas Pendientes

Para la validación final se deberán realizar pruebas de:

- Precisión de detección del sensor.
- Funcionamiento repetido del LED.
- Funcionamiento repetido del buzzer.
- Tiempo de respuesta.
- Registro de eventos.
- Persistencia de información.
- Funcionamiento del dashboard.
- Operación continua.
- Integración con el encapsulado.

Los protocolos correspondientes se encuentran documentados en:

`../../testing/`

---

## 17. Integración con el Encapsulado

La electrónica debe integrarse físicamente dentro del encapsulado diseñado.

El diseño debe permitir:

- Acceso a la ESP32.
- Revisión de conexiones.
- Acceso al sensor.
- Acceso al buzzer.
- Acceso al cable USB.
- Reparación.
- Reemplazo de componentes.
- Apertura sin destruir el dispositivo.

La estructura física debe permitir mantener y reparar el sistema electrónico.

---

## 18. Evidencias

La documentación del proyecto se distribuye en las siguientes carpetas:

- `../../hardware/` — componentes, esquemas y fotografías.
- `../../firmware/` — código del sistema.
- `../../testing/` — protocolos y resultados de pruebas.
- `../../diseno_3d/` — archivos del encapsulado y modelo 3D.
- `../../docs/` — documentación general del proyecto.

---

## 19. Mejoras Pendientes

Las principales tareas pendientes son:

- Confirmar los GPIO definitivos de la ESP32.
- Finalizar el firmware.
- Completar la integración del dashboard.
- Ejecutar pruebas cuantitativas.
- Integrar completamente la electrónica dentro del encapsulado.
- Finalizar el modelo 3D.
- Completar las fotografías finales.
- Documentar los resultados.
- Preparar la demostración en vivo.

---

## 20. Estado Actual

La Iteración 3 corresponde a la etapa de integración final del sistema electrónico e IoT.

Actualmente se cuenta con:

- Prototipo físico.
- ESP32.
- Sensor.
- LED.
- Buzzer pasivo.
- Circuito de prueba funcional.
- Firmware en desarrollo.
- Documentación de hardware.
- Protocolo de testing.
- Diseño de encapsulado.

El siguiente objetivo es completar la integración del sistema, realizar las pruebas finales y generar la evidencia necesaria para la presentación.