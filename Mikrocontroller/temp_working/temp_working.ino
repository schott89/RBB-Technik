#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2 // Digitaler Pin, der mit dem DHT-Sensor verbunden ist
#define DHTTYPE DHT11 // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
void setup() {
 Serial.begin(9600);
 // Gerät initialisieren.
 dht.begin();
 // Details zum Temperatursensor ausgeben.
 sensor_t sensor;
 dht.temperature().getSensor(&sensor);
 Serial.println(F("------------------------------------"));
 Serial.println(F("Temperatursensor"));
 Serial.print (F("Sensor Type: ")); Serial.println(sensor.name);
 Serial.print (F("Treiber Ver: ")); Serial.println(sensor.version);
 Serial.print (F("Einzigartige ID: ")); Serial.println
(sensor.sensor_id);
 Serial.print (F("Maximaler Wert: ")); Serial.print
(sensor.max_value); Serial.println(F("°C"));
 Serial.print (F("Minimaler Wert: ")); Serial.print
(sensor.min_value); Serial.println(F("°C"));
 Serial.print (F("Auflösung: ")); Serial.print(sensor.resolution);
Serial.println(F("°C"));
 Serial.println(F("------------------------------------"));
 // Details zum Feuchtigkeitssensor ausgeben.
 dht.humidity().getSensor(&sensor);
 Serial.println(F("Luftfeuchtigkeitssensor"));
 Serial.print (F("Sensor Type: ")); Serial.println(sensor.name);
 Serial.print (F("Treiber Ver: ")); Serial.println(sensor.version);
 Serial.print (F("Einzigartige ID: ")); Serial.println
(sensor.sensor_id);
 Serial.print (F("Maximaler Wert: ")); Serial.print
(sensor.max_value); Serial.println(F("%"));
 Serial.print (F("Minimaler Wert: ")); Serial.print
(sensor.min_value); Serial.println(F("%"));
 Serial.print (F("Auflösung: ")); Serial.print(sensor.resolution);
Serial.println(F("%"));
 Serial.println(F("------------------------------------"));
 // Stellen Sie die Verzögerung zwischen den Sensormessungen
 // anhand der Sensordetails ein.
 delayMS = sensor.min_delay / 1000;
}
void loop() {
 // Verzögerung zwischen den Messungen.
 delay(delayMS);
 // Abrufen des Temperaturereignisses und Ausgabe
 // seines Wertes.
 sensors_event_t event;
 dht.temperature().getEvent(&event);
 if (isnan(event.temperature)) {
 Serial.println(F("Fehler beim Ablesen der Temperatur!"));
 }
 else {
 Serial.print(F("Temperatur: "));
 Serial.print(event.temperature);
 Serial.println(F("°C"));
 }
 // Abrufen des Feuchtigkeitsereignisses und Ausgabe
 // seines Wertes.
 dht.humidity().getEvent(&event);
 if (isnan(event.relative_humidity)) {
 Serial.println(F("Fehler beim Ablesen der Luftfeuchtigkeit!"));
 }
 else {
 Serial.print(F("Luftfeuchtigkeit: "));
 Serial.print(event.relative_humidity);
 Serial.println(F("%"));
 }
}