#include <Arduino.h>
#include <WiFi.h>

const char * ssid = "virus32";
const char * password = "a1b2c3d4";

/**
 * @brief Esta es la funcion que ejecuta la configuración inicial del programa
*/

void setup() {
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  Serial.println("Esperando conexión");
  while (WiFi.status()!= WL_CONNECTED){
    Serial.print(".");
    delay(4000);
  }
  Serial.print("\r\nConexión establecida");
}

/**
 * @brief Esta es la funcion que inicia la ejecución del programa
*/

void loop() {
    delay(400);
}

