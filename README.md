<!DOCTYPE html>
<html>
<body>

<h2>Temperature and humidity data transfer with LoRa protocol</h2>

<p>
  This repository contains Arduino code for sending temperature and humidity data using the LoRa protocol and receiving and processing them in JSON format via LoRa. The project consists of two parts: a client and a server, allowing you to monitor temperature and humidity using DHT modules and communicate with LoRa modules.

 - The client part reads temperature and humidity data from a DHT sensor, packages the data in JSON format, and transmits it to the server using LoRa.

 - The server part opens the received data from the client, extracts sensor data from the JSON, and, if the data meets specific conditions (e.g., humidity above 30% and temperature above 32°C), controls a device (e.g., a fan).

<b><i>This project provides the flexibility for further customization to meet your specific needs and offers the capability to monitor and control temperature and humidity data. LoRa is used as an efficient communication protocol for data transmission.</i></b>
</p>

<h2>Table of Contents</h2>
<ul>
    <li><a href="#client">Client</a></li>
    <li><a href="#server">Server</a></li>
    <li><a href="#hardware-requirements">Hardware Requirements</a></li>
    <li><a href="#how-it-works">How it Works</a></li>
    <li><a href="#getting-started">Getting Started</a></li>
</ul>

<h2 id="client">Client Part</h2>

<h3>Overview</h3>

<p>The client part of the project reads temperature and humidity data from a DHT11 sensor and transmits it using LoRa protocol. The data is packaged in JSON format and sent to the LoRa receiver (server).</p>

<h3>Hardware Requirements</h3>

<ul>
    <li>ESP-WROOM-32</li>
    <li>LoRa module (Ra-02)</li>
    <li>DHT sensor (DHT11)</li>
</ul>

<h3>How it Works</h3>

<p>The client reads temperature and humidity data from the DHT sensor, packages it in JSON format, and sends it via LoRa to the server. The data is periodically sent in 5-second intervals.</p>

<h2 id="server">Server Part</h2>

<h3>Overview</h3>

<p>The server part of the project receives LoRa packets, extracts the JSON data, and processes it. In this example, if the humidity is above 30% and the temperature is above 32°C, a fan is turned on.</p>

<h3>Hardware Requirements</h3>

<ul>
    <li>ESP-WROOM-32</li>
    <li>LoRa module (Ra-02)</li>
    <li>Fan (or any other device to control)</li>
</ul>

<h3>How it Works</h3>

<p>The server receives LoRa packets, extracts the JSON data, and checks the humidity and temperature values. If they meet the specified conditions, it controls a fan (or other device).</p>

<h3>LoRa Module Pin Connections to ESP32</h3>


| LoRa Pin  | ESP32 Pin  | Description   |
|-----------|------------|---------------|
| ANA       | -          | Antenna       |
| GND       | GND        | Ground        |
| 3.3V      | 3.3V       | 3.3V Power    |
| DIO0      | GPIO 2     | Digital Input/Output 0 |
| RESET     | GPIO 14    | Reset         |
| NSS       | GPIO 5     | Slave Select  |
| SCK       | GPIO 18    | Serial Clock  |
| MOSI      | GPIO 23    | Master Out Slave In |
| MISO      | GPIO 19    | Master In Slave Out |

<b>Please ensure the correct wiring of these connections for your LoRa communication.</b>


<h2>Getting Started</h2>
<ol>
    <li>Clone this repository to your local machine.</li>
    <li>Set up the client and server components on separate Arduino boards.</li>
    <li>Ensure the necessary libraries (LoRa, DHT, and ArduinoJson) are installed in the Arduino IDE.</li>
    <li>Upload the client code to the client board and the server code to the server board.</li>
    <li>Connect the both boards to power supply.</li>
    <li>Monitor the serial output of the client to ensure it's sending data.</li>
    <li>Monitor the serial output of the server to check if it's receiving and processing data.</li>
</ol>

<p>You can further customize and expand upon this project to suit your needs.</p>

<p>Enjoy working with LoRa and collecting temperature and humidity data!</p>

</body>
</html>
