# Hardware - Documentación

## Contenido
Esta carpeta contiene toda la documentación técnica del hardware utilizado en el prototipo del pastillero inteligente.

### 📁 Carpetas

#### `esquemas/`
Diagramas de circuitos y esquemáticos del sistema.

#### `bom/`
Bill of Materials (Lista de materiales y componentes utilizados).

#### `fotos/`
Fotografías del prototipo electrónico, conexiones y pruebas realizadas.

---

## Instrucciones de Ensamble

### Componentes Principales
1. **ESP8266 NodeMCU** - Procesa las señales del sensor y controla los actuadores.
2. **Sensor / microinterruptor** - Detecta la interacción o apertura del compartimiento.
3. **LED** - Genera la alerta visual cuando el sistema se activa.
4. **Buzzer pasivo** - Genera la alerta sonora.
5. **Resistencia para LED** - Limita la corriente que circula por el LED.
6. **Protoboard** - Permite realizar las conexiones del circuito durante el prototipado.
7. **Cables Dupont** - Conectan los diferentes componentes con la ESP8266.

### Pasos de Ensamblaje
1. Conectar el sensor al pin **D2 / GPIO4** de la ESP8266 y su segundo terminal a **GND**.
2. Conectar el LED al pin **D5 / GPIO14** utilizando una resistencia en serie y conectar su segundo terminal a **GND**.
3. Conectar el buzzer pasivo al pin **D6 / GPIO12** y su segundo terminal a **GND**.
4. Verificar que todos los componentes compartan una conexión **GND común**.
5. Conectar la ESP8266 al computador mediante cable USB.
6. Cargar el programa desde Arduino IDE.
7. Activar el sensor y comprobar que el LED y el buzzer respondan correctamente.

### Precauciones
- ⚠️ Verificar la polaridad del LED y del buzzer antes de alimentar el circuito.
- ⚠️ No conectar directamente componentes a voltajes superiores a los admitidos por la ESP8266.
- ⚠️ Revisar que los cables estén correctamente fijados antes de realizar las pruebas.
- ⚠️ Mantener una conexión GND común entre todos los componentes.

---

## Especificaciones Técnicas

**Alimentación:** ESP8266 alimentada mediante USB, aproximadamente 5 V de entrada.  
**Consumo:** No medido experimentalmente en esta etapa del prototipo.  
**Dimensiones del prototipo físico:** Aproximadamente 100 mm x 80 mm x 30 mm.  
**Peso:** No medido experimentalmente en esta etapa.

---

## Troubleshooting

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| El LED no enciende | Polaridad incorrecta o conexión equivocada | Revisar polaridad, resistencia y conexión al pin D5 / GPIO14 |
| El buzzer no emite sonido | Se está utilizando `digitalWrite()` con un buzzer pasivo | Utilizar la función `tone()` para generar una frecuencia |
| El sensor no responde | Conexión incorrecta o configuración del pin | Verificar conexión a D2 / GPIO4 y utilizar `INPUT_PULLUP` |
| La alarma se activa pero no se apaga | El programa no detecta correctamente una segunda interacción | Revisar la lógica de cambio de estado y el debounce del sensor |
| El sistema se comporta de manera inestable | Cableado suelto o GND no compartido | Revisar todas las conexiones y asegurar un GND común |