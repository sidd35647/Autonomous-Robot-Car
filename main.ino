#include<Servo.h>

Servo m;

int servopos=65;
int servopin=11;
int enableA = 3;
int MotorA1 = 8;
int MotorA2 = 9;
//Motor B
int enableB = 5;
int MotorB1 = 6;
int MotorB2 = 7;

#include <NewPing.h>
#define TRIGGER_PIN  4  // Arduino pin trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10  // Arduino pin echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup()
{
Serial.begin (9600); //configure pin modes
pinMode (enableA, OUTPUT);
pinMode (MotorA1, OUTPUT);
pinMode (MotorA2, OUTPUT);
pinMode (enableB, OUTPUT);
pinMode (MotorB1, OUTPUT);
pinMode (MotorB2, OUTPUT);
m.attach(servopin);
}

int get( ) {
  int time = sonar.ping();                  //Send out a ping and store the time it took for it to come back in the time variable
  int distance = time / US_ROUNDTRIP_CM;    //Convert that time into a distance
  //dis = sonar.ping_cm();
  if ( distance == 0 || distance == 5 ) {                //If no ping was recieved
    distance = 100;                     //Set the distance to max
  }
  delay(100);
  return distance;
}

void forward()
{
Serial.println ("Motion Forward");
digitalWrite (MotorA1, LOW);
digitalWrite (MotorA2, HIGH);
digitalWrite (MotorB1, HIGH);
digitalWrite (MotorB2, LOW);
delay (200);
}

void right()
{
Serial.println ("Motion Right");
digitalWrite (MotorA1,HIGH);
digitalWrite (MotorA2,LOW);
digitalWrite (MotorB1,HIGH);
digitalWrite (MotorB2,LOW);
delay (200);
powers_out();
}
void left()
{
Serial.println ("Motion left");
digitalWrite (MotorA1,LOW);
digitalWrite (MotorA2,HIGH);
digitalWrite (MotorB1,LOW);
digitalWrite (MotorB2,HIGH);
delay (200);
powers_out();
}

void Engines_running()
{
  //enabling motor A
//Serial.println ("Enabling Motors");
digitalWrite (enableA, 10);
digitalWrite (enableB, 9);
delay (200); //do something

}

void powers_out()
{
//Serial.println ("Stopping Motors");
//stop
digitalWrite (enableA, LOW);
digitalWrite (enableB, LOW);
delay (1000);
}
int checkright(){
  Serial.println("cheking right");
    m.write(180);
    delay(100);
    int rgt=get();
    delay(50);  
    if(rgt>30){
      Engines_running();
      return 1;
    }
    return 0;
}
int checkleft(){
    Serial.println("cheking left");
    m.write(0);
    delay(100);
    int lgt=get();
    delay(50);
    if(lgt>30){
      Engines_running();
      return 1;
    }
    return 0;
}
void loop()
{
 
  m.write(servopos);
  delay(100);
  int gt = get();
  Serial.println(gt);
  Engines_running();
  delay(50);
  if(gt > 30) forward();
  else if(gt<=30){
    powers_out();
    if(checkright()) {
      Serial.println("Right");
      right();
    }
    else if(checkleft()) {
      Serial.println("Left");
      left();
    }
  }
  else powers_out();

}



#include <Servo.h>
Servo serv;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  serv.attach(5);
  Serial.begin(9600);
  for(int i=6;i<10;i++){
      pinMode(i,OUTPUT);
  }
  serv.write(90);
  start();
}

void start()
{
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(30);
  Serial.print("Start\n");
}

void stop()
{
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(9,LOW);
  delay(50);
}

void left()
{
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(30);
}

void right()
{
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(30);
}

void back()
{
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  delay(30);
}

int pos = 0;
int trigPin=4;
int echoPin=3;
int dist=0;
int distance=0;
long duration=0;
int turnTime=1500;
int calculateDistance(){
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  // Serial.print(duration);
  distance=duration*0.034/2;
  return distance;
}
void loop() {
  start();
  delay(50);
  dist=calculateDistance();
  if(dist<20)
  {
    stop();
    delay(1000);
    // delay(1000);
    serv.write(0);
    delay(500);
    int leftDist=calculateDistance();
    delay(10);
    serv.write(180);
    delay(500);
    int rightDist=calculateDistance();
    delay(10);
    serv.write(90);
    delay(500);
   
    if(leftDist>rightDist && leftDist>=20)
    {
      left();
      delay(turnTime);
    }
    else if(rightDist>leftDist && rightDist>=20)
    {
      right();
      delay(turnTime);
    }
    else
    {
      back();
      delay(turnTime);
    }
  }
}
