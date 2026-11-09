#include <Arduino.h>
#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE
#include <DabbleESP32.h>

String Serialdata = "";
bool dataflag = 0;
String comando = "";

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, 13, 14);   // UART hacia el Nucleo (TX=14)
  Dabble.begin("MyEsp32");
}

void loop() {

  Dabble.processInput();

  // --- Monitor Serie -> celular (igual que antes) ---
  while (Serial.available() != 0)
  {
    Serialdata = String(Serialdata + char(Serial.read()));
    dataflag = 1;
  }
  if (dataflag == 1)
  {
    Terminal.print(Serialdata);
    Serialdata = "";
    dataflag = 0;
  }

  // --- Lo que llega del celular por Bluetooth ---
  if (Terminal.available() != 0)
  {
    comando = "";                       // limpia antes de leer
    while (Terminal.available() != 0)
    {
      comando += (char)Terminal.read(); // junta todo lo que llego
    }
    comando.trim();                     // funcion para quitar espacios
    comando.toLowerCase();              // no importa si se introduce mayus o minus

    Serial.print("Recibido del BT: ");
    Serial.println(comando);

       if (comando == "m" || comando == "medir")
    {
      Serial2.write('M');
      Serial.println(">> Enviado al Nucleo: M");
    }
    else if (comando == "g" || comando == "guardar")
    {
      Serial2.write('G');
      Serial.println(">> Enviado al Nucleo: G");
    }
    else
    {
      Serial2.write('X');                          // <-cualquier otra cosa = invalido
      Serial.println(">> Comando invalido");
    }
  }
}