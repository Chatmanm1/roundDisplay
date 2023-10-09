
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
// state machine to cycle through diaplsy
int displayInfo = 1; 


// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC,TFT_DIN,TFT_CLK);
 String teststr = "Starting value";// for incoming serial data
void setup() {
  Serial.begin(9600);
  tft.fillScreen(GC9A01A_BLACK);
  Serial.println("GC9A01A Test!");
 
  tft.begin();
   tft.setRotation(0);
}
 
void loop(void) {
  tft.setCursor(xPos, yPos);
  writeText();


   delay(5000);/// do loop ever 5 seconds.
 
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
  if(teststr.charAt(0)=='M'&& displayInfo == 1){
       tft.println(teststr);
       tft.println("Memory Usage");
       displayInfo = displayInfo +1;
  }// end if M

  if(teststr.charAt(0)=='C'&& displayInfo == 2){
       tft.println(teststr);
       tft.println("CPU Usage");
       displayInfo = displayInfo +1;
  }// end if C
  if(teststr.charAt(0)=='W'&& displayInfo == 3){
       tft.println(teststr);
       tft.println("Weather");
       displayInfo =1;
  }// end if w
    // say what you got
   }


 

 
 

 
}



//reverse writing
// for (int i = teststr.length() - 1; i >= 0; i--) {//write it backwards
//     tft.drawChar(xPos, yPos, teststr[i],GC9A01A_WHITE, GC9A01A_BLACK, 2);
//     xPos += 10; // Adjust the spacing between characters if needed
//     }