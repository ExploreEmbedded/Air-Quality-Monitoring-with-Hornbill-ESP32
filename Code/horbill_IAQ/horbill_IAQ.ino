/*

Copyright (c) 2015, Embedded Adventures
All rights reserved.

Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.

*/

// Test sketch for MOD1023 
// Communicating with  indoor air quality sensor


#include <iAQ-MOD1023.h>
#include "Adafruit_SHT31.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


Adafruit_SHT31 sht31 = Adafruit_SHT31();

float t,h;
unsigned int  pred,tvoc;

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  
  }

void loop() {
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
  Serial.println(pred);
 // Serial.println(ohm);
  Serial.println(tvoc);
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
        
          if (! isnan(t)) {  // check if 'is not a number'
            Serial.print("Temp *C = "); Serial.println(t);
          } else { 
            Serial.println("Failed to read temperature");
          }
          
          if (! isnan(h)) {  // check if 'is not a number'
            Serial.print("Hum. % = "); Serial.println(h);
          } else { 
            Serial.println("Failed to read humidity");
          }
          Serial.println();
          //delay(1000); 
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

