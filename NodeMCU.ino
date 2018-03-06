#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <SoftwareSerial.h>

//NodeMCU Pin Mappings

const char* token = "3c73f3490da646b9a55bca46d0bc24cb";

const char *ssid =  "iPhone";     // replace with your wifi ssid and wpa2 key
const char *pass =  "mj123456";

//GPS Module 
float lati = 17.381901, lon = 78.560739;
//SoftwareSerial ss(0,1);
//TinyGPS tinygps;

void setup() 
{
       Serial.begin(115200);
       Blynk.begin(token,ssid,pass);
       pinMode(2,OUTPUT);
       delay(10);
               
       Serial.println("Connecting to ");
       delay(50);
       Serial.println(ssid); 
       delay(50); 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(1000);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
}


void loop() {
  
        Blynk.run();
        //mymap.location(1,lati,lon,"Bike");
        //delay(1000);
}
