## Estado de la Entrega

El repositorio reúne la documentación técnica y de diseño correspondiente al prototipo final del pastillero inteligente.

La entrega incluye:

- Prototipo físico del pastillero.
- ESP32 como unidad principal de procesamiento.
- Sensor o microinterruptor para detección de interacción.
- LED como alerta visual.
- Buzzer pasivo como alerta sonora.
- Firmware del dispositivo.
- Documentación del hardware.
- BOM con componentes y costos de referencia.
- Esquemas y documentación de conexiones.
- Evidencia fotográfica del prototipo.
- Documentación de las iteraciones realizadas.
- Modelo y documentación de diseño 3D.
- Protocolo de testing.
- Documentación de fuentes y uso de inteligencia artificial.
- Informes y presentaciones desarrollados durante el proyecto.

---

## Validación del Sistema

La validación del prototipo considera el funcionamiento integrado de sus principales elementos:

1. Generación de una alerta asociada a una dosis.
2. Activación de una señal visual mediante LED.
3. Activación de una señal sonora mediante buzzer.
4. Detección de interacción mediante el sensor.
5. Procesamiento del evento mediante la ESP32.
6. Registro de la interacción.
7. Desactivación de la alerta.
8. Generación de información relacionada con el cumplimiento de la dosis.

Los protocolos utilizados para evaluar el sistema se encuentran documentados en:

`testing/`

---

## Diseño Final

El diseño físico corresponde a un pastillero rectangular de ocho compartimientos, organizado en una distribución de 4 × 2.

La estructura fue desarrollada considerando:

- Portabilidad.
- Integración electrónica.
- Accesibilidad.
- Reparabilidad.
- Fabricación mediante impresión 3D.
- Organización interna de los componentes.

La documentación asociada al modelo tridimensional se encuentra en:

`diseno_3d/`

---

## Documentación del Proyecto

La documentación completa se distribuye de la siguiente manera:

- `hardware/` — componentes, BOM, esquemas y fotografías.
- `firmware/` — código fuente de la ESP32.
- `diseno_3d/` — modelos, planos y renders.
- `iteraciones/` — evolución del diseño y del prototipo.
- `testing/` — metodología y resultados de validación.
- `docs/` — informes y presentaciones.
- `FUENTES.md` — referencias, dependencias, código externo y herramientas de inteligencia artificial utilizadas.

---

## Resultado del Proyecto

El proyecto permitió desarrollar un prototipo de pastillero inteligente que combina diseño físico, electrónica y procesamiento digital para apoyar la organización de medicamentos.

La propuesta integra alertas visuales y sonoras con detección de interacción del usuario y registro de eventos, permitiendo transformar una acción física sobre el pastillero en información útil para el seguimiento de las dosis.

El desarrollo se realizó mediante un proceso iterativo en el que se modificaron la geometría, dimensiones, sistema de apertura, integración electrónica y lógica de funcionamiento hasta obtener una versión más compacta, reparable y coherente con el problema abordado.