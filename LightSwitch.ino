char val; // variable to receive data from the serial port
char preval;
int pin = 13;
int LED = 12;

#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(pin);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);       // start serial communication at 9600bps
  lightsOn();
  delay(1000);
  lightsOff(); 
}

void loop() {
  if( Serial.available() )       // if data is available to read
  {
    val = Serial.read();         // read it and store it in 'val'
  }
  
  if (( val == '1' ) && (preval != val) ){
    lightsOn();
    preval = val;
    digitalWrite(LED, HIGH);
  } else if(( val == '0' ) && (preval != val) ) {
    lightsOff();
    
    preval = val;
    digitalWrite(LED, LOW);
  } 
  
  delay(100);                   // wait 100ms for next reading
}

void lightsOn() {
    myservo.write(7);              // tell servo to go to position in variable 'pos'
}

void lightsOff() {
    myservo.write(30);              // tell servo to go to position in variable 'pos'
}

