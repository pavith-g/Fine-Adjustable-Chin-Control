#include <AccelStepper.h>

// l = linear || r =  rotational

const int lsteps = 1500;
const int rsteps = 1500;

const int lAccel = 1000;
const int rAccel = 500;

const int lMaxSpeed = 2000;
const int rMaxSpeed = 2000;


int motorDir = 1;

// Joystick switches
// Axis 1: 6, 7 Axis 2: 8, 9
int js1 = 6;
int js2 = 7;
int js3 = 8;
int js4 = 9;


// Linear Wires
// Orange = In1
// Grey = In2
// Purple = In3
// Green = In4
AccelStepper linearStepper(AccelStepper::FULL4WIRE, 10, 11, 12, 13);

// Rotational Wires
// Purple = In1
// Brown = In2
// Grey = In3
// Black = In4
// Blue = 5V INPUT
// RED = PSU 7V ?
AccelStepper rotateStepper(AccelStepper::FULL4WIRE, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600);
  linearStepper.setMaxSpeed(lMaxSpeed);
  linearStepper.setAcceleration(lAccel);
  
  rotateStepper.setMaxSpeed(lMaxSpeed);
  rotateStepper.setAcceleration(lAccel);


  pinMode(js1, INPUT_PULLUP);
  pinMode(js2, INPUT_PULLUP);
  pinMode(js3, INPUT_PULLUP);
  pinMode(js4, INPUT_PULLUP);
}

void loop() {

  int linearAxis = digitalRead(js1) * 1 + digitalRead(js2) * -1;
  int rotAxis = digitalRead(js3) * 1 + digitalRead(js4) * -1;
  // int linearAxis = +1;
  // int rotAxis = +1;
  Serial.print(linearAxis);
  Serial.print("   ");
  Serial.println(rotAxis);

  linearStepper.setSpeed(linearAxis * lsteps);
  rotateStepper.setSpeed(rotAxis * rsteps);

  linearStepper.run();
  rotateStepper.run();
}