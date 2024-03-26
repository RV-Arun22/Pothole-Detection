#include <Servo.h>
// this is the code for the vehicle
Servo myservo;
//Motor Pin Declaration Starts
int motor1pin1 = 22;
int motor1pin2 = 2;

int motor2pin1 = 3;
int motor2pin2 = 23;

int motor3pin1 = 4;
int motor3pin2 = 24;

int motor4pin1 = 25;
int motor4pin2 = 5;
//Motor pin declaration ends
//IR Pins Declaration
const int IR1 = 26;
const int IR2 = 29;
const int IR3 = 28;
int IR1Val, IR2Val, IR3Val;

// defines pins numbers
const int trigPin1 = 6;
const int echoPin1 = 7;
const int trigPin2 = 8;
const int echoPin2 = 9;
const int trigPin3 = 10;
const int echoPin3 = 11;
// defines variables
long duration1;
int distance1;
long duration2;
int distance2;
long duration3;
int distance3;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Motor Declaration
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);

  Serial.println("Motor Declartion Completed");
  //IR Declaration
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  Serial.println("IR Declaration Completed");
  myservo.attach(12);
  myservo.write(30);
  Serial.println("Initializing Servo to Zero");

  pinMode(trigPin1, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT);   // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);   // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT);   // Sets the echoPin as an Input
  Serial.println("Ultrasonic SR04 Declaration Completed");
}

void loop() {
  //start if  here

  if (Serial.available() > 0) {

    IR1Val = digitalRead(IR1);
    IR2Val = digitalRead(IR2);
    IR3Val = digitalRead(IR3);
    Serial.print("IR1 - ");
    Serial.print(IR1Val);
    Serial.print("  IR2 - ");
    Serial.print(IR2Val);
    Serial.print("  IR3 - ");
    Serial.print(IR3Val);
    Serial.println("");
    //Ultrasonic();
    if (IR1Val == 1 && IR2Val == 1 && IR3Val == 1) {
      Serial.println("Move Forward and check for potholes");

      //Ultrasonic();
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);

      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, LOW);

      digitalWrite(motor4pin1, LOW);
      digitalWrite(motor4pin2, LOW);

      analogWrite(motor1pin1, 255);
      digitalWrite(motor1pin2, LOW);

      analogWrite(motor2pin1, 255);
      digitalWrite(motor2pin2, LOW);

      analogWrite(motor3pin1, 255);
      digitalWrite(motor3pin2, LOW);

      analogWrite(motor4pin1, 255);
      digitalWrite(motor4pin2, LOW);



      delay(200);
      //Stop and check for holes
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);

      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, LOW);

      digitalWrite(motor4pin1, LOW);
      digitalWrite(motor4pin2, LOW);
      Ultrasonic();
      delay(3000);
    } else {
      Ultrasonic();
      Serial.println("Stop and check for pot holes alone");
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);

      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, LOW);

      digitalWrite(motor4pin1, LOW);
      digitalWrite(motor4pin2, LOW);
      delay(1000);
    }
  } else {
    Ultrasonic();
    Serial.println("Stop and check for pot holes alone");
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);

    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, LOW);

    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, LOW);
    delay(1000);
  }
  //Close if here
}

void Ultrasonic() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1 = duration1 * 0.034 / 2;
  // Clears the trigPin
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance2 = duration2 * 0.034 / 2;
  // Clears the trigPin
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration3 = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  distance3 = duration3 * 0.034 / 2;


  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.print("  Distance2: ");
  Serial.print(distance2);
  Serial.print("  Distance3: ");
  Serial.print(distance3);
  Serial.println();

  if (distance1 > 7) {
    ServoRight();
  } else if (distance2 > 7) {
    ServoCentre();
  } else if (distance3 > 6) {
    Servoleft();
  } else {
    Serial.println("No PotHoles");
  }
}
void ServoRight() {
  Serial.println("Rotating Servo to right and retun back to center");
  myservo.write(0);
  delay(3000);
  myservo.write(30);
}
void Servoleft() {
  Serial.println("Rotating Servo to Left and retun back to center");
  myservo.write(60);
  delay(3000);
  myservo.write(30);
}
void ServoCentre() {
  Serial.println("Stay for sometime");
  myservo.write(30);
  delay(3000);
}
