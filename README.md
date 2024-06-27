# Weather-Station
This project is aimed at creating an accessible and user-friendly weather station. A similar weather monitoring station can be implemented to monitor environmental changes by analysing the data received from sensor nodes deployed in landslide prone areas. It is designed for an ESP32 microcontroller to perform four main functions: connect to a WiFi network, receive data from sensor nodes, communicate with an MQTT server, and host a web server which can be accessible to users through a web browser. 


# ESP32 Weather Station with MQTT and Web Server

This project demonstrates how to create an ESP32-based weather station.

A similar weather monitoring station can be implemented to monitor environmental changes by analysing the data received from sensor nodes deployed in landslide prone areas.  

## Features
- Connects to a WiFi network.
- Publishes sensor node data to an MQTT broker.
- Hosts a web server to display the ensor data. (In this case, Internal-temperature for demonstration purpose)

## Requirements
- ESP32 board
- Arduino IDE
- WiFi network credentials
- MQTT broker (e.g., test.mosquitto.org)

## Libraries Used
- WiFi.h
- PubSubClient.h
- ESPAsyncWebServer.h

## Hardware Required
- ESP32 development board
- USB cable for programming and power
- WiFi network

## Installation
1. Clone this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Update the `ssid` and `password` variables with your WiFi network credentials.
4. Install the required libraries (`PubSubClient` and `ESPAsyncWebServer`) through the Arduino Library Manager.
5. Connect your ESP32 to the computer via USB.
6. Select the appropriate board and port in the Arduino IDE.
7. Upload the sketch to your ESP32 while holding its boot button.

## Usage
1. Ensure your ESP32 is connected to the WiFi network.
2. Open the Serial Monitor (set baud rate to 115200).
3. The ESP32 will publish the internal temperature to the MQTT topic "weather_internal_temperature".
4. Access the web server by navigating to the ESP32's IP address in a web browser to view the internal temperature.


