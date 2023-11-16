


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
String memoryString  = "MEM"
String cpuString = "CPU"
string weatherString = "Weath"



// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC,TFT_DIN,TFT_CLK);
 String teststr = "";// for incoming serial data
void setup() {
  tft.fillScreen(GC9A01A_BLACK);
  Serial.begin(9600);
  
  yPos = 110;
 
 
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

    ///get new values if delimeter is respective values
    if(Serial.readString.substring(0,1) == "C"){
      cpuString = Serial.readStringUntil('\n');
    }
    if(Serial.readString.substring(0,1) == "M"){
      memoryStringString = Serial.readStringUntil('\n');
    }
    if(Serial.readString.substring(0,1) == "T"){
      weatherString = Serial.readStringUntil('\n');
    }

    tft.println(cpuString);
    yPos = 130;
    tft.println(memoryString);
    yPos = 150;
    tft.println(weatherString);
   }
   

if (Serial.available() == 0) {//reading from serial
     

  tft.println(teststr);
  delay(10000);
  
  teststr = "HoloCube";
  tft.fillScreen(GC9A01A_BLACK);
  
    // say what you got
   }
   
 

 
 

 
}
