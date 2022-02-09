
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define WIFI_SSID "mudassir"  //WiFi SSID
#define WIFI_PASSWORD "mudassir"  //WiFi Password
#define FIREBASE_HOST "mudassir-acede.firebaseio.com"       //Firebase Project URL Remove "https:" , "\" and "/"
#define FIREBASE_AUTH "LVol5lAFrsMrrBETvhnIkeMumEtNy7Jrw8X682Xg"      //Firebase Auth Token




// Set these to run example.


void setup() {
Serial.begin(9600);
pinMode(16, OUTPUT);
// connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
//Firebase.set("LED_STATUS", "9");
}
String n;
void loop() {
// get value
n = Firebase.getString("LED");

Serial.println(n);
// handle error
if (n=="1") {
Serial.println("LED ON");
digitalWrite(16,HIGH);
//return;
}
else {
Serial.println("led off");
digitalWrite(16,LOW);
//return;
}



}
