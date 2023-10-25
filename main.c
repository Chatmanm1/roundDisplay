


#include "SPI.h"
#include "Adafruit_GC9A01A_MOD.h"



 
#define TFT_DC 16
#define TFT_CS 10
#define TFT_DIN 15
#define TFT_CLK 14

int timer;
int xPos = 40;
int yPos = 110;
// state machine to cycle through diaplsy
int displayInfo = 1; 


// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC,TFT_DIN,TFT_CLK);
 String teststr = "";// for incoming serial data
void setup() {
  tft.fillScreen(GC9A01A_BLACK);
  Serial.begin(9600);
  
  yPos = 130;
 
 
  tft.begin();
   tft.setRotation(2);
}
 
void loop(void) {
  yPos = 110;
  displayInfo = 1;
 
 
 
  tft.setCursor(xPos, yPos);
  writeText();



}
 
 


 

unsigned long writeText() {
  
  tft.setTextColor(GC9A01A_WHITE);
  tft.setCursor(xPos, yPos);
  tft.setTextSize(2);
  // send data only when you receive data:
if (Serial.available() > 0) {//reading from serial
     tft.fillScreen(GC9A01A_BLACK);
    // read the incoming byte:
      teststr = Serial.readStringUntil('\n');
  
    // say what you got
    tft.println(teststr);
   }
   

if (Serial.available() == 0) {//reading from serial
     

  tft.println(teststr);
  delay(10000);
  
  teststr = "HoloCube";
  tft.fillScreen(GC9A01A_BLACK);
  
    // say what you got
   }
   
 

 
 

 
}



//reverse writing
// for (int i = teststr.length() - 1; i >= 0; i--) {//write it backwards
//     tft.drawChar(xPos, yPos, teststr[i],GC9A01A_WHITE, GC9A01A_BLACK, 2);
//     xPos += 10; // Adjust the spacing between characters if needed
//     }