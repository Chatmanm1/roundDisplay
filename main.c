
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"
 
#define TFT_DC 7
#define TFT_CS 10
#define TFT_DIN 15
#define TFT_CLK 14

// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC,TFT_DIN,TFT_CLK);
 String teststr = "";// for incoming serial data
void setup() {
  Serial.begin(9600);
  Serial.println("GC9A01A Test!");
 
  tft.begin();
}
 
void loop(void) {
  
  writeText();
}
 
 


 

unsigned long writeText() {
  tft.setTextColor(GC9A01A_WHITE);
  tft.setCursor(30, 120);
  tft.setTextSize(3);
  // send data only when you receive data:
  if (Serial.available() > 0) {
     tft.fillScreen(GC9A01A_BLACK);
    // read the incoming byte:
      teststr = Serial.readString();
    // say what you got:
   
   }
   tft.println(teststr);
 
 
}
