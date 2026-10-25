# Historial de Iteraciones

## Objetivo

Documentar la evolución del pastillero inteligente, registrando las modificaciones realizadas durante el desarrollo del prototipo y las mejoras implementadas.

## Iteración 1 — Diseño inicial

La primera propuesta consistía en un pastillero circular con un mecanismo de apertura más complejo.

Durante las pruebas iniciales se identificaron dificultades relacionadas con el tamaño, la portabilidad y el sistema de apertura.

## Iteración 2 — Rediseño rectangular

Se modificó el diseño circular por una estructura rectangular de aproximadamente 100 × 80 × 30 mm, con ocho compartimientos distribuidos en dos filas de cuatro.

Las principales modificaciones fueron la reducción del tamaño, incorporación de tapas individuales, reubicación de las bisagras y corrección de los ejes de giro.

## Iteración 3 — Integración electrónica

El desarrollo del prototipo contempla la incorporación de una ESP8266 NodeMCU, un sensor o microinterruptor, un LED y un buzzer pasivo.

El código actual permite detectar una interacción con el sensor y activar o desactivar las alertas visuales y sonoras.

La integración de los componentes dentro del encapsulado y la conectividad con Pill Up corresponden a etapas de desarrollo que deben validarse.

## Principales Aprendizajes

- La simplificación del diseño permitió avanzar hacia una estructura más compacta.
- Las modificaciones de las bisagras buscaron mejorar el mecanismo de apertura.
- El buzzer pasivo requiere una señal generada mediante `tone()` para producir sonido.
- La integración entre los componentes electrónicos y el encapsulado es necesaria para completar el funcionamiento del dispositivo.

## Evidencias

Las fotografías y registros de las versiones desarrolladas se organizan en `iteracion_1/`, `iteracion_2/` e `iteracion_3/`.