#define BLYNK_TEMPLATE_ID "TMPL3K58xya-9"
#define BLYNK_TEMPLATE_NAME "Smart parking"
#define BLYNK_AUTH_TOKEN "82rG9UJgFjEwmlfJWfeze_WorAMsqAPz"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_PN532.h>
#include <ESP32Servo.h>

char ssid[] = "sagar";
char pass[] = "123456789";

Adafruit_PN532 nfc(-1, -1);
Servo gate;

#define IR1 32
#define IR2 33
#define LED1 25
#define LED2 26
#define SERVO_PIN 13

void setup() {
  Serial.begin(115200);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  gate.attach(SERVO_PIN);
  gate.write(0);

  Wire.begin(21, 22);
  nfc.begin();

  if (!nfc.getFirmwareVersion()) {
    Serial.println("PN532 not detected!");
    while (1);
  }

  nfc.SAMConfig();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("System Ready...");
}

void loop() {
  Blynk.run();

  bool slot1Full = (digitalRead(IR1) == LOW);
  bool slot2Full = (digitalRead(IR2) == LOW);

  // LED update
  digitalWrite(LED1, slot1Full);
  digitalWrite(LED2, slot2Full);

  // Blynk LED update (make sure LED widgets use V0 and V1)
  Blynk.virtualWrite(V0, slot1Full);
  Blynk.virtualWrite(V1, slot2Full);

  // Status label (V4 must be label widget)
  if (slot1Full && slot2Full) {
    Blynk.virtualWrite(V4, "PARKING FULL");
  } else {
    Blynk.virtualWrite(V4, "SLOTS AVAILABLE");
  }

  // RFID gate control
  uint8_t uid[7];
  uint8_t uidLength;

  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {

    Serial.println("Card detected");

    if (!(slot1Full && slot2Full)) {
      Serial.println("Gate Opening");
      gate.write(90);
      delay(3000);
      gate.write(0);
    } else {
      Serial.println("Parking FULL - Gate Locked");
    }

    delay(2000);
  }
}