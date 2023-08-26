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
void loop()
{
  server.handleClient();
}
void toggleLED()
{
   for (int pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos); 
    delay(15);          
  }
  digitalWrite(pin_led,HIGH);
  server.send(204,"");
  delay(3000);
  digitalWrite(pin_led,LOW);
    for (int pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);                  // tell servo to go to position in variable 'pos'
    delay(15);                           // waits 15ms for the servo to reach the position
  }
}

