# FUENTES.md

Este archivo documenta las librerías, código externo y herramientas de Inteligencia Artificial utilizadas durante el desarrollo del proyecto **Pastillero Inteligente** para TEI201.

---

## 1. Librerías y Dependencias

### Librerías utilizadas

En la versión actual del prototipo no se utilizan librerías externas adicionales.

El programa utiliza funciones incluidas en el entorno Arduino y en el soporte de la placa ESP8266, principalmente:

| Recurso | Uso en el proyecto | Fuente |
|---|---|---|
| Arduino Core | Estructura general del programa mediante `setup()` y `loop()` | Arduino IDE |
| `digitalRead()` | Lectura del sensor / microinterruptor | Arduino |
| `digitalWrite()` | Control del LED | Arduino |
| `tone()` | Generación de señal para el buzzer pasivo | Arduino |
| `noTone()` | Desactivación del buzzer | Arduino |
| `Serial.begin()` / `Serial.println()` | Debugging y visualización del estado del sistema | Arduino |

Si se incorporan posteriormente librerías para WiFi, almacenamiento de datos, dashboard u otros servicios, deberán agregarse a esta sección indicando nombre, versión, función y fuente.

---

## 2. Código Externo Adaptado

No se ha incorporado directamente código copiado desde repositorios externos, Stack Overflow u otros proyectos completos.

El código del prototipo fue desarrollado y adaptado específicamente para este proyecto con apoyo de herramientas de Inteligencia Artificial.

### Código de lectura del sensor y control de actuadores

**Archivo:** `firmware/src/main.ino`

**Función:**  
Detectar la interacción del usuario mediante un sensor / microinterruptor y controlar el LED y buzzer del sistema.

**Adaptaciones realizadas:**
- Sensor configurado en `D2 / GPIO4`.
- LED configurado en `D5 / GPIO14`.
- Buzzer configurado en `D6 / GPIO12`.
- Uso de `INPUT_PULLUP` para simplificar la conexión del sensor.
- Incorporación de una variable de estado para activar y desactivar la alarma.
- Incorporación de retardos para disminuir lecturas repetidas del sensor.

### Control del buzzer pasivo

Durante las primeras pruebas se intentó controlar el buzzer mediante una salida digital convencional.

Se comprobó experimentalmente que el buzzer utilizado era pasivo y necesitaba una señal de frecuencia.

Por esta razón se adaptó el código para utilizar:

`tone(pinBuzzer, 1000);`

y para detener el sonido:

`noTone(pinBuzzer);`

Esta modificación permitió que la alerta sonora funcionara correctamente.

---

## 3. Uso de Inteligencia Artificial

Durante el desarrollo se utilizó **ChatGPT de OpenAI** como herramienta de apoyo.

La IA fue utilizada para generar propuestas iniciales, explicar errores, apoyar el debugging, estructurar documentación y desarrollar código que posteriormente fue revisado y adaptado al prototipo real.

### 3.1 Código Arduino para ESP8266

**Herramienta:** ChatGPT — OpenAI  
**Periodo de uso:** 2026  

**Uso:**  
Apoyo para desarrollar y corregir el código de control del sensor, LED y buzzer conectado a una placa ESP8266.

**Prompt / solicitud realizada:**  
Se solicitó desarrollar un código Arduino para una ESP8266 que permitiera detectar un sensor o microinterruptor y controlar una alerta mediante un LED y un buzzer.

**Adaptación realizada por el equipo:**
- Se ajustaron los pines de acuerdo con las conexiones reales del circuito.
- Se probó cada componente individualmente.
- Se modificó el funcionamiento del buzzer al comprobar que era pasivo.
- Se incorporó `tone()` y `noTone()`.
- Se realizaron pruebas físicas hasta conseguir el funcionamiento del sistema.

**Comprensión:**  
El equipo comprende que el programa lee el estado digital del sensor y utiliza esa señal para cambiar el estado de la alarma. Cuando la alarma está activa se enciende el LED y se genera una frecuencia en el buzzer. Una nueva interacción permite desactivar ambos actuadores.

---

### 3.2 Debugging del buzzer

**Herramienta:** ChatGPT — OpenAI  

**Uso:**  
Diagnóstico del problema por el cual el LED funcionaba correctamente pero el buzzer no producía sonido.

**Problema detectado:**  
El buzzer no funcionaba mediante `digitalWrite()`.

**Adaptación:**  
Se realizó una prueba independiente del buzzer utilizando una frecuencia de 1000 Hz.

El código utilizado fue:

`tone(pinBuzzer, 1000);`

La prueba confirmó que el buzzer era pasivo y que necesitaba una señal de frecuencia.

Posteriormente esta solución se integró al código general del pastillero.

---

### 3.3 Estructura del repositorio GitHub

**Herramienta:** ChatGPT — OpenAI  

**Uso:**  
Apoyo para organizar el repositorio GitHub del proyecto.

**Elementos desarrollados con apoyo de IA:**
- Estructura de carpetas.
- README principal.
- README de hardware.
- README de software / firmware.
- Documentación de BOM.
- Documentación de esquemas.
- Documentación fotográfica.
- Organización de testing.
- Estructura del archivo `FUENTES.md`.

**Adaptación:**  
La estructura propuesta fue modificada de acuerdo con los requerimientos específicos de TEI201 y con los archivos reales generados durante el desarrollo del proyecto.

---

### 3.4 Diseño y modelado 3D

**Herramienta:** ChatGPT — OpenAI  

**Uso:**  
Apoyo en la conceptualización y desarrollo del encapsulado del pastillero inteligente y generación de propuestas de código para OpenSCAD.

**Solicitudes realizadas:**
- Diseño de un pastillero rectangular.
- Distribución de ocho compartimientos.
- Diseño de tapas independientes.
- Posicionamiento de bisagras.
- Modificación de dimensiones.
- Incorporación de espacio para electrónica.
- Incorporación de ventilación y perforaciones.
- Diseño de elementos desmontables y accesibles para reparación.

**Adaptación realizada por el equipo:**  
Las dimensiones y características fueron modificadas progresivamente a partir de pruebas de impresión 3D y necesidades reales del hardware.

---

### 3.5 Apoyo en documentación

**Herramienta:** ChatGPT — OpenAI  

**Uso:**  
Apoyo en la redacción y organización de documentación técnica relacionada con:

- proceso de iteración;
- testing y debugging;
- descripción del hardware;
- estructura del software;
- funcionamiento del sistema;
- organización del repositorio GitHub.

**Adaptación:**  
El contenido fue ajustado utilizando las características reales del prototipo y los resultados obtenidos durante las pruebas realizadas por el equipo.

---

## 4. Declaración de Comprensión y Adaptación

El equipo declara que las herramientas de Inteligencia Artificial fueron utilizadas como apoyo durante el proceso de desarrollo.

El código generado o sugerido fue revisado, probado y adaptado al hardware real del proyecto.

El equipo comprende el funcionamiento general del código implementado, incluyendo:

- lectura del sensor;
- configuración de entradas y salidas;
- funcionamiento de `INPUT_PULLUP`;
- activación del LED;
- generación de frecuencia mediante `tone()`;
- desactivación mediante `noTone()`;
- manejo del estado de la alarma;
- uso del Monitor Serial para debugging.

Las decisiones finales de diseño, conexiones, dimensiones, integración física y pruebas corresponden al desarrollo realizado por el equipo.

---

## 5. Actualización de este Archivo

Este documento debe actualizarse si durante las siguientes etapas se incorporan:

- nuevas librerías;
- código proveniente de fuentes externas;
- Firebase u otra plataforma de almacenamiento;
- herramientas para dashboard;
- nuevas funciones generadas con Inteligencia Artificial;
- nuevos recursos externos utilizados en el proyecto.