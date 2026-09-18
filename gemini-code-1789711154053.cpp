#define BLYNK_TEMPLATE_ID "TMPL66OtYh4_W"
#define BLYNK_TEMPLATE_NAME "yic2024"
#define BLYNK_AUTH_TOKEN "yPBGO62B8G1OJiFXkbRp_JSmTgENA03I"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

int sensorPin = 34;
int sensorValue = 0;
WidgetLED led(V1);

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  Blynk.virtualWrite(V0, sensorValue);

  if (sensorValue > 700) {
    led.on();
    Serial.println("Smoke/Vape detected!");
    delay(5000);
  } else {
    led.off();
  }

  Blynk.run();
  delay(200); // Wait for a second
}