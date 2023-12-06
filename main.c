#include "SPI.h"
#include "Adafruit_GC9A01A_MOD.h"

#define TFT_DC 16
#define TFT_CS 10
#define TFT_DIN 15
#define TFT_CLK 14

int xPos = 40;
int yPos = 110;
int displayInfo = 1; 
///initialize with stuff
String memoryString = "MEM";
String cpuString = "CPU";
String weatherString = "Weath";
String teststr = ""; // for incoming serial data

Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_DIN, TFT_CLK);

void setup() {
  tft.fillScreen(GC9A01A_BLACK);
  Serial.begin(9600);
  yPos = 110;
  tft.begin();
  tft.setRotation(2);
}

void loop() {
  yPos = 110;
  displayInfo = 1;
  tft.setCursor(xPos, yPos);
  writeText();
}

void writeText() {
  tft.setTextColor(GC9A01A_WHITE);
  tft.setCursor(xPos, yPos);
  tft.setTextSize(2);

  if (Serial.available() > 0) {
    tft.fillScreen(GC9A01A_BLACK);
    teststr = Serial.readStringUntil('\n');
//check waht data received.
    if (teststr.substring(0, 1) == "C") {
      cpuString = Serial.readStringUntil('\n');
    }
    if (teststr.substring(0, 1) == "M") {
      memoryString = Serial.readStringUntil('\n');
    }
    if (teststr.substring(0, 1) == "T") {
      weatherString = Serial.readStringUntil('\n');
    }
///always write these three to the screen.
    tft.println(cpuString);
    yPos = 130;
    tft.setCursor(xPos, yPos);
    tft.println(memoryString);
    yPos = 150;
    tft.setCursor(xPos, yPos);
    tft.println(weatherString);
  }

  if (Serial.available() == 0) {
    tft.setCursor(xPos, yPos);
    tft.println(teststr);
     xPos = 45;   
     yPos = 130;
    tft.setCursor(xPos, yPos);
    tft.println("test");
     xPos = 45;
    yPos = 150;
    tft.setCursor(xPos, yPos);
    tft.println("test2");
    delay(10000);
    teststr = "HoloCube";

    tft.fillScreen(GC9A01A_BLACK);
  }
}