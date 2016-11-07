#include <SPI.h>
#include "RF24.h"

RF24 radio(7, 8);
byte address[] = "Aaron"; // Six bytes incl. NUL

typedef struct {
  float pressure;
  float temperature;
} prestemp_t;
   
void setup(void) {
  Serial.begin(9600);
  Serial.println("OHAI");

  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop(void) {
  prestemp_t data;

  if(radio.available()){
    radio.read(&data, 8);
    Serial.print("P");
    Serial.print(data.pressure);
    Serial.print("T");
    Serial.print(data.temperature);
    Serial.println("");
  }
}
