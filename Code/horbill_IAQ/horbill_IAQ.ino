

// Communicating with  indoor air quality sensor

#include <WiFi.h>
#include <iAQ-MOD1023.h>
#include "Adafruit_SHT31.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define OLED_address  0x3c
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

String apiKey = "YK4CWRHAS88E3E3E";
char ssid[20] = "ExploreEmbedded.com";
char password[20] = "9632083055";
char TempValue[15];
String str;
const char* server = "api.thingspeak.com";


Adafruit_SHT31 sht31 = Adafruit_SHT31();

float t,h;
unsigned int  pred,tvoc;
WiFiClient client;

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();

  display.setCursor(0,20);
  display.print("Connecting to:");

  display.setCursor(0,40);
  display.print(ssid);
  
    // Setup the Internet
  WiFi.begin(ssid, password);
  int pos  = 0;
  int dot = 20;
  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    pos++;
    dot++;
    display.setCursor(dot,40);
    display.print(".");
   
  }

 // sendStrXY("connected", 5, 0);
  display.clearDisplay();
  delay(100); 
  
  
  
  }

void loop() {
  wifi_thingspeak();
  iaqUpdate();  
  readSensors();
  OLED_Display();
  
  
  
}

//Update and print data from iAQ
void iaqUpdate() {
  Wire.begin();  
  iaq.readRegisters();
  //String pred;   //= "iAQ prediction value: \t";
  pred = iaq.getPrediction();
  String ohm = "iAQ resistance value: \t";
  ohm += iaq.getResistance();
  ohm += " Ohms";
  //String tvoc = "iAQ TVOC value: \t";
  tvoc = iaq.getTVOC();
 // Serial.println("Indoor Air Quality Data");
  //Serial.print("iAQ Data Status: \t");
  //Serial.println(iaq.getStatus());
 // Serial.println(pred);
 // Serial.println(ohm);
 // Serial.println(tvoc);
  //Serial.println();
}

void readSensors(){

            //sensor init
          // Serial.println("SHT31 test");
          if (! sht31.begin(0x44)) {   // Set to 0x45 for alternate i2c addr
            Serial.println("Couldn't find SHT31");
            while (1) delay(1);
          }
  
           t = sht31.readTemperature();
           h = sht31.readHumidity();
           char tvalue[5], hvalue[5];
        
          if (! isnan(t)) {  // check if 'is not a number'
           // Serial.print("Temp *C = "); Serial.println(t);
          } else { 
            Serial.println("Failed to read temperature");
          }
          
          if (! isnan(h)) {  // check if 'is not a number'
           // Serial.print("Hum. % = "); Serial.println(h);
          } else { 
            Serial.println("Failed to read humidity");
          }
          Serial.println();
          //delay(1000); 

         //str = String(t);
         //str.toCharArray(tvalue,15); 
         //sendStrXY(tvalue,3,10);

         //str = String(h);
        // str.toCharArray(hvalue,15); 
         //sendStrXY(hvalue,4,10);

 }

void OLED_Display()

{

  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.


  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.clearDisplay();
  display.setCursor(0,0);
  display.print(" Indoor Air Quality     ");
 
 
  display.setCursor(0,20);
  display.print("Temp     :");
  display.setCursor(70,20);
  display.print(t);
  display.setCursor(100,20);
  display.print(" C");

  display.setCursor(0,30);
  display.print("Humidity :");
  display.setCursor(70,30);
  display.println(h);
   display.setCursor(100,30);
  display.print(" %");

  
  display.setCursor(0,40);
  display.print("Pred Val :");
  display.setCursor(70,40);
   display.print(pred);
    display.setCursor(100,40);
  display.print(" ppm");


  display.setCursor(0,50);
  display.print("TVOC     :");
  display.setCursor(70,50);
  display.print(tvoc);
   display.setCursor(100,50);
  display.print(" ppb");

  
  display.display();
}

void wifi_thingspeak()
{

         
  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
              String postStr = apiKey;
                     postStr +="&field1=";
                     postStr += String(t);
                     postStr +="&field2=";
                     postStr += String(h);
                     postStr +="&field3=";
                     postStr += String(pred);
                     postStr +="&field4=";
                     postStr += String(tvoc);
                     postStr += "\r\n\r\n";
           
               client.print("POST /update HTTP/1.1\n"); 
               client.print("Host: api.thingspeak.com\n"); 
               client.print("Connection: close\n"); 
               client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
               client.print("Content-Type: application/x-www-form-urlencoded\n"); 
               client.print("Content-Length: "); 
               client.print(postStr.length()); 
               client.print("\n\n"); 
               client.print(postStr);
                     
           
               Serial.print("Temperature: ");
               Serial.print(t);
               Serial.print(" degrees Celcius Humidity: "); 
               Serial.print(h);
               Serial.println("% send to Thingspeak");    
            }
            client.stop();
             
            Serial.println("Waiting...");    
            // thingspeak needs minimum 15 sec delay between updates
            delay(20000);  
     



}



