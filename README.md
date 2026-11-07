# Proyecto-Final-3-ED2
Dispositivo Médico y Data Logger

# Integrantes
Kathy Anzueto 24910
Alysson Galindo 231960

# Descripción del proyecto
Este repositorio contiene el código del proyecto del curso Electrónica Digital 2. En este proyecto se diseñó e implementó un sistema médico de adquisición, visualización y registro de datos (Data Logger) para evaluar la recuperación de la movilidad del brazo (flexión media) mediante un sensor de giroscopio y acelerómetro, integrando dos microcontroladores STM32F446RE (Nucleo), un ESP32, comunicación inalámbrica Bluetooth y diversos periféricos embebidos.

# Funcionamiento general
El sistema opera mediante tres dispositivos principales distribuidos de la siguiente manera:

-ESP32: Actúa como interfaz inalámbrica, recibiendo comandos de lectura y guardado enviados desde un smartphone mediante Bluetooth y reenviándolos hacia la Nucleo 1.

-Nucleo 1 (Controlador Central): Coordina las operaciones del sistema, se comunica con el ESP32, la Nucleo 2 y la computadora por canales UART independientes. Es la encargada de actualizar un indicador visual NeoPixel según el estado de funcionamiento y de generar efectos de sonido analógicos mediante el DAC conectados a una bocina/buzzer.   

-Nucleo 2 (Adquisición y Registro): Al recibir la solicitud de la Nucleo 1, adquiere los datos del sensor giroscopio mediante el protocolo I2C, actualiza la interfaz gráfica en tiempo real en la pantalla TFT (ILI9341) conectada por SPI, y almacena las mediciones en una tarjeta SD cuando se le indica el comando de guardado.

# Componentes utilizados
El proyecto utiliza 2 microcontroladores NUCLEO-F446RE, 1 módulo ESP32, un sensor I2C (giroscopio), una pantalla LCD TFT, una tarjeta SD/microSD, un LED RGB NeoPixel, componentes para circuito de audio con DAC, protoboards y cables de conexión.

# Código
El programa está desarrollado en C++ utilizando PlatformIO y CubeIDE.
