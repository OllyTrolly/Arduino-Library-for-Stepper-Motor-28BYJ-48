/*
  Stepper.h - - Stepper library for Wiring/Arduino - Version 0.1 for Stepper Motor 28BYJ-48
  
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

// ensure this library description is only included once
#ifndef Stepper_h
#define Stepper_h

// library interface description
class Stepper {
  public:
    // constructors:
    Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void stepMotor(int this_step);
    
    int direction;        // Direction of rotation
    int speed;          // Speed in RPMs
    unsigned long step_delay;    // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int step_number;        // which step the motor is on
    
    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;
    
    long last_step_time;      // time stamp in ms of when the last step was taken
};

#endif

