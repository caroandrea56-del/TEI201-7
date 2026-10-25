# Evidencias de Testing

## Evidencias de Funcionamiento

Esta carpeta documenta las evidencias disponibles de las pruebas iniciales del pastillero inteligente, incluyendo los componentes electrónicos y su funcionamiento.

### Prueba del LED

Se cuenta con una fotografía del LED encendido durante el desarrollo del prototipo.

Esta imagen permite registrar la activación de la luz, aunque por sí sola no demuestra el funcionamiento integrado del sensor, LED y buzzer.

### Fotografías del Prototipo

Las fotografías de los componentes electrónicos, conexiones y estructura del pastillero se encuentran disponibles en la carpeta [`hardware/fotos/`](../../hardware/fotos/).

Estas imágenes permiten observar la construcción del circuito y los componentes utilizados.

### Prueba del Sistema Integrado

El código desarrollado contempla la activación y desactivación de las alertas mediante la interacción con el sensor.

Actualmente no se cuenta con evidencia audiovisual que permita mostrar el funcionamiento completo del sistema integrado.

---

## Errores y Mejoras

Durante el desarrollo se identificó que el buzzer utilizado era pasivo, por lo que se incorporó la función `tone()` para generar la señal sonora.

Esta modificación se encuentra reflejada en el código Arduino.

---

## Evidencias Complementarias

La documentación técnica del circuito y las pruebas de funcionamiento se encuentra distribuida entre las carpetas `hardware/`, `software/` y `testing/`.

A medida que se realicen nuevas pruebas se podrán incorporar fotografías, registros y resultados adicionales.