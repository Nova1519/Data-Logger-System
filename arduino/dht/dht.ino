
#include "DHT.h"

#define DHTPIN 2     //Digital pin connected to the dht sensor


#define DHTTYPE DHT11   // DHT 11  (AM2302)


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHT final");
 
  dht.begin();
}

void loop() {
  delay(500);


  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t,h, false);

  Serial.println(t);
  Serial.println(h);

}
