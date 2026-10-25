# Testing y Validación

## Objetivo

Evaluar el funcionamiento de los componentes electrónicos del pastillero inteligente y registrar los problemas identificados durante el desarrollo del prototipo.

Las pruebas se enfocan en la detección de interacción mediante el sensor y el funcionamiento de las alertas visuales y sonoras.

---

## Carpetas

### `evidencias/`

Fotografías y registros del funcionamiento del sensor, LED, buzzer y prototipo.

### `reportes/`

Descripción de las pruebas realizadas, problemas encontrados y soluciones implementadas.

### `datos/`

Registros de funcionamiento y mediciones obtenidas durante las pruebas.

---

## Metodología de Testing

El sistema se ha desarrollado mediante pruebas incrementales de sus componentes.

### Prueba del Sensor

Se utiliza un sensor o microinterruptor conectado al pin D2 / GPIO4 de la ESP8266.

El programa lee su estado mediante `digitalRead()` e identifica una nueva interacción comparando el estado actual con el anterior.

### Prueba del LED

El LED se encuentra conectado al pin D5 / GPIO14.

El código permite encenderlo cuando se activa la alarma y apagarlo cuando se detecta una nueva interacción.

### Prueba del Buzzer

El buzzer pasivo está conectado al pin D6 / GPIO12.

Durante el desarrollo se identificó que no era suficiente utilizar `digitalWrite()` para generar el sonido, por lo que se implementó la función `tone()`.

### Prueba de Integración

La lógica programada permite relacionar el sensor con las alertas:

1. Se detecta una interacción.
2. Se activa el LED y el buzzer.
3. Se detecta una segunda interacción.
4. Se desactivan ambas alertas.

La estabilidad del sistema durante cinco minutos continuos debe comprobarse mediante una prueba física.

---

## Errores Encontrados y Soluciones

| Problema | Causa identificada o posible | Solución |
|---|---|---|
| Buzzer sin sonido | Se estaba utilizando un buzzer pasivo sin generar una frecuencia | Implementación de `tone()` |
| Sensor sin respuesta | Posible error de conexión o configuración | Revisar GPIO4 y `INPUT_PULLUP` |
| LED sin encender | Posible error de polaridad o conexión | Verificar polaridad, resistencia y GPIO14 |
| Alarma que no se desactiva | Posible error en la detección de una segunda interacción | Revisar la comparación de estados del sensor |

El problema del buzzer está documentado como una dificultad encontrada durante el desarrollo. Los demás corresponden a posibles fallas y procedimientos de revisión.

---

## Validación del Prototipo

El sistema permite desarrollar una solución orientada al recordatorio de medicamentos mediante alertas visuales y sonoras.

La conectividad inalámbrica con Pill Up y la confirmación de toma de medicamentos requieren desarrollo y validación adicionales.

---

## Próximas Pruebas

- Verificar el funcionamiento continuo del sistema durante cinco minutos.
- Registrar evidencias fotográficas y videos de las alertas.
- Evaluar la integración electrónica dentro del encapsulado.
- Probar la comunicación futura con Pill Up.
- Realizar pruebas de usabilidad con usuarios.