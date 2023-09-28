# Temperature and Humidity Data Transfer with LoRa Protocol

This repository contains Arduino code for sending temperature and humidity data using the LoRa protocol and receiving and processing them in JSON format via LoRa. The project consists of two parts: a client and a server, allowing you to monitor temperature and humidity using DHT modules and communicate with LoRa modules.

- The client part reads temperature and humidity data from a DHT sensor, packages the data in JSON format, and transmits it to the server using LoRa.

- The server part opens the received data from the client, extracts sensor data from the JSON, and, if the data meets specific conditions (e.g., humidity above 30% and temperature above 32°C), controls a device (e.g., a fan).

**This project provides the flexibility for further customization to meet your specific needs and offers the capability to monitor and control temperature and humidity data. LoRa is used as an efficient communication protocol for data transmission.**

## Table of Contents
- [Client](#client)
- [Server](#server)
- [Hardware Requirements](#hardware-requirements)
- [How it Works](#how-it-works)
- [Getting Started](#getting-started)

## Client Part

## Overview

The client part of the project reads temperature and humidity data from a DHT11 sensor and transmits it using LoRa protocol. The data is packaged in JSON format and sent to the LoRa receiver (server).

## Hardware Requirements

- ESP-WROOM-32
- LoRa module (Ra-02)
- DHT sensor (DHT11)

## How it Works

The client reads temperature and humidity data from the DHT sensor, packages it in JSON format, and sends it via LoRa to the server. The data is periodically sent in 5-second intervals.

## Server Part

## Overview

The server part of the project receives LoRa packets, extracts the JSON data, and processes it. In this example, if the humidity is above 30% and the temperature is above 32°C, a fan is turned on.

## Hardware Requirements

- ESP-WROOM-32
- LoRa module (Ra-02)
- Fan (or any other device to control)

### How it Works

The server receives LoRa packets, extracts the JSON data, and checks the humidity and temperature values. If they meet the specified conditions, it controls a fan (or other device).

## LoRa Module Pin Connections to ESP32

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

**Please ensure the correct wiring of these connections for your LoRa communication.**

## Getting Started

1. Clone this repository to your local machine.
2. Set up the client and server components on separate Arduino boards.
3. Ensure the necessary libraries (LoRa, DHT, and ArduinoJson) are installed in the Arduino IDE.
4. Upload the client code to the client board and the server code to the server board.
5. Connect both boards to a power supply.
6. Monitor the serial output of the client to ensure it's sending data.
7. Monitor the serial output of the server to check if it's receiving and processing data.

You can further customize and expand upon this project to suit your needs.

Enjoy working with LoRa and collecting temperature and humidity data!
