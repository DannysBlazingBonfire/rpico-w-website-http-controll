#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

#define LED_PIN 28

const char* SSID = "SSID-Here";
const char* password = "Password-Here";
String ledState = "OFF";

WebServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  delay(5000);
  connectToWiFi();
  setupEndPoints();
}

void loop() {
  server.handleClient();
}

void setupEndPoints() {
  server.on("/", rootRequest);
  server.on("/led/on", turnLedOn);
  server.on("/led/off", turnLedOff);

  server.begin();
  Serial.println("Server ready to handle HTTP requests");
}

// End-Point functions
void rootRequest() {
  server.send(200, "text/plain", "rpico server is running");
}

void turnLedOn() {
  digitalWrite(LED_PIN, HIGH);
  ledState = "ON";
  String response = "led is: " + ledState;
  server.send(200, "text/plain", response);
}

void turnLedOff() {
  digitalWrite(LED_PIN, LOW);
  ledState = "OFF";
  String response = "led is: " + ledState;
  server.send(200, "text/plain", response);
}

void connectToWiFi() {
  Serial.print("Connecting to: ");
  Serial.print(SSID);
  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.print("IP adress: ");
  Serial.println(WiFi.localIP());
  server.begin();
}


/*
to send HTTP request: http://<rpico ip>/led/on

HTTP status codes:
200 - OK
500 - internal server error
404 - not found
400 - bad request
*/
