// original sketch: http://shin-ajaran.blogspot.ro/2014/12/noobs-guide-to-esp8266-with-arduino.html
// rewrite after phote by niq_ro from http://nicuflorica.blogspot.com/
// and http://arduinotehniq.blogspot.com/
// and http://www.tehnic.go.ro
// rewrite for M590 GPRS module by niq_ro - 19.08.2015, Craiova - Romania, Europe, Earth


#include <SoftwareSerial.h> 
SoftwareSerial M590(7, 8);  // Rx, Tx


void setup() {
  // initialize both serial ports:
  Serial.begin(9600);

//  M590.begin(115200);
M590.begin(9600);
}

void loop() {
// while(Serial2.available()) Serial.write(Serial2.read());
 while(M590.available()) Serial.write(M590.read());
//while(Serial.available()) Serial2.write(Serial.read());
while(Serial.available()) M590.write(Serial.read());
}
