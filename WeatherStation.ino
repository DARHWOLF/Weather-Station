#include <WiFi.h>
#include <PubSubClient.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "******";
const char* password = "********";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
AsyncWebServer server(80);

float internalTemperature = 0.0;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Set up MQTT
  client.setServer(mqtt_server, 1883);

  // Set up web server
  setupWebServer();

  // Subscribe to MQTT topic
  client.setCallback(callback);
  client.subscribe("weather_internal_temperature");
}

void loop() {
  client.loop();

  // Read temperature from internal sensor (dummy function, replace with actual sensor code)
  internalTemperature = random(20, 30);  // Replace with your actual sensor reading code

  // Publish internal temperature to MQTT
  if (client.connect("ESP32WeatherStation")) {
    client.publish("weather_internal_temperature", String(internalTemperature, 2).c_str());
  }

  delay(2000);
}

void setupWebServer() {
  // Handle root request
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body>";
    html += "<h1>ESP32 Weather Station</h1>";
    html += "<p>Internal Temperature: " + String(internalTemperature, 2) + "°C</p>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  // Start server
  server.begin();
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle MQTT message received
  if (strcmp(topic, "weather_internal_temperature") == 0) {
    payload[length] = '\0';  // Null-terminate the payload
    internalTemperature = atof((char*)payload);  // Convert payload to float
  }
}
