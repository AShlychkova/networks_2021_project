#include <ESP8266WiFi.h> 
#include <WiFiClient.h> 
#include <ESP8266WebServer.h> 

const char* ssid = "<name>";
const char* password = "<password>";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Hi!");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  Serial.begin(115200);
  while(!Serial){};

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("\nIP addres: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.on("/temperature", []() {
    server.send(200, "text/plain", "0");
  });

  server.on("/humidity", []() {
    server.send(200, "text/plain", "50");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP-server is ready");
}

void loop(void) {
  server.handleClient();
}
