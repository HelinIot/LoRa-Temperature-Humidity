#include <SPI.h>
#include <LoRa.h>
#include <ArduinoJson.h>

#define NSS 4
#define RST 5
#define DI0 2
#define Fan 12

// Create a JSON document to hold the incoming data
DynamicJsonDocument doc(2048);

// Create variables to store sensor data
String LoRaData;
float h, tc, tf;

// Function prototypes
void initializeLora();
void readPacket();
void deserializePacket(String jsonPacket);
void processPacket();

// =========================================================

void setup() {
  Serial.begin(115200);
  pinMode(Fan, OUTPUT);
  
  // Initialize LoRa communication
  setupLora();
}

// =========================================================

void loop() {
  // Read and process LoRa packets
  readPacket();
  processPacket();
  delay(50);
}

// =========================================================

// Initialize LoRa communication
void setupLora(){
  Serial.println("LoRa Sender");
  LoRa.setPins(NSS, RST, DI0);
  while (!LoRa.begin(433E6)) {
    Serial.print(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF1);
  Serial.println("LoRa Initializing Successful!");
}

// =========================================================

// Read LoRa packet
void readPacket(){
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet: ");
    while (LoRa.available()) 
      LoRaData = LoRa.readString();
    Serial.println(LoRaData);
    deserializePacket(LoRaData);
  }
}

// =========================================================

// Deserialize JSON packet
void deserializePacket(String jsonPacket){
  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, jsonPacket);

  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  // Extract sensor data from JSON
  h = doc["Humidity"];
  tc = doc["Temperature_C"];
  tf = doc["Temperature_F"];
  
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature_C: ");
  Serial.println(tc);
  Serial.print("Temperature_F: ");
  Serial.println(tf);
}

// =========================================================

// Process the sensor data and control the fan
void processPacket(){
  //  packet process
  if(h > 30 && tc >32)
    digitalWrite(Fan, HIGH); // Turn on the fan
  else
    digitalWrite(Fan, LOW); // Turn off the fan
  delay(5);
}
