#include <Arduino.h>
#include <WiFi.h>

const char * ssid = "virus2";
const char * password ="a1b2c3d4";
const char * host = "www.google.com";
const int port = 80;
WiFiClient client;

/**
 * @brief Esta es la funcion que ejecuta la configuracion inicial del programa
*/

void setup() {
   WiFi.begin(ssid, password);
   Serial.begin(115200);
   Serial.println("Esperando conexion");
   while(WiFi.status()!=WL_CONNECTED){
      Serial.print(".");
      delay(4000);
   }
   Serial.println("\r\nConexion establecida");
   Serial.println(WiFi.localIP());



}


/**
 * @brief Esta es la funcion que inicia la ejecucion del programa
*/
void loop() {

   // Si no se puede conectar al servidor, se imprime un mensaje de error
   if(!client.connect(host, port)){
      Serial.println("Fallo la conexion");
      return;
   }

   // Si se logra conectar al servidor, se envia la cabecera HTTP de la peticion
   client.print("GET / HTTP/1.1\r\n");
   client.print("Connection: close\r\n\r\n");


   //Codigo que espera 5 segundos sin bloquear el programa
   unsigned long timeout = millis();
   while(client.available()==0){
      if(millis()-timeout >= 5000){
         Serial.println("Tiempo de espera agotado");
         client.stop();
         return;
      }
   }  

   // Se imprime la respuesta del servidor
   while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
   }
   
   Serial.println("Se termino la conexion");

   client.stop();
   
   delay(400);
}