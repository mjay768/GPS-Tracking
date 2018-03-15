#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TinyGPS.h>

#include <SoftwareSerial.h>

//NodeMCU Pin Mappings
const char* token = "3c73f3490da646b9a55bca46d0bc24cb";

const char *ssid =  "REDDY";     // replace with your wifi ssid and wpa2 key
const char *pass =  "sneha2668";

String latitude;
String longitude;
//GPS Module 
float lati = 17.419583, lon = 78.656013;
SoftwareSerial gpsSerial(1,2);
TinyGPS gps;
WidgetMap mymap(V0);
void setup() 
{
       Serial.begin(115200);
       delay(50);
       gpsSerial.begin(115200);
       delay(50);
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
      delay(50);

      if(gpsSerial.available())  
          Serial.println("The GPS Received Signal:");
}


void loop() {
  
      Blynk.run();

      while(gpsSerial.available()){ // check for gps data 
          if(gps.encode(gpsSerial.read()))// encode gps data 
          {  
              gps.f_get_position(&lati,&lon); // get latitude and longitude 
  
          }
   
        }
      mymap.location(1,lati,lon,"Bike");
      Blynk.virtualWrite(V1,lati);
      Blynk.virtualWrite(V2,lon);
      delay(1000);

      latitude = String(lati,6); 
      longitude = String(lon,6); 
      Serial.println(latitude+" "+longitude); 
      delay(5000);

      


}

void notifyWhenButtonPressed(){

  int isbuttonpressed = !digitalRead(3);
  if(isbuttonpressed){
    Serial.println("Notification Sent!");

    Blynk.notify("In emergency, Please call me!");
    String message = String("Your Device is offline, Last seen location is: "+latitude+" "+longitude);
    Blynk.email("manoj_ponagandla@hotmail.com","GPS Device Status Changed",message);
  }
}
