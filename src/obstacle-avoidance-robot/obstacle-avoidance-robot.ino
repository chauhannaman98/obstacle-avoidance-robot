/*  Arduino to L293D connections:
 *  Pin 4 -> Input 1
 *  Pin 5 -> Input 4
 *  Pin 6 -> Input 2
 *  Pin 7 -> Input 3 
 *  Vcc -> VCC 1, VCC2
 *  GND -> GND
 *  Enable 1,2 -> +5
 *  Enable 3,4 -> +5
 *  
 *  L293D to motors connection
 *  Output 1,2 -> Motor 1
 *  Output 2,3 -> Motor 2
 */

#define echopin  8 // echo pin
#define trigpin 9 // Trigger pin


int maximumRange = 30;
long duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
}

void loop ()
{

  {
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    
    duration=pulseIn (echopin,HIGH);
    
    distance= duration/58.2;
    delay (50);
    Serial.println(distance);
  }
  
  if (distance >= 30 ){
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay (200);
  }
  
  else if (distance >=15 && distance <= 25) {
    digitalWrite (4,HIGH);
    digitalWrite (5,LOW);
    digitalWrite (6,LOW);
    digitalWrite (7,LOW);
    delay (1000);
  }
 else if (distance < 15){
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6,HIGH);
   digitalWrite (7,HIGH);
   delay (1000);
   digitalWrite (4,LOW);
   digitalWrite (5,HIGH);
   digitalWrite (6,LOW);
   digitalWrite (7, LOW);
   delay (1000);
   
     
 }

}
