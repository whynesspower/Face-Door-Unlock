#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <ArduinoJson.h>
#include <Servo.h>
ESP8266WebServer server;
uint8_t pin_led = D0;
char* ssid = "Yashraj Shukla";
char* password = "12345678";
Servo myservo; 
void setup()
{
  myservo.attach(D4);
  pinMode(pin_led, OUTPUT);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/plain","Hello World!");});
  server.on("/toggle",toggleLED);
  server.begin();
}
