
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"
 
#define TFT_DC 16
#define TFT_CS 10
#define TFT_DIN 15
#define TFT_CLK 14

int timer;
int xPos = 100;
int yPos = 100;

// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC,TFT_DIN,TFT_CLK);
 String teststr = "HoloCube";// for incoming serial data
void setup() {
  Serial.begin(9600);
  tft.fillScreen(GC9A01A_BLACK);
  Serial.println("GC9A01A Test!");
 
  tft.begin();
   tft.setRotation(0);
}
 
void loop(void) {
  int xPos = 20;
int yPos = 100;
  writeText();
  tft.setCursor(10, 120);
  tft.fillScreen(GC9A01A_BLACK);
  for (int i = teststr.length() - 1; i >= 0; i--) {
    tft.drawChar(xPos, yPos, teststr[i],GC9A01A_WHITE, GC9A01A_BLACK, 2);
    xPos += 10; // Adjust the spacing between characters if needed
    }
 
 
}
 
 


 

unsigned long writeText() {
  tft.setTextColor(GC9A01A_WHITE);
  tft.setCursor(50, 120);
  tft.setTextSize(2);
  // send data only when you receive data:
  if (Serial.available() > 0) {//reading from serial
     tft.fillScreen(GC9A01A_BLACK);
    // read the incoming byte:
      teststr = Serial.readString();
    // say what you got:
        for (int i = teststr.length() - 1; i >= 0; i--) {//write it backwards
    tft.drawChar(xPos, yPos, teststr[i],GC9A01A_WHITE, GC9A01A_BLACK, 2);
    xPos += 10; // Adjust the spacing between characters if needed
    }
   }


 

 
 
  delay(2000);
 
}




