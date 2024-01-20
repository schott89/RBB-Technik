/** This program tests the SD card module is working */
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

/** The clock select pin for the SD card module */
#define CS_PIN 5

void setup() {

  // Initialize the Serial (it'll tell us if the program runned correctly)
  Serial.begin(9600);
  while (!Serial) { }

  // Check the module is connected
  if (!SD.begin(CS_PIN)) {
    Serial.println("Error, SD Initialization Failed");
    return;
  }

  write();
  read();

  
}

void write() {
  File testFile = SD.open("/SDTest.txt", FILE_WRITE);
  if (testFile) {
    testFile.println("Das ist ein Test");
    testFile.close();
    Serial.println("Success, data written to SDTest.txt");
  } else {
    Serial.println("Error, couldn't not open SDTest.txt");
  }
}

void read() {
  File testFile = SD.open("/SDTest.txt", FILE_READ);
  if (testFile) {
    Serial.print("Read from file: ");
    while(testFile.available()){
        Serial.write(testFile.read());
    }
    testFile.close();
    Serial.println("Success, data read from SDTest.txt");
  } else {
    Serial.println("Error, couldn't not read SDTest.txt");
  }
}




// Do nothing, sd card operations run on setup()
void loop() {}