# Diseño 3D – Pastillero Inteligente

## 1. Objetivo

Esta carpeta contiene la documentación asociada al diseño tridimensional del pastillero inteligente.

El objetivo del modelo 3D es representar de forma coherente la estructura física del prototipo y permitir su fabricación, montaje, reparación y modificación.

El diseño debe considerar tanto la forma exterior como el espacio necesario para integrar los componentes electrónicos.

---

## 2. Estructura de la carpeta

La carpeta `diseno_3d/` se organiza de la siguiente manera:

```text
diseno_3d/
├── README.md
├── modelos_editables/
├── planos/
└── renders/
```

### `modelos_editables/`

Contiene los archivos fuente editables utilizados para desarrollar el diseño 3D.

Aquí deben almacenarse los archivos principales del modelo.

Ejemplos:

- `pastillero_final.f3d`
- `pastillero_final.f3z`
- Archivos auxiliares de diseño.
- Versiones anteriores relevantes.

### `planos/`

Contiene la documentación técnica del diseño.

Ejemplos:

- `planos_pastillero.pdf`
- Vistas acotadas.
- Medidas generales.
- Detalles de montaje.
- Secciones.
- Tolerancias.
- Archivos STL destinados a impresión 3D, si corresponde.

### `renders/`

Contiene las imágenes generadas a partir del modelo 3D.

Ejemplos:

- Vista exterior.
- Vista interior.
- Vista superior.
- Vista inferior.
- Vista explotada.
- Vista del sistema electrónico integrado.

---

## 3. Descripción del Diseño

La versión actual del pastillero utiliza una geometría rectangular y compacta.

El diseño fue desarrollado para facilitar:

- Transporte.
- Organización interna.
- Integración electrónica.
- Fabricación mediante impresión 3D.
- Acceso a los medicamentos.
- Apertura y reparación del sistema.

La estructura considera una zona superior destinada al uso del pastillero y una zona inferior destinada principalmente a contener e integrar el sistema electrónico.

---

## 4. Dimensiones Generales

La versión actual considera aproximadamente:

- Largo exterior: 75 mm.
- Ancho exterior: 58 mm.
- Altura total: 40 mm.

La estructura se divide aproximadamente en:

- Parte inferior: 20 mm de altura.
- Parte superior: 20 mm de altura.

Estas dimensiones pueden presentar ajustes menores en el modelo CAD final.

Las dimensiones definitivas deberán obtenerse directamente desde el archivo final de Fusion 360.

---

## 5. Compartimientos

El diseño considera ocho compartimientos destinados a medicamentos.

La distribución general corresponde a:

- Dos filas.
- Cuatro compartimientos por fila.

Esta distribución permite mantener un formato compacto y al mismo tiempo disponer de diferentes espacios de almacenamiento.

---

## 6. Sistema de Apertura

El diseño debe permitir que el dispositivo pueda abrirse y cerrarse sin destruir el encapsulado.

La estructura debe facilitar:

- Montaje.
- Desmontaje.
- Reparación.
- Inspección.
- Sustitución de componentes electrónicos.

El sistema de cierre definitivo deberá permitir mantener ambas partes unidas durante el uso normal, pero permitir el acceso al interior cuando sea necesario.

---

## 7. Reparabilidad

Uno de los criterios centrales del diseño es la reparabilidad.

Por esta razón, el modelo debe permitir acceso a:

- ESP32.
- Sensor.
- LED.
- Buzzer.
- Cableado.
- Conector USB.
- Elementos de montaje.

Los componentes electrónicos no deben quedar encapsulados de forma permanente.

---

## 8. Integración de la ESP32

El modelo 3D debe considerar el volumen ocupado por la ESP32 dentro del dispositivo.

En la versión final se deberá verificar:

- Largo de la placa.
- Ancho de la placa.
- Altura de la placa.
- Posición del conector USB.
- Espacio necesario para los cables.
- Separación respecto de las paredes.

La ubicación debe permitir conectar el cable USB sin desmontar completamente el dispositivo, siempre que sea posible.

---

## 9. Integración del Sensor

El sensor o microinterruptor debe ubicarse de forma que pueda detectar correctamente la interacción con el pastillero.

El modelo debe considerar:

- Posición.
- Espacio ocupado.
- Punto de activación.
- Acceso para mantenimiento.
- Ruta de cableado.

---

## 10. Integración del LED

El LED debe ubicarse de manera que pueda ser visible desde el exterior.

Su posición debe permitir que la alerta visual pueda ser identificada claramente por el usuario.

---

## 11. Integración del Buzzer

El buzzer debe disponer de una zona que permita la salida adecuada del sonido.

Para esto, el diseño puede incorporar una pequeña rejilla o perforaciones en el encapsulado.

En la versión actual se considera una zona de ventilación o salida de sonido mediante una matriz de pequeñas perforaciones.

---

## 12. Aberturas del Encapsulado

El diseño puede incorporar distintas aperturas destinadas a componentes o interfaces.

Entre ellas:

- Abertura para conexión USB.
- Abertura para LED.
- Perforaciones para salida de sonido.
- Espacio para sensor.
- Elementos de montaje.

Las dimensiones de estas aperturas deberán definirse según las medidas reales de los componentes.

---

## 13. Tolerancias

El modelo final debe considerar tolerancias de fabricación.

Esto es especialmente importante en:

- Tapas.
- Encajes.
- Aberturas.
- Piezas móviles.
- Montaje de componentes.
- Unión entre parte superior e inferior.

Las tolerancias deberán comprobarse mediante impresión y pruebas físicas.

---

## 14. Modelo Digital del Sistema

El modelo 3D final debe representar de manera aproximada los volúmenes reales de los componentes principales.

Como mínimo debe considerar:

- Encapsulado.
- ESP32.
- Sensor.
- LED.
- Buzzer.
- Espacio de cableado.
- Elementos principales del sistema físico.

El objetivo es que exista coherencia entre el prototipo físico y su representación digital.

---

## 15. Archivo Editable

La versión final del proyecto deberá incluir un archivo editable de Fusion 360.

Formato esperado:

`pastillero_final.f3d`

o, si corresponde a un conjunto:

`pastillero_final.f3z`

Este archivo debe permitir revisar la geometría, componentes, dimensiones y estructura del dispositivo.

---

## 16. Planos Técnicos

La carpeta `planos/` deberá contener un PDF con los principales planos técnicos.

El documento debería incluir:

- Vista frontal.
- Vista superior.
- Vista lateral.
- Vista inferior.
- Dimensiones generales.
- Espesores.
- Aberturas.
- Detalles de ensamblaje.

Nombre recomendado:

`planos_pastillero_final.pdf`

---

## 17. Renders

La carpeta `renders/` deberá incluir imágenes claras del modelo final.

Como mínimo se recomienda generar:

### Render 1 – Vista exterior

`01_render_exterior.png`

Debe mostrar el aspecto general del producto cerrado.

### Render 2 – Vista interior

`02_render_interior.png`

Debe mostrar el espacio interno y la disposición de componentes.

### Render 3 – Vista explotada

`03_render_explotado.png`

Debe mostrar las principales piezas separadas para explicar cómo se ensambla el producto.

### Render 4 – Integración electrónica

`04_render_electronica.png`

Debe mostrar la posición de la ESP32, sensor, LED y buzzer dentro del encapsulado.

---

## 18. Archivos para Impresión 3D

Si se generan archivos STL, deberán almacenarse de forma ordenada dentro de `planos/` o en una subcarpeta específica.

Ejemplo:

```text
planos/
├── planos_pastillero_final.pdf
├── cuerpo_inferior.stl
├── cuerpo_superior.stl
└── tapas.stl
```

Los STL deben corresponder a las piezas utilizadas para fabricar el prototipo físico.

---

## 19. Evolución del Diseño

El diseño 3D ha evolucionado durante el proyecto.

Entre los principales cambios se encuentran:

- Cambio de geometría general.
- Reducción de tamaño.
- Mejora en la distribución interna.
- Ajuste del espacio disponible.
- Incorporación de electrónica.
- Mejora de la reparabilidad.
- Modificación del sistema de apertura.
- Ajuste de perforaciones y zonas de acceso.

Estas modificaciones responden a problemas identificados durante las iteraciones y pruebas físicas.

---

## 20. Entregables Finales

Antes de la entrega final, esta carpeta deberá contener:

- Archivo editable de Fusion 360 `.f3d` o `.f3z`.
- Planos técnicos en PDF.
- Renders exteriores.
- Render interior.
- Vista explotada.
- Representación de los componentes electrónicos.
- Archivos STL utilizados para fabricar el prototipo, cuando corresponda.

---

## 21. Estado Actual

Actualmente se cuenta con una estructura de carpetas organizada para almacenar el modelo, planos y renders.

El diseño físico del pastillero ha sido desarrollado mediante distintas iteraciones.

Antes de la entrega final se debe:

- Incorporar el archivo editable definitivo.
- Verificar las dimensiones finales.
- Representar los componentes electrónicos dentro del modelo.
- Generar los planos técnicos.
- Generar los renders finales.
- Confirmar tolerancias.
- Verificar la correspondencia entre el modelo digital y el prototipo físico.