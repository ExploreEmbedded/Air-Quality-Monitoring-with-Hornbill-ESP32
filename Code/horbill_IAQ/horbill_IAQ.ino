/*
 *  Indoor Air Quality v0.1 
 *  
 *  Demo sketch to log Indoor Air Quality to thingspeak.com 
 *   
 *  Temperature, humidity, TVOC and C02 are measured and logged.
 *  The data is also printed on the terminal and displayed on OLED
 * 
 *  More details visit:
 *  
 *  https://exploreembedded.com/wiki/Building_a_reliable_and_rugged_Air_Quality_Logger_with_Hornbill_ESP32_PART-1 
 *  
 */



// Libraries
 
#include <WiFi.h>
#include <Adafruit_SHT31.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "iAQ-MOD1023.h"


//Display 
#define OLED_RESET 4
#define OLED_address  0x3c
Adafruit_SSD1306 display(OLED_RESET);


//Wifi Thingspeak data logging

WiFiClient client;

//String apiKey = "things_speak_api_key";
//char ssid[20] = "your_wifi_ssid";
//char password[20] = "yourWifiPassword";

String apiKey = "YK4CWRHAS88E3E3E";
char ssid[20] = "ExploreEmbedded.com";
char password[20] = "9632083055";


const char* server = "api.thingspeak.com";


//Temperature humidity Sensor
#define SHT_ADDRESS 0x44
Adafruit_SHT31 sht31 = Adafruit_SHT31();


//Global Variables
float temperature,humidity;
unsigned int co2,tvoc;


void setup() 
{
      Serial.begin(115200);
      display.begin(SSD1306_SWITCHCAPVCC, OLED_address);  
      display.clearDisplay();
    
      display.setCursor(0,20);
      display.print("Connecting to:");
    
      display.setCursor(0,40);
      display.print(ssid);
      
        // Setup the Internet
      WiFi.begin(ssid, password);
      int pos  = 0;
      int dot = 20;
      while (WiFi.status() != WL_CONNECTED) 
      {
    
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

void loop() 
{
 
      iaqUpdate();  
      readSensors();
      updateDisplay();
      printData();
      logData();
}

//Update and print data from iAQ
void iaqUpdate() 
{
      Wire.begin();  
      iaq.readRegisters();
      co2 = iaq.getPrediction();
      tvoc = iaq.getTVOC();

}

void readSensors()
{ 
      if (! sht31.begin(SHT_ADDRESS)) 
      {   
        Serial.println("Couldn't find SHT31");
        while (1) delay(1);
      }
    
      temperature = sht31.readTemperature();
      humidity = sht31.readHumidity();
 }

void updateDisplay()
{
      display.setTextSize(1);
      display.setTextColor(WHITE);
    
      display.clearDisplay();
      display.setCursor(0,0);
      display.print(" Indoor Air Quality     ");
     
     
      display.setCursor(0,20);
      display.print("Temp     :");
      display.setCursor(70,20);
      display.print(temperature);
      display.setCursor(100,20);
      display.print(" C");
    
      display.setCursor(0,30);
      display.print("Humidity :");
      display.setCursor(70,30);
      display.println(humidity);
      display.setCursor(100,30);
      display.print(" %");
    
      
      display.setCursor(0,40);
      display.print("co2 Val :");
      display.setCursor(70,40);
      display.print(co2);
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

void logData()
{

         
      if (client.connect(server,80)) 
        {  
          String postStr = apiKey;
                 postStr +="&field1=";
                 postStr += String(temperature);
                 postStr +="&field2=";
                 postStr += String(humidity);
                 postStr +="&field3=";
                 postStr += String(co2);
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
                         
                 
          }
         
       client.stop();
       Serial.println("****Next data log after 20 seconds*****");    
         
       // thingspeak needs minimum 15 sec delay between updates
       delay(20000);    

}


//prints data to the terminal, can be removed later

void printData()
{
    
      Serial.println("****Indoor Air Quality Values******");
      
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.println(" *C "); 
    
      Serial.print("Humidity");  
      Serial.print(humidity);
      Serial.println("%");
    
      Serial.print("TVOC:");
      Serial.print(tvoc);
      Serial.println("ppb");
    
      Serial.print("Corbon Dioxide: ");
      Serial.print(co2);
      Serial.println("ppm");
}




 




