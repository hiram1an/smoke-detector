# smoke-detector
Problem Statement:

In our school, there has been an increasing problem with students smoking secretly in school. This issue is particularly concerning for several reasons, including health risks, violation of school policies, and the influence it may have on other students.

Our Solution:

Install our smoke detector(SD). When the sensor detects a smoking smoke, it will light the warning led in our phone.

![hihi](Gemini_Generated_Image_9kmoaf9kmoaf9kmo.jpg)

our team:

Name: Yap Zhong Herng/Class: 1L

Name: Hiram/Class: 2s

Name: Teng Zhen Nam/Class: 2s

We had bring this project to a competition which is call the young innovators challenge 2024

In this project, we learned the importance of teamwork. The key element of working in a team of this project is Responsibility.  Each of our member has specific roles and responsibilities, contributing to the team's success. Although the work is tough, as long as we have companions to do it together, no matter how hard the task is, it will become easier.

#code

#define BLYNK_TEMPLATE_ID "TMPL66OtYh4_W"

#define BLYNK_TEMPLATE_NAME "yic2024"

#define BLYNK_AUTH_TOKEN "yPBGO62B8G1OJiFXkbRp_JSmTgENA03I"

#define BLYNK_PRINT Serial

#include <WiFi.h>

#include <WiFiClient.h>

#include <BlynkSimpleEsp32.h>



char auth[] = "yPBGO62B8G1OJiFXkbRp_JSmTgENA03I";

char ssid[] = "YourWiFiSSID";

char pass[] = "YourWiFiPassword";



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
  } 
  else {
    led.off();
  }

  
  Blynk.run();
  
  delay(200); // Wait for a second
}

