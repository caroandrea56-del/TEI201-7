# Esquemas de Circuito

## Archivos Requeridos

### Formato Fritzing
- `circuito_completo.fzz` - Archivo fuente del circuito en Fritzing
- `esquema_circuito.png` - Exportación visual del esquema
- `pcb_layout.png` - Opcional, layout de PCB si se desarrolla una versión final

### Formato Wokwi
- `wokwi_diagram.json` - Archivo del proyecto en Wokwi
- `wokwi_screenshot.png` - Captura del circuito
- `wokwi_link.txt` - URL del proyecto online

---

## Nomenclatura de Archivos

- Usar nombres descriptivos
- Incluir versión cuando corresponda: `v1_esquema_inicial.fzz`
- Para versiones finales usar: `v3_esquema_final.fzz`
- Incluir fecha en formato: `YYYYMMDD_descripcion`

Ejemplo:

`20261025_esquema_pastillero_v1.png`

---

## Conexiones del Prototipo Actual

| Componente | Pin ESP8266 | Función |
|------------|-------------|---------|
| Sensor / microinterruptor | D2 / GPIO4 | Detecta la interacción con la tapa |
| LED | D5 / GPIO14 | Alerta visual |
| Buzzer pasivo | D6 / GPIO12 | Alerta sonora |
| GND | GND | Tierra común del circuito |

---

## Notas de Diseño

El circuito fue diseñado utilizando una placa **ESP8266 NodeMCU** como unidad principal de procesamiento.

Se eligió esta placa porque permite controlar sensores y actuadores, además de incorporar conectividad WiFi para futuras etapas del proyecto.

El sensor / microinterruptor se utiliza para detectar la interacción del usuario con el pastillero.

El LED funciona como alerta visual y el buzzer pasivo como alerta sonora.

Durante las pruebas se comprobó que el buzzer requiere una señal de frecuencia para funcionar correctamente, por lo que se utiliza la función `tone()` en el código.

El sensor está configurado mediante `INPUT_PULLUP`, permitiendo simplificar el circuito al utilizar la resistencia interna de la ESP8266.

Todos los componentes comparten una conexión GND común.

---

## Flujo del Sistema

Sensor / microinterruptor  
↓  
ESP8266  
↓  
Procesamiento de la señal  
↓  
LED + Buzzer  
↓  
Alerta al usuario

---

## Consideraciones

- Verificar la polaridad del LED y del buzzer antes de alimentar el circuito.
- Revisar que todas las conexiones estén firmes.
- Mantener un GND común entre todos los componentes.
- Actualizar los esquemas si se modifica la distribución del circuito.
- Guardar versiones anteriores para documentar el proceso de iteración.