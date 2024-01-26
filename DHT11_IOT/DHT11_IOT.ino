#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPLyRzdoEYC"
#define BLYNK_DEVICE_NAME "ultrasonik"
#define BLYNK_AUTH_TOKEN "YX7PN5gWFxx0s58WmMj9Nimoru3kXEoE"
#define BLYNK_PRINT Serial

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mii";
char pass[] = "aa123456";

BlynkTimer timer;

#include "DHT.h"            // Inisiasi library DHT11
#define DHTPIN 23           // Buat variabel DHTPIN, mengarah pada pin
#define DHTTYPE DHT11       // Tentukan tipe DHT menjadi DHT11
DHT dht(DHTPIN, DHTTYPE);   // Buat objek dht

void setup() {
  Serial.begin(9600);      // Buka komunikasi serial pada baudrate 9600
  dht.begin();             // Inisiasi objek dht
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  timer.setInterval(100L, dht11);
}

void loop() {
  Blynk.run();
  timer.run();
//  
//  float hum = dht.readHumidity();      // Baca kelembapan
//  float temp = dht.readTemperature();  // Baca temperatur
//  if (isnan(hum) || isnan(temp)) {     // Cek jika sensor error
//      Serial.println("Gagal Membaca DHT sensor!");
//      return;
//  }
//  Serial.println("Humidity: " + (String)hum + " %");       // Print kelembapan (%)
//  Serial.println("Temperature: " + (String)temp + " *C");  // Print temperatur (*C)
//  delay(1000);
}

void dht11(){
  float hum = dht.readHumidity();      // Baca kelembapan
  float temp = dht.readTemperature();  // Baca temperatur
  if (isnan(hum) || isnan(temp)) {     // Cek jika sensor error
      Serial.println("Gagal Membaca DHT sensor!");
      return;
  }
  Serial.println("Humidity: " + (String)hum + " %");       // Print kelembapan (%)
  Serial.println("Temperature: " + (String)temp + " *C");  // Print temperatur (*C)
  delay(1000);

  Blynk.virtualWrite(V1, hum);
  Blynk.virtualWrite(V2, temp); 
}
