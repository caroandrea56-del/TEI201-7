# Testing del prototipo

## 1. Objetivo de las pruebas

El objetivo de las pruebas es verificar que el pastillero inteligente funcione de manera estable y que sea capaz de detectar correctamente la interacción del usuario, activar las alertas y registrar la información necesaria para monitorear la toma de medicamentos.

Las pruebas consideran tanto el funcionamiento del hardware como la respuesta del sistema frente a distintos eventos de uso.

---

## 2. Elementos evaluados

Durante las pruebas se evaluarán los siguientes elementos:

- Funcionamiento del sensor.
- Activación del LED.
- Activación del buzzer.
- Tiempo de respuesta del sistema.
- Registro de eventos.
- Detección de una dosis confirmada.
- Funcionamiento del dashboard.
- Persistencia de los datos.
- Estabilidad del sistema durante múltiples ciclos de uso.

---

## 3. Condiciones de prueba

Las pruebas se realizarán con el prototipo armado y energizado mediante conexión USB.

El sistema estará compuesto por:

- ESP32.
- Sensor o microinterruptor.
- LED.
- Buzzer pasivo.
- Resistencias y conexiones correspondientes.
- Estructura física del pastillero.

Las pruebas se realizarán simulando el uso normal del dispositivo.

---

## 4. Protocolo de prueba

### Prueba 1: detección del sensor

Objetivo:

Verificar que el sistema detecte correctamente la activación del sensor.

Procedimiento:

1. Encender el sistema.
2. Activar manualmente el sensor.
3. Observar la respuesta del sistema.
4. Repetir el procedimiento 10 veces.

Criterio de éxito:

El sensor debe ser detectado correctamente en al menos 9 de 10 intentos.

Datos a registrar:

- Número de intentos.
- Número de detecciones correctas.
- Número de errores.
- Porcentaje de éxito.

---

### Prueba 2: funcionamiento del LED

Objetivo:

Verificar que el LED se active correctamente cuando exista una alerta.

Procedimiento:

1. Activar una alerta.
2. Observar si el LED se enciende.
3. Confirmar la interacción con el sensor.
4. Verificar que el LED se apague.
5. Repetir 10 veces.

Criterio de éxito:

El LED debe encenderse y apagarse correctamente en al menos 9 de 10 ciclos.

---

### Prueba 3: funcionamiento del buzzer

Objetivo:

Verificar que el buzzer pasivo emita correctamente la alerta sonora.

Procedimiento:

1. Activar una alerta.
2. Comprobar que el buzzer emita sonido.
3. Activar el sensor para confirmar la interacción.
4. Verificar que el buzzer se detenga.
5. Repetir 10 veces.

Criterio de éxito:

El buzzer debe funcionar correctamente en al menos 9 de 10 ciclos.

---

### Prueba 4: tiempo de respuesta

Objetivo:

Medir el tiempo que transcurre entre la activación de una alerta y la interacción del usuario.

Procedimiento:

1. Activar una alerta.
2. Iniciar el registro del tiempo.
3. Activar el sensor.
4. Registrar el tiempo transcurrido.
5. Repetir al menos 5 veces.

Datos a registrar:

- Tiempo de respuesta en segundos.
- Tiempo mínimo.
- Tiempo máximo.
- Tiempo promedio.

Criterio de éxito:

El sistema debe registrar correctamente el tiempo de respuesta en cada prueba.

---

### Prueba 5: registro de eventos

Objetivo:

Verificar que los eventos generados por el dispositivo queden registrados correctamente.

Procedimiento:

1. Activar una alerta.
2. Activar el sensor.
3. Revisar el registro generado.
4. Confirmar que aparezca el evento correspondiente.
5. Repetir 5 veces.

Criterio de éxito:

Todos los eventos deben quedar registrados correctamente.

---

### Prueba 6: persistencia de datos

Objetivo:

Verificar que la información registrada no se pierda al reiniciar el sistema.

Procedimiento:

1. Generar al menos 5 eventos.
2. Verificar que aparezcan en el historial.
3. Apagar o reiniciar el dispositivo.
4. Volver a encenderlo.
5. Revisar nuevamente el historial.

Criterio de éxito:

Los datos registrados antes del reinicio deben seguir disponibles.

---

### Prueba 7: funcionamiento del dashboard

Objetivo:

Verificar que el dashboard muestre correctamente la información generada por el dispositivo.

Procedimiento:

1. Encender el sistema.
2. Acceder al dashboard.
3. Generar diferentes eventos.
4. Observar la actualización de los indicadores.
5. Comparar la información mostrada con los eventos realizados.

Criterio de éxito:

El dashboard debe mostrar correctamente:

- Dosis programadas.
- Dosis tomadas.
- Dosis pendientes.
- Porcentaje de cumplimiento.
- Estado de la alarma.
- Historial de eventos.

---

### Prueba 8: funcionamiento continuo

Objetivo:

Evaluar la estabilidad general del sistema durante múltiples ciclos de uso.

Procedimiento:

1. Encender el dispositivo.
2. Realizar 20 ciclos consecutivos de alerta e interacción.
3. Registrar cualquier falla.
4. Revisar el funcionamiento del sensor, LED, buzzer y sistema de registro.

Criterio de éxito:

El sistema debe completar al menos 18 de los 20 ciclos sin fallas.

---

## 5. Registro de resultados

Los resultados de cada prueba deberán registrarse en una tabla.

Ejemplo:

| Prueba | Intentos | Éxitos | Errores | Resultado |
|---|---:|---:|---:|---|
| Sensor | 10 | Por completar | Por completar | Por completar |
| LED | 10 | Por completar | Por completar | Por completar |
| Buzzer | 10 | Por completar | Por completar | Por completar |
| Registro | 5 | Por completar | Por completar | Por completar |
| Persistencia | 1 | Por completar | Por completar | Por completar |
| Dashboard | 5 | Por completar | Por completar | Por completar |

---

## 6. Evidencia

La evidencia de las pruebas se almacenará dentro de esta carpeta e incluirá:

- Fotografías del prototipo durante las pruebas.
- Capturas del dashboard.
- Registro de datos.
- Fotografías del montaje.
- Videos breves del funcionamiento.
- Resultados de las pruebas.

---

## 7. Fallas detectadas y mejoras

Durante las pruebas se deberán registrar todas las fallas observadas.

Para cada falla se documentará:

- Descripción del problema.
- Condición en que ocurrió.
- Posible causa.
- Solución aplicada.
- Resultado después de la corrección.

Ejemplo:

Falla detectada:

El buzzer no emitía sonido utilizando una señal digital simple.

Causa:

El componente utilizado corresponde a un buzzer pasivo.

Solución:

Se utilizó una señal de frecuencia mediante la función correspondiente para generar el sonido.

Resultado:

El buzzer comenzó a funcionar correctamente.

---

## 8. Validación del problema

El prototipo busca apoyar la adherencia al tratamiento mediante recordatorios y confirmación de interacción con el pastillero.

La validación final deberá analizar si el sistema permite:

- Alertar al usuario cuando corresponde una toma.
- Detectar la interacción con el pastillero.
- Registrar la confirmación de una dosis.
- Mantener un historial de eventos.
- Entregar información útil sobre el cumplimiento.

A partir de los resultados obtenidos se evaluará si el prototipo responde adecuadamente al problema identificado y qué mejoras son necesarias para futuras iteraciones.

---

## 9. Estado actual

Protocolo de pruebas definido.

Los resultados cuantitativos serán incorporados una vez realizadas las pruebas con el prototipo final.