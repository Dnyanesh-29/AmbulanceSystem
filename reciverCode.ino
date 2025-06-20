#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RH_ASK.h>
#include <SPI.h>  // Required for RH_ASK

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize I2C LCD (address 0x27, 16 columns, 2 rows)
RH_ASK driver(2000, A0);  // Receiver pin set to A0

// Pin Definitions
const int signal3Red = 2;
const int signal3Yellow = 3;
const int signal3Green = 4;
const int signal4Red = 5;
const int signal4Yellow = 6;
const int signal4Green = 7;
const int signal1Red = 8;
const int signal1Yellow = 9;
const int signal1Green = 10;
const int signal2Red = 11;
const int signal2Yellow = 12;
const int signal2Green = 13;

// Variables
unsigned long lastSignalTime = 0;
const unsigned long overrideDuration = 5000;
bool overrideActive = false;
unsigned long lastCycleTime = 0;
const unsigned long cycleDuration = 10000;
const unsigned long yellowDuration = 2000;
int currentSignal = 1;

void setup() {
  Serial.begin(9600);

  // Pin modes for traffic signals
  pinMode(signal1Red, OUTPUT);
  pinMode(signal1Yellow, OUTPUT);
  pinMode(signal1Green, OUTPUT);
  pinMode(signal2Red, OUTPUT);
  pinMode(signal2Yellow, OUTPUT);
  pinMode(signal2Green, OUTPUT);
  pinMode(signal3Red, OUTPUT);
  pinMode(signal3Yellow, OUTPUT);
  pinMode(signal3Green, OUTPUT);
  pinMode(signal4Red, OUTPUT);
  pinMode(signal4Yellow, OUTPUT);
  pinMode(signal4Green, OUTPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Control");

  if (!driver.init()) {
    Serial.println("Receiver Init Failed");
    lcd.setCursor(0, 1);
    lcd.print("RX Failed");
  } else {
    Serial.println("Receiver Ready");
    lcd.setCursor(0, 1);
    lcd.print("RX Ready");
  }
}

void loop() {
  uint8_t buffer[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buffer);

  if (driver.recv(buffer, &buflen)) {
    Serial.println("Transmitter Signal Detected");
    lastSignalTime = millis();
    overrideActive = true;

    // Display message on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AMBULANCE");
    lcd.setCursor(0, 1);
    lcd.print("INCOMING");
  }

  if (overrideActive) {
    activateOverride(3);  // Signal 3 turns green
    if (millis() - lastSignalTime > overrideDuration) {
      overrideActive = false;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Traffic Control");
    }
  } else {
    normalTrafficCycle();
  }
}

void activateOverride(int signalNumber) {
  for (int i = 1; i <= 4; i++) {
    if (i == signalNumber) {
      setSignalState(i, true, false); // Green ON
    } else {
      setSignalState(i, false, false); // Red ON
    }
  }
}

void normalTrafficCycle() {
  if (millis() - lastCycleTime >= cycleDuration) {
    // Start yellow phase
    setSignalState(currentSignal, false, true); // Yellow ON
    delay(yellowDuration);

    // Move to next signal
    setSignalState(currentSignal, false, false); // All OFF
    currentSignal++;
    if (currentSignal > 4) currentSignal = 1;

    lastCycleTime = millis();
    setSignalState(currentSignal, true, false); // Green ON
  }
}

void setSignalState(int signalNumber, bool greenOn, bool yellowOn) {
  int redPin, yellowPin, greenPin;

  switch (signalNumber) {
    case 1:
      redPin = signal1Red;
      yellowPin = signal1Yellow;
      greenPin = signal1Green;
      break;
    case 2:
      redPin = signal2Red;
      yellowPin = signal2Yellow;
      greenPin = signal2Green;
      break;
    case 3:
      redPin = signal3Red;
      yellowPin = signal3Yellow;
      greenPin = signal3Green;
      break;
    case 4:
      redPin = signal4Red;
      yellowPin = signal4Yellow;
      greenPin = signal4Green;
      break;
  }

  digitalWrite(redPin, !greenOn && !yellowOn);   // Red ON if green and yellow are OFF
  digitalWrite(yellowPin, yellowOn);
  digitalWrite(greenPin, greenOn);
}
