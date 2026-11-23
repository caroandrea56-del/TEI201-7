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

El circuito electrónico del pastillero inteligente utiliza una placa **ESP32 Dev Module con módulo ESP-WROOM-32**, que incorpora conectividad Wi-Fi y Bluetooth y permite controlar los componentes electrónicos del prototipo.

Se seleccionó esta placa por su capacidad de controlar las alertas visuales y sonoras, además de permitir la incorporación de funciones de conectividad en el sistema.

El **LED rojo**, conectado al GPIO25 mediante una resistencia de 300 Ω, funciona como alerta visual mediante parpadeos.

El **pulsador**, conectado al GPIO27 y configurado mediante `INPUT_PULLUP`, permite que el usuario silencie la alarma. Se comprobó que una pulsación detiene el parpadeo del LED.

El **buzzer** está destinado a proporcionar una alerta sonora. Se contempla su control desde el GPIO26 mediante un transistor BC547 y una resistencia de 1 kΩ. Sin embargo, su tipo, tensión y consumo todavía deben verificarse antes de completar y probar esta conexión.

La alimentación definitiva considera dos baterías recargables de ion-litio tipo 18650 y un portabaterías. Su salida eléctrica y condiciones de seguridad deben verificarse antes de conectarlo a la ESP32.

Los componentes del circuito deben compartir una conexión GND común cuando corresponda.

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
