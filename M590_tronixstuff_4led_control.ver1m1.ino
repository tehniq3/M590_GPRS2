// http://tronixstuff.com/2014/01/08/tutorial-arduino-and-sim900-gsm-modules/
// base sketch: Example 55.7
// rewrite after phote by niq_ro from http://nicuflorica.blogspot.com/
// and http://arduinotehniq.blogspot.com/
// rewrite for M590 GPRS module by niq_ro - 18.08.2015, Craiova - Romania, Europe, Earth

 
#include <SoftwareSerial.h> 
char inchar; // Will hold the incoming character from the GSM shield
SoftwareSerial M590(7, 8);  // Rx, Tx
 
int led1 = 10;
int led2 = 11;
int led3 = 12;
int led4 = 13;
 
void setup()
{
 // initialize both serial ports:
 Serial.begin(9600);
//  Serial2.begin(115200);
// Serial.flush();
// Serial2.flush();
  
  //  Serial.begin(19200);
 // set up the digital pins to control
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
 
  // wake up the GSM shield
  M590.begin(9600);
//  delay(20000);  // give time to log on to network.
  delay(5000);
M590.print("AT+CMGF=1\r");  // set SMS mode to text
Serial.println("set SMS mode to txt");  // set SMS mode to text
delay(2500);

M590.print("AT+CSCS=\"GSM\"");
M590.print("\r");
delay(2500);

Serial.println("set SMS mode to txt");  // set SMS mode to text
M590.print("AT+CMGF=1\r");  // set SMS mode to text
delay(2500);

  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
Serial.println("blurt out contents of new SMS upon receipt to the GSM shield's serial out"); 
M590.print("AT+CNMI=2,2,0,0,0\r"); 
delay(2500);

  Serial.println("Ready...");
M590.println("AT+CMGD=1,4"); // delete all SMS
Serial.println("delete all SMS"); // delete all SMS
delay(2500);  
}
 
void loop() 
{
  if(M590.available() >0)
    {
//   while(Serial2.available()) Serial.write(Serial2.read());    
      
      inchar=M590.read(); 
    Serial.write(inchar);
    if (inchar=='#')
    {
      delay(10);
 
      inchar=M590.read(); 
      if (inchar=='a')
      {
        delay(10);
        
       inchar=M590.read();
        if (inchar=='0')
        {
          digitalWrite(led1, LOW);
          Serial.println("LED1 off");
        } 
        else if (inchar=='1')
        {
          digitalWrite(led1, HIGH);
          Serial.println("LED1 on");
        }
        delay(10);
        
      inchar=M590.read(); 
        if (inchar=='b')
        {
      inchar=M590.read(); 
          if (inchar=='0')
          {
            digitalWrite(led2, LOW);
            Serial.println("LED2 off");
          } 
          else if (inchar=='1')
          {
            digitalWrite(led2, HIGH);
            Serial.println("LED2 on");
          }
          delay(10);
          
      inchar=M590.read(); 
          if (inchar=='c')
          {
      inchar=M590.read(); 
            if (inchar=='0')
            {
              digitalWrite(led3, LOW);
              Serial.println("LED3 off");
            } 
            else if (inchar=='1')
            {
              digitalWrite(led3, HIGH);
              Serial.println("LED3 on");
            }
            delay(10);
           
       inchar=M590.read(); 
            if (inchar=='d')
            {
       inchar=M590.read(); 
              if (inchar=='0')
              {
                digitalWrite(led4, LOW);
                Serial.println("LED4 off");
              } 
              else if (inchar=='1')
              {
                digitalWrite(led4, HIGH);
                Serial.println("LED4 on");
              }
              delay(10);
            }
          }
            M590.println("AT+CMGD=1,4"); // delete all SMS
            Serial.println("delete all SMS"); // delete all SMS
        }
      }
    }
  }
}
