#include <RH_ASK.h>
#include <SPI.h> // Required for RH_ASK

RH_ASK driver;

// Define LED pins for the ambulance indicator
const int ambulanceRed = 6;   // Red LED
const int ambulanceGreen = 7; // Green LED
const int buttonPin = 8;      // Toggle button input

bool transmitterOn = false;  // Stores ON/OFF state
bool lastButtonState = HIGH; // Stores previous button state (for debounce)

void setup() {
  Serial.begin(9600);

  // Initialize RF Transmitter
  if (!driver.init()) {
    Serial.println("Transmitter Init Failed");
  } else {
    Serial.println("Transmitter Ready");
  }

  // Set up LED and button pins
  pinMode(ambulanceRed, OUTPUT);
  pinMode(ambulanceGreen, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor for button
}

void loop() {
  // Read button state (LOW = pressed, HIGH = not pressed)
  bool buttonState = digitalRead(buttonPin);

  // Detect button press (ignore if held)
  if (buttonState == LOW && lastButtonState == HIGH) {
    transmitterOn = !transmitterOn; // Toggle state
    Serial.println(transmitterOn ? "🚑 Transmitter ON!" : "🚦 Transmitter OFF");
    delay(200); // Simple debounce delay
  }
  lastButtonState = buttonState; // Store button state for next loop

  if (transmitterOn) {
    // Send RF signal
    const char *message = "Hello"; // Message to send
    driver.send((uint8_t *)message, strlen(message));
    driver.waitPacketSent(); // Wait for the message to be sent

    // 🚨 Flashing Ambulance LEDs 🚨
    digitalWrite(ambulanceRed, HIGH);
    digitalWrite(ambulanceGreen, LOW);
    delay(250);
    digitalWrite(ambulanceRed, LOW);
    digitalWrite(ambulanceGreen, HIGH);
    delay(250);
  } 
  else {  // If transmitter is OFF, turn OFF LEDs
    digitalWrite(ambulanceRed, LOW);
    digitalWrite(ambulanceGreen, LOW);
  }
}
