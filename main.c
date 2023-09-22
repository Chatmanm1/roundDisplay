#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"
//https://github.com/adafruit/Adafruit_GC9A01A
// most code taken from https://dronebotworkshop.com/gc9a01/

///wireing diagram
//https://i0.wp.com/dronebotworkshop.com/wp-content/uploads/2022/06/GC9A01-arduino-hookup.jpg?w=768&ssl=1


#define TFT_DC 9
#define TFT_CS 10 // define where to plug in.
 
// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
 
void setup() {
  Serial.begin(9600);
  Serial.println("GC9A01A Test!");

tft.fillScreen(GC9A01A_BLACK);
  yield();



}


void loop(void) {
  for(uint8_t rotation=0; rotation<4; rotation++) {
    tft.setRotation(rotation);
    testFillScreen();
    delay(1000);
  }
}
 
unsigned long testFillScreen() {
  unsigned long start = micros();
  tft.fillScreen(GC9A01A_BLACK);
  yield();
  tft.fillScreen(GC9A01A_RED);
  yield();
  tft.fillScreen(GC9A01A_GREEN);
  yield();
  tft.fillScreen(GC9A01A_BLUE);
  yield();
  tft.fillScreen(GC9A01A_BLACK);
  yield();
  tft.fillScreen(epd_bitmap_allArray[0])
  yield();
  tft.fillScreen(epd_bitmap_allArray[1])
  yield();
  tft.fillScreen(epd_bitmap_allArray[2])
  yield();
  tft.fillScreen(epd_bitmap_allArray[3])
}
