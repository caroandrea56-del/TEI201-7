# Software - Documentación

## Contenido
Esta carpeta contiene todo el código y documentación del software del proyecto del pastillero inteligente.

### 📁 Carpetas

#### `src/`
Código fuente del proyecto en formato `.ino` para ESP8266.

#### `librerias/`
Librerías adicionales necesarias para el funcionamiento del proyecto.

#### `docs/`
Documentación técnica relacionada con el software.

---

## Stack Tecnológico

**Plataforma:** ESP8266 NodeMCU  
**Lenguaje:** C/C++  
**IDE:** Arduino IDE 2.x  

**Librerías principales:**
- Actualmente no se utilizan librerías externas.
- Se utilizan funciones nativas de Arduino como `digitalRead()`, `digitalWrite()`, `tone()` y `noTone()`.

---

## Instalación y Configuración

### 1. Instalar Arduino IDE
1. Descargar e instalar Arduino IDE.
2. Abrir Arduino IDE.
3. Instalar el soporte para placas ESP8266.
4. Conectar la ESP8266 al computador mediante USB.

### 2. Configurar ESP8266
1. Abrir Arduino IDE.
2. Seleccionar la placa ESP8266 correspondiente.
3. Seleccionar el puerto USB correcto.
4. Verificar que la placa sea reconocida.

### 3. Instalar Librerías
En la versión actual no se requieren librerías externas adicionales.

### 4. Cargar Código
1. Abrir `src/main.ino`.
2. Seleccionar la placa ESP8266.
3. Seleccionar el puerto correspondiente.
4. Compilar el código.
5. Subir el programa a la placa.
6. Abrir el Monitor Serial a 115200 baudios.

---

## Configuración de Parámetros

- Sensor / microinterruptor → D2 / GPIO4
- LED → D5 / GPIO14
- Buzzer pasivo → D6 / GPIO12

El sensor utiliza configuración `INPUT_PULLUP`.

El buzzer es pasivo, por lo que se activa mediante `tone()` y se apaga mediante `noTone()`.

---

## Arquitectura del Software

Sensor / microinterruptor  
↓  
ESP8266  
↓  
Procesamiento de la señal  
↓  
Cambio de estado de la alarma  
↓  
LED + Buzzer  
↓  
Alerta visual y sonora

### Módulos Principales

1. **Inicialización**
   - Configuración de pines.
   - Inicialización del Monitor Serial.
   - Estado inicial del LED y buzzer apagados.

2. **Lectura del Sensor**
   - Lectura del sensor mediante `digitalRead()`.

3. **Procesamiento**
   - Detección de la interacción del usuario.
   - Cambio del estado de la alarma.

4. **Actuación**
   - Encendido y apagado del LED.
   - Activación y desactivación del buzzer.

5. **Comunicación**
   - Visualización del estado del sistema mediante el Monitor Serial.
   - La conectividad WiFi queda considerada para futuras versiones.

---

## Funcionamiento Actual

1. El usuario activa el sensor / microinterruptor.
2. La ESP8266 detecta la señal.
3. Se enciende el LED.
4. El buzzer comienza a emitir sonido.
5. Una nueva interacción con el sensor apaga el LED y el buzzer.
6. El sistema queda disponible para una nueva activación.

---

## Testing del Software

Durante el desarrollo se realizaron pruebas de:

- lectura del sensor;
- encendido y apagado del LED;
- funcionamiento del buzzer;
- integración del sensor con los actuadores;
- activación y desactivación de la alarma.

Durante las primeras pruebas el buzzer no generaba sonido utilizando únicamente `digitalWrite()`. Se comprobó que el buzzer utilizado es pasivo, por lo que fue necesario utilizar `tone()` para generar la señal sonora.

---

## Próximas Mejoras

- Incorporar horarios programados para la toma de medicamentos.
- Integrar conectividad WiFi.
- Registrar eventos de apertura.
- Enviar información a una aplicación.
- Incorporar alertas de dosis pendientes.
- Mejorar la integración entre software y encapsulado físico.