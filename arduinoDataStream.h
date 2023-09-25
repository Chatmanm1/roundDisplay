void displayData(){

if(Serial.available()) {
    String message = Serial.readStringUntil('\n');
    Serial.println("Received: " + message);

}///end data display
  tft.setCursor(0, 0);
  tft.setTextColor(GC9A01A_WHITE);  tft.setTextSize(3);
  tft.println(message);
}