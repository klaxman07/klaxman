
#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "SmartDoorLock"
#define BLYNK_AUTH_TOKEN "YourBlynkAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

char auth[] = BLYNK_AUTH_TOKEN;

#define RELAY_PIN 5 

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); 

  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(RELAY_PIN, HIGH); // Unlock
    Serial.println("Door Unlocked");
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Lock
    Serial.println("Door Locked");
  }
}

void loop() {
  Blynk.run();
}
