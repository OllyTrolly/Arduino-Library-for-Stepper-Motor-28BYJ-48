/*
  Stepper.cpp - - Stepper library for Wiring/Arduino - Version 0.1 for Stepper Motor 28BYJ-48
  
  -> Forked from official 0.4 by Tom Igoe, bug fix from Noah Shibley
  Modified specifically for motor 28BYJ-48, two-pin functionality taken out (0.1) by Oliver Stevenson

  Drives the 28BYJ-48 stepper motor using 4 wires. 

  The sequence of control signals for the 4 control wires is as follows:

  Step C0 C1 C2 C3
     1  0  0  0  1
     2  0  0  1  1
     3  0  0  1  0
     4  0  1  1  0
	 5  0  1  0  0
	 6  1  1  0  0
	 7  1  0  0  0
	 8  1  0  0  1

  The circuits can be found at 
  http://www.arduino.cc/en/Tutorial/Stepper
 */


#include "Arduino.h"
#include "Stepper.h"

/*
 *   Constructor
 *   Sets which wires should control the motor.
 */

Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{
  this->step_number = 0;      // which step the motor is on
  this->speed = 0;        // the motor speed, in revolutions per minute
  this->direction = 0;      // motor direction
  this->last_step_time = 0;    // time stamp in ms of the last step taken
  this->number_of_steps = number_of_steps;    // total number of steps for this motor
  
  // Arduino pins for the motor control connection:
  this->motor_pin_1 = motor_pin_1;
  this->motor_pin_2 = motor_pin_2;
  this->motor_pin_3 = motor_pin_3;
  this->motor_pin_4 = motor_pin_4;

  // setup the pins on the microcontroller:
  pinMode(this->motor_pin_1, OUTPUT);
  pinMode(this->motor_pin_2, OUTPUT);
  pinMode(this->motor_pin_3, OUTPUT);
  pinMode(this->motor_pin_4, OUTPUT);

  // pin_count is used by the stepMotor() method:  
  this->pin_count = 4;  
}

/*
  Sets the speed in revs per minute
*/
void Stepper::setSpeed(long whatSpeed)
{
  this->step_delay = 60L * 1000L / this->number_of_steps / whatSpeed;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative, 
   the motor moves in the reverse direction.
 */
void Stepper::step(int steps_to_move)
{  
  int steps_left = abs(steps_to_move);  // how many steps to take
  
  // determine direction based on whether steps_to_move is + or -:
  if (steps_to_move > 0) {this->direction = 1;}
  if (steps_to_move < 0) {this->direction = 0;}
    
    
  // decrement the number of steps, moving one step each time:
  while(steps_left > 0) {
  // move only if the appropriate delay has passed:
  if (millis() - this->last_step_time >= this->step_delay) {
      // get the timeStamp of when you stepped:
      this->last_step_time = millis();
      // increment or decrement the step number,
      // depending on direction:
      if (this->direction == 1) {
        this->step_number++;
        if (this->step_number == this->number_of_steps) {
          this->step_number = 0;
        }
      } 
      else { 
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor to step number 0, 1, 2, 3, 4, 5, 6 or 7:
      stepMotor(this->step_number % 8);
    }
  }
}

/*
 * Moves the motor forward or backwards.
 */
void Stepper::stepMotor(int thisStep)
{
    switch (thisStep) {
      case 0:    // 0001
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, HIGH);
		break;
      case 1:    // 0011
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, HIGH);
		digitalWrite(motor_pin_4, HIGH);
		break;
      case 2:    //0010
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, HIGH);
		digitalWrite(motor_pin_4, LOW);
		break;
      case 3:    //0110
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, HIGH);
		digitalWrite(motor_pin_3, HIGH);
		digitalWrite(motor_pin_4, LOW);
		break;
	  case 4:	//0100
		digitalWrite(motor_pin_1, LOW);
		digitalWrite(motor_pin_2, HIGH);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, LOW);
		break;
	  case 5:	//1100
		digitalWrite(motor_pin_1, HIGH);
		digitalWrite(motor_pin_2, HIGH);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, LOW);
		break;
	  case 6:	//1000
		digitalWrite(motor_pin_1, HIGH);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, LOW);
		break;
	  case 7:	//1001
		digitalWrite(motor_pin_1, HIGH);
		digitalWrite(motor_pin_2, LOW);
		digitalWrite(motor_pin_3, LOW);
		digitalWrite(motor_pin_4, HIGH);
		break;
  }
}

/*
  version() returns the version of the library:
*/
int Stepper::version(void)
{
  return 1;
}