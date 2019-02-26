#include <ESP8266WiFi.h>

byte ledPin = 2;
char ssid[] = "AltSense";           // SSID of your AP
char pass[] = "alt2018sense";         // password of your AP


WiFiClient client;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  //  WiFi.config(node4,gateway,mask);
  WiFi.begin(ssid, pass);           // connects to the WiFi AP
  Serial.println();
  Serial.println("Connection to the AP");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  server.begin();
  Serial.println();
  Serial.println("Connected");
  Serial.println("station_bare_01.ino");
  Serial.print("Your LocalIP is : ");
  Serial.println(WiFi.localIP());
  Serial.print("To see patient monitoring page in action, open a browser to http://");
  Serial.println(WiFi.localIP());
  //  Serial.println("MAC:" + WiFi.macAddress());
  //  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
  //  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
  pinMode(ledPin, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client");
  }
  client.print("<h1>PATIENT MONITORING SITE</h1>");
  client.print("<h2>CO2 LEVEL :</h2> ");
  client.println(analogRead(A0));
  delay(10);
  client.stop();
}




