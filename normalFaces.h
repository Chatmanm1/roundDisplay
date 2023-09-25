#define halfway 120
#define oneThird 80
#define defaultColor GC9A01A_RED

void drawEyes(){

tft.fillScreen(GC9A01A_BLACK);
tft.fillCircle(80, 80, 60, GC9A01A_RED); 
tft.fillCircle(160, 160, 60, GC9A01A_RED); 
tft.fillScreen(GC9A01A_BLACK);

}//end draw eyes

void drawEyesClosed(){
	writeLine(oneThird, halfway, halfway, halfway,defaultColor);
	writeLine(180,halfway,halfway,halfway,defaultColor)
}

void happyEyes(){
	drawChar(40, 40,n, defaultColor, GC9A01A_BLACK, 20);
	drawChar(80, 80,n, defaultColor, GC9A01A_BLACK, 20);
}