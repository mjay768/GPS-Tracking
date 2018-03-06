//#include <LiquidCrystal.h> 
#include <SoftwareSerial.h> 
#include <TinyGPS.h> 
//#include <ESP8266WiFi.h>

float lati = 28.5458,lon = 77.1703; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(2,3);//rx,tx 
SoftwareSerial wifiSerial(5,6);
//LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
TinyGPS gps; // create gps object 

//const char* ssid     = "Rogue Nation";
//const char* password = "ghostProtocol";



void setup(){ 

//NodeMCU Wifi Setup 
 Serial.begin(9600);
 gpsSerial.begin(9600);// connect gps sensor 
 wifiSerial.begin(9600);

/*Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
*/
   // connect serial 
if(gpsSerial.available())  
 Serial.println("The GPS Received Signal:"); 

//lcd.begin(16,2); 
} 
void loop(){
  digitalWrite(10,HIGH);
 
  while(gpsSerial.available()){ // check for gps data 
  if(gps.encode(gpsSerial.read()))// encode gps data 
  {  
  gps.f_get_position(&lati,&lon); // get latitude and longitude 
  
 }
   
}
String latitude = String(lati,6); 
  String longitude = String(lon,6); 
Serial.println(latitude+" "+longitude); 
delay(5000); 

} 
