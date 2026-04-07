//COMPLETE CODE OF THE SYSTEM 
//add the library 
#include <LiquidCrystal_I2C.h>
 // Define I2C address for the LCD (0x27, or change based on your setup)
LiquidCrystal_I2C lcd(0x27, 16, 2);
 // Define the pins
#define SENSOR_PIN 2 // Flame sensor connected to pin 2
#define BUZZER_PIN 9 // Buzzer connected to pin 9
#define RELAY_PIN 4 // Relay connected to pin 4
 // Variable to store previous state for LCD
String previousMessage = "";
 void setup() {
// Initialize LCD
lcd.init();
lcd.clear();
lcd.backlight();
 // Set the pin modes
 pinMode(RELAY_PIN, OUTPUT); // Relay
pinMode(SENSOR_PIN, INPUT); // Flame sensor
pinMode(BUZZER_PIN, OUTPUT); // Buzzer
 // Initially, ensure relay is off (NO contact)
digitalWrite(RELAY_PIN, HIGH); // Relay off
digitalWrite(BUZZER_PIN, LOW); // Buzzer off initially
 // Start with a message
lcd.setCursor(2, 0);
lcd.print("System Ready");
lcd.setCursor(0, 1);
lcd.print("Awaiting Flame...");
 delay(2000); // Display initial message for 2 seconds
lcd.clear();
}
 void loop() {
 int sensorValue = digitalRead(SENSOR_PIN); // Read the flame sensor value
 // Debugging output in the Serial MonitorSerial.print("Flame Sensor Value: ");
Serial.println(sensorValue);
// If flame is detected (sensor reads LOW)
if (sensorValue == LOW) {
 // Fire detected
 digitalWrite(RELAY_PIN, LOW); // Activate relay (turn on pump/sprinkler)
digitalWrite(BUZZER_PIN, HIGH); // Activate buzzer (alert the user)
 // Check if the message has changed, and only update LCD if necessary
if (previousMessage != "Fire Detected!") {
 lcd.clear(); // Clear the LCD only if the message
changes lcd.setCursor(0, 0); lcd.print("Fire
Detected!"); lcd.setCursor(0, 1);
 lcd.print("Relay and Buzzer ON");
 previousMessage = "Fire Detected!"; // Update the previous message
 } }
else {
 // No flame detected
 digitalWrite(RELAY_PIN, HIGH); // Deactivate relay (turn off pump/sprinkler)
digitalWrite(BUZZER_PIN, LOW); // Deactivate buzzer (no fire detected)
 // Check if the message has changed, and only update LCD if
necessary if (previousMessage != "Regulated Temp.") { lcd.clear();
// Clear the LCD only if the message changes lcd.setCursor(0, 0);
lcd.print("Regulated Temp."); lcd.setCursor(0, 1);
lcd.print("System Normal");
 previousMessage = "Regulated Temp."; // Update the previous message
 }
 }
 delay(50); // Small delay to avoid rapid switching and flickering of LCD text
