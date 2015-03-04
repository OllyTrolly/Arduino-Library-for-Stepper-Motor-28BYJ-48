# Arduino-Library-for-Stepper-Motor-28BYJ-48
A modified version of the official Arduino library exclusively for the stepper motor 28BYJ-48 (with the board ULN2003) as the official version doesn't work properly with this stepper motor.

Stepper library for Wiring/Arduino - Version 0.1 for Stepper Motor 28BYJ-48
  
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

  An overview of the stepper motor can be found here:
  http://42bots.com/wp-content/uploads/2014/02/28BYJ-48-Stepper-Motor.jpg
  
  Instructions for using the library can be found here (with the exception of the 2 pin methods):
  http://www.arduino.cc/en/Tutorial/Stepper
