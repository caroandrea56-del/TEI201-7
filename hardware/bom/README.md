# Bill of Materials (BOM)

## Formato del Archivo

El archivo BOM debe incluir las siguientes columnas:

| Columna | Descripción | Ejemplo |
|---------|-------------|---------|
| Cantidad | Número de unidades | 1 |
| Componente | Nombre descriptivo | ESP8266 NodeMCU |
| Especificación | Detalles técnicos | WiFi integrado, 3.3 V |
| Fabricante | Marca del componente | Espressif |
| Código/SKU | Identificador único | ESP8266 |
| Proveedor | Tienda/distribuidor | MercadoLibre / tienda electrónica |
| Precio Unitario | Costo por unidad (CLP) | Por definir |
| Precio Total | Cantidad × Precio | Por definir |
| Datasheet | Link a especificaciones | Por agregar |

---

## Archivos a Incluir

- `bom_completo.xlsx` - Lista completa de materiales
- `bom_completo.pdf` - Versión PDF para visualización
- `datasheets/` - Carpeta con PDFs de componentes críticos

---

## Componentes Principales del Prototipo

| Cantidad | Componente | Especificación | Fabricante | Código/SKU | Proveedor | Precio Unitario | Precio Total | Datasheet |
|---------:|------------|----------------|------------|------------|-----------|-----------------|--------------|-----------|
| 1 | ESP8266 NodeMCU | WiFi integrado, lógica 3.3 V | Espressif / compatible | ESP8266 | Por definir | Por definir | Por definir | Por agregar |
| 1 | Sensor / microinterruptor | Sensor de contacto para detectar interacción | Por definir | Por definir | Por definir | Por definir | Por definir | Por agregar |
| 1 | LED | LED indicador visual | Por definir | Por definir | Por definir | Por definir | Por definir | Por agregar |
| 1 | Resistencia | Resistencia para protección del LED | Por definir | Por definir | Por definir | Por definir | Por definir | Por agregar |
| 1 | Buzzer pasivo | Alerta sonora controlada mediante `tone()` | Por definir | Por definir | Por definir | Por definir | Por definir | Por agregar |
| 1 | Protoboard | Placa de prototipado | Por definir | Por definir | Por definir | Por definir | Por definir | Por agregar |
| Varios | Cables Dupont | Cables de conexión | Por definir | Por definir | Por definir | Por definir | Por definir | Por agregar |
| 1 | Cable USB | Alimentación y programación de ESP8266 | Por definir | Por definir | Por definir | Por definir | Por definir | Por agregar |
| 1 | Encapsulado impreso en 3D | Pastillero 100 × 80 × 30 mm | Diseño propio | — | Impresión 3D | Por definir | Por definir | — |

---

## Presupuesto Total

**Costo Total Estimado:** Por definir

### Desglose por Categoría
- Microcontrolador: Por definir
- Sensores: Por definir
- Actuadores: Por definir
- Estructura / Encapsulado: Por definir
- Otros: Por definir

---

## Observaciones

- El buzzer utilizado es pasivo y requiere la función `tone()` para generar sonido.
- El sensor se encuentra configurado con `INPUT_PULLUP`.
- Todos los componentes comparten una conexión GND común.
- Los precios, fabricantes y proveedores deben completarse con los componentes reales utilizados en el prototipo.