void displayData(){

if(Serial.available()) {
    String message = Serial.readStringUntil('\n');
    Serial.println("Received: " + message);

}///end data display
}