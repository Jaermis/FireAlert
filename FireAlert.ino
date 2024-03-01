#include <SoftwareSerial.h>
SoftwareSerial SIM800(10, 9); // gsm module connected here


const int FlameSensor = A2; // Flame Sensor
const int Buzzer = 11; // Alarm/light can be connected with this Buzzer
const int threshold=200; // sensitivity 
int flamesensevalue=0; //value to be compared for sensitivity
String textForSMS;


void setup() {

randomSeed(analogRead(0));
Serial.begin(9600);
SIM800.begin(9600); // original 19200. while enter 9600 for sim800A
Serial.println(" logging time completed!");
pinMode(FlameSensor, INPUT); 
pinMode(Buzzer, OUTPUT); 
  
}

void loop() {
flamesensevalue=analogRead(FlameSensor);
  
  if (flamesensevalue<=threshold) // 
  {
  textForSMS =  "\nFire Detected!";  
  analogWrite(Buzzer, 200); 
  sendSMS(textForSMS);
  Serial.println(textForSMS);
  Serial.println("message sent."); 
  delay(8000);
   
     SIM800.println("AT"); //Once the handshake test is successful, i t will back to OK
  updateSerial();
  
 SIM800.println("ATD+ +639053524787;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
  updateSerial();
  delay(20000); // wait for 20 seconds...
  SIM800.println("ATH"); //hang up
  updateSerial();
  }
  else
  {
  digitalWrite(Buzzer, LOW);
  delay(1000);
  }

  
}


void sendSMS(String message)
{

SIM800.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  SIM800.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  SIM800.println("AT+CMGS=\"+639453395681\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  SIM800.print("A Fire has been detected in your home at San Antonio, Kabac, Bantayan, Cebu. Please be calm and patient as the system will call the fire department within 8 seconds. Please return immediately to your house."); //text content
  updateSerial();
  SIM800.write(26);
  delay(100);                                     // give module time to send SMS


}


void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    SIM800.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(SIM800.available()) 
  {
    Serial.write(SIM800.read());//Forward what Software Serial received to Serial Port
  }
}
