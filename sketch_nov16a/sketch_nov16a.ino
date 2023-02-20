#define BLYNK_TEMPLATE_ID           "TMPLSMilIpdm"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "w0b1Lcg02uCzV1DWTKU0V-c4ezHaCTpQ"
// for ultrasonic and servo
#include<Servo.h>
#define trigPin D4
#define echoPin D5
#define trigPin1 D6
#define echoPin1 D7
long duration;
int distance;
long duration1;
int distance1;


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "realme 7";
char pass[] = "87654321";

Servo servo;

BLYNK_WRITE(V3)
{
  servo.write(param.asInt());
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin1,OUTPUT);
  pinMode(echoPin1,INPUT);
  Serial.begin(9600);
  servo.attach(15);//d8 pin 
}

void loop()
{
  Blynk.run();
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);

  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  duration1 = pulseIn(echoPin1,HIGH);

  distance = duration*0.034/2;
  Serial.print("Distance:");
  Serial.println(distance);
  delay(10);

  distance1 = duration1*0.034/2;
  Serial.print("Distance1:");
  Serial.println(distance1);
    delay(10);
  if (distance<=20&&distance1>3)
{        
 servo.write(150);    
}
if (distance1<=3)
{   
    servo.write(0);     
 delay(10000);

}
}