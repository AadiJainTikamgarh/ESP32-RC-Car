#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Samsung M12";
const char* password = "esp32rccar";

// Set listening port 80
WebServer server(80);

// Motor control pins
#define M1_IN1 33  
#define M1_IN2 32
#define M1_EN 25

#define M2_IN1 19
#define M2_IN2 18
#define M2_EN 5

#define M3_IN1 14
#define M3_IN2 27
#define M3_EN 12

#define M4_IN1 16
#define M4_IN2 17
#define M4_EN 4


void moveForward() {
  // Setting all motor to move forward
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  analogWrite(M1_EN, 255);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);
  analogWrite(M2_EN, 255);

  digitalWrite(M3_IN1, LOW);
  digitalWrite(M3_IN2, HIGH);
  analogWrite(M3_EN, 255);

  digitalWrite(M4_IN1, LOW);
  digitalWrite(M4_IN2, HIGH);
  analogWrite(M4_EN, 255);

  String html = "<!DOCTYPE html><html lang='en' style='height: 100vh'>";
  html += "<head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  html += "<title>ESP32 Car Control</title><style>";
  html += "body { background-color: black; height: 100%; padding: 0; margin: 0; }";
  html += ".container { height: 100%; display: flex; flex-direction: column; justify-content: space-between; gap: 4px; padding: 2px; }";
  html += ".btn { color: white; background-color: #3551e0; width: 200px; height: 100px; font-size: 30px; padding: 10px; border: none; cursor: pointer; }";
  html += ".stop-btn { background-color: red; width: 80px; height: 80px; font-size: larger; }";
  html += ".row { display: flex; justify-content: center; }";
  html += ".row-between { display: flex; justify-content: space-between; align-items: center; }";
  html += "</style></head><body>";
  html += "<div class='container'>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/F'\">Forward</button></div>";
  html += "<div class='row-between'>";
  html += "<button class='btn' onclick=\"location.href='/L'\">Left</button>";
  html += "<button class='btn stop-btn' onclick=\"location.href='/S'\">Stop</button>";
  html += "<button class='btn' onclick=\"location.href='/R'\">Right</button>";
  html += "</div>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/B'\">Backward</button></div>";
  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

void moveBackward() {
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
  analogWrite(M1_EN, 255);

  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  analogWrite(M2_EN, 255);

  digitalWrite(M3_IN1, HIGH);
  digitalWrite(M3_IN2, LOW);
  analogWrite(M3_EN, 255);

  digitalWrite(M4_IN1, HIGH);
  digitalWrite(M4_IN2, LOW);
  analogWrite(M4_EN, 255);


  String html = "<!DOCTYPE html><html lang='en' style='height: 100vh'>";
  html += "<head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  html += "<title>ESP32 Car Control</title><style>";
  html += "body { background-color: black; height: 100%; padding: 0; margin: 0; }";
  html += ".container { height: 100%; display: flex; flex-direction: column; justify-content: space-between; gap: 4px; padding: 2px; }";
  html += ".btn { color: white; background-color: #3551e0; width: 200px; height: 100px; font-size: 30px; padding: 10px; border: none; cursor: pointer; }";
  html += ".stop-btn { background-color: red; width: 80px; height: 80px; font-size: larger; }";
  html += ".row { display: flex; justify-content: center; }";
  html += ".row-between { display: flex; justify-content: space-between; align-items: center; }";
  html += "</style></head><body>";
  html += "<div class='container'>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/F'\">Forward</button></div>";
  html += "<div class='row-between'>";
  html += "<button class='btn' onclick=\"location.href='/L'\">Left</button>";
  html += "<button class='btn stop-btn' onclick=\"location.href='/S'\">Stop</button>";
  html += "<button class='btn' onclick=\"location.href='/R'\">Right</button>";
  html += "</div>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/B'\">Backward</button></div>";
  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

void stopMotors() {
  analogWrite(M1_EN, 0);
  analogWrite(M2_EN, 0);
  analogWrite(M3_EN, 0);
  analogWrite(M4_EN, 0);


  String html = "<!DOCTYPE html><html lang='en' style='height: 100vh'>";
  html += "<head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  html += "<title>ESP32 Car Control</title><style>";
  html += "body { background-color: black; height: 100%; padding: 0; margin: 0; }";
  html += ".container { height: 100%; display: flex; flex-direction: column; justify-content: space-between; gap: 4px; padding: 2px; }";
  html += ".btn { color: white; background-color: #3551e0; width: 200px; height: 100px; font-size: 30px; padding: 10px; border: none; cursor: pointer; }";
  html += ".stop-btn { background-color: red; width: 80px; height: 80px; font-size: larger; }";
  html += ".row { display: flex; justify-content: center; }";
  html += ".row-between { display: flex; justify-content: space-between; align-items: center; }";
  html += "</style></head><body>";
  html += "<div class='container'>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/F'\">Forward</button></div>";
  html += "<div class='row-between'>";
  html += "<button class='btn' onclick=\"location.href='/L'\">Left</button>";
  html += "<button class='btn stop-btn' onclick=\"location.href='/S'\">Stop</button>";
  html += "<button class='btn' onclick=\"location.href='/R'\">Right</button>";
  html += "</div>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/B'\">Backward</button></div>";
  html += "</div></body></html>";


  server.send(200, "text/html", html);
}

void moveLeft() {
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  analogWrite(M1_EN, 0);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);
  analogWrite(M2_EN, 255);

  digitalWrite(M3_IN1, LOW);
  digitalWrite(M3_IN2, HIGH);
  analogWrite(M3_EN, 0);

  digitalWrite(M4_IN1, LOW);
  digitalWrite(M4_IN2, HIGH);
  analogWrite(M4_EN, 255);


  String html = "<!DOCTYPE html><html lang='en' style='height: 100vh'>";
  html += "<head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  html += "<title>ESP32 Car Control</title><style>";
  html += "body { background-color: black; height: 100%; padding: 0; margin: 0; }";
  html += ".container { height: 100%; display: flex; flex-direction: column; justify-content: space-between; gap: 4px; padding: 2px; }";
  html += ".btn { color: white; background-color: #3551e0; width: 200px; height: 100px; font-size: 30px; padding: 10px; border: none; cursor: pointer; }";
  html += ".stop-btn { background-color: red; width: 80px; height: 80px; font-size: larger; }";
  html += ".row { display: flex; justify-content: center; }";
  html += ".row-between { display: flex; justify-content: space-between; align-items: center; }";
  html += "</style></head><body>";
  html += "<div class='container'>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/F'\">Forward</button></div>";
  html += "<div class='row-between'>";
  html += "<button class='btn' onclick=\"location.href='/L'\">Left</button>";
  html += "<button class='btn stop-btn' onclick=\"location.href='/S'\">Stop</button>";
  html += "<button class='btn' onclick=\"location.href='/R'\">Right</button>";
  html += "</div>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/B'\">Backward</button></div>";
  html += "</div></body></html>";


  server.send(200, "text/html", html);
}

void moveRight() {
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
  analogWrite(M1_EN, 255);

  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, HIGH);
  analogWrite(M2_EN, 0);

  digitalWrite(M3_IN1, LOW);
  digitalWrite(M3_IN2, HIGH);
  analogWrite(M3_EN, 255);

  digitalWrite(M4_IN1, LOW);
  digitalWrite(M4_IN2, HIGH);
  analogWrite(M4_EN, 0);


  String html = "<!DOCTYPE html><html lang='en' style='height: 100vh'>";
  html += "<head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  html += "<title>ESP32 Car Control</title><style>";
  html += "body { background-color: black; height: 100%; padding: 0; margin: 0; }";
  html += ".container { height: 100%; display: flex; flex-direction: column; justify-content: space-between; gap: 4px; padding: 2px; }";
  html += ".btn { color: white; background-color: #3551e0; width: 200px; height: 100px; font-size: 30px; padding: 10px; border: none; cursor: pointer; }";
  html += ".stop-btn { background-color: red; width: 80px; height: 80px; font-size: larger; }";
  html += ".row { display: flex; justify-content: center; }";
  html += ".row-between { display: flex; justify-content: space-between; align-items: center; }";
  html += "</style></head><body>";
  html += "<div class='container'>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/F'\">Forward</button></div>";
  html += "<div class='row-between'>";
  html += "<button class='btn' onclick=\"location.href='/L'\">Left</button>";
  html += "<button class='btn stop-btn' onclick=\"location.href='/S'\">Stop</button>";
  html += "<button class='btn' onclick=\"location.href='/R'\">Right</button>";
  html += "</div>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/B'\">Backward</button></div>";
  html += "</div></body></html>";


  server.send(200, "text/html", html);
}

void moveCenter() {
  analogWrite(M1_EN, 255);
  analogWrite(M2_EN, 255);
  analogWrite(M3_EN, 255);
  analogWrite(M4_EN, 255);

  
  String html = "<!DOCTYPE html><html lang='en' style='height: 100vh'>";
  html += "<head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  html += "<title>ESP32 Car Control</title><style>";
  html += "body { background-color: black; height: 100%; padding: 0; margin: 0; }";
  html += ".container { height: 100%; display: flex; flex-direction: column; justify-content: space-between; gap: 4px; padding: 2px; }";
  html += ".btn { color: white; background-color: #3551e0; width: 200px; height: 100px; font-size: 30px; padding: 10px; border: none; cursor: pointer; }";
  html += ".stop-btn { background-color: red; width: 80px; height: 80px; font-size: larger; }";
  html += ".row { display: flex; justify-content: center; }";
  html += ".row-between { display: flex; justify-content: space-between; align-items: center; }";
  html += "</style></head><body>";
  html += "<div class='container'>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/F'\">Forward</button></div>";
  html += "<div class='row-between'>";
  html += "<button class='btn' onclick=\"location.href='/L'\">Left</button>";
  html += "<button class='btn stop-btn' onclick=\"location.href='/S'\">Stop</button>";
  html += "<button class='btn' onclick=\"location.href='/R'\">Right</button>";
  html += "</div>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/B'\">Backward</button></div>";
  html += "</div></body></html>";


  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  
  Serial.println("\nWiFi connected.");
  Serial.println(WiFi.localIP()); // Print ESP32 IP Address

  server.on("/", handleRoot);
  server.on("/F", moveForward);
  server.on("/B", moveBackward);
  server.on("/S", stopMotors);
  server.on("/L", moveLeft);
  server.on("/R", moveRight);
  server.on("/C", moveCenter);

  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);
  pinMode(M1_EN, OUTPUT);

  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);
  pinMode(M2_EN, OUTPUT);

  pinMode(M3_IN1, OUTPUT);
  pinMode(M3_IN2, OUTPUT);
  pinMode(M3_EN, OUTPUT);

  pinMode(M4_IN1, OUTPUT);
  pinMode(M4_IN2, OUTPUT);
  pinMode(M4_EN, OUTPUT);

  server.begin();
}

void handleRoot() {
  
  String html = "<!DOCTYPE html><html lang='en' style='height: 100vh'>";
  html += "<head><meta charset='UTF-8' /><meta name='viewport' content='width=device-width, initial-scale=1.0' />";
  html += "<title>ESP32 Car Control</title><style>";
  html += "body { background-color: black; height: 100%; padding: 0; margin: 0; }";
  html += ".container { height: 100%; display: flex; flex-direction: column; justify-content: space-between; gap: 4px; padding: 2px; }";
  html += ".btn { color: white; background-color: #3551e0; width: 200px; height: 100px; font-size: 30px; padding: 10px; border: none; cursor: pointer; }";
  html += ".stop-btn { background-color: red; width: 80px; height: 80px; font-size: larger; }";
  html += ".row { display: flex; justify-content: center; }";
  html += ".row-between { display: flex; justify-content: space-between; align-items: center; }";
  html += "</style></head><body>";
  html += "<div class='container'>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/F'\">Forward</button></div>";
  html += "<div class='row-between'>";
  html += "<button class='btn' onclick=\"location.href='/L'\">Left</button>";
  html += "<button class='btn stop-btn' onclick=\"location.href='/S'\">Stop</button>";
  html += "<button class='btn' onclick=\"location.href='/R'\">Right</button>";
  html += "</div>";
  html += "<div class='row'><button class='btn' onclick=\"location.href='/B'\">Backward</button></div>";
  html += "</div></body></html>";


  server.send(200, "text/html", html);
}

void loop() {
  server.handleClient();
}
