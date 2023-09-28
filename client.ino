#include <SPI.h>
#include <LoRa.h>
#include "DHT.h"
#include <ArduinoJson.h>

#define DHTPIN 13     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

// Define the pins used by the LoRa transceiver module
#define NSS 4
#define RST 5
#define DI0 2

// Create a JSON document to hold the incoming data
DynamicJsonDocument doc(2048);

// Function prototypes
void initializeLora();
void sendPacket(String data);
void pushJsonDoc(String name, float data);

// =========================================================

void setup() {
  Serial.begin(9600);
  dht.begin();
  initializeLora();
}

// =========================================================

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.println(F("°F"));

  pushJsonDoc("Humidity", h);
  pushJsonDoc("Temperature_C", t);
  pushJsonDoc("Temperature_F", f);
  String jsonPacket;
  serializeJson(doc, jsonPacket);
  Serial.print("Send Lora JSON : ");
  Serial.print(jsonPacket);
  sendPacket(jsonPacket);

  delay(5000);
}

// =========================================================

// Initialize the LoRa module
void initializeLora(){
    Serial.println("LoRa Sender");
  // Setup the LoRa sender
  LoRa.setPins(NSS, RST, DI0);
  while (!LoRa.begin(433E6)) {
    Serial.print(".");
    delay(500);
  }  
  LoRa.setSyncWord(0xF1);
  Serial.println("LoRa Initializing Successful!");
}

// =========================================================

// Send a packet via LoRa
void sendPacket(String data){
  LoRa.beginPacket();
  LoRa.print(data);
  LoRa.endPacket();
}

// =========================================================

// Add data to the JSON Document
void pushJsonDoc(String name, float data){
  doc[name] = data;
}
