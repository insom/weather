#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <SPI.h>
#include "RF24.h"

RF24 radio(7, 8);
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
byte address[] = "Aaron";

typedef struct {
  float pressure;
  float temperature;
} prestemp_t;

void setup(void) {
  Serial.begin(9600);
  Serial.println("OHAI");

  if(!bmp.begin()) {
    Serial.println("No BMP");
    while(1);
  }
  
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address);
}

void loop(void) {
  sensors_event_t event;
  float temperature;
  prestemp_t data;

  bmp.getEvent(&event);
  if (event.pressure) {
    data.pressure = event.pressure;
    bmp.getTemperature(&temperature);
    data.temperature = temperature;
    radio.enableDynamicAck();
    radio.write(&data, 8, 1);
    Serial.println("Written");
  } else {
    Serial.println("Sensor error");
  }
  delay(500);
}

