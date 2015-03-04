# Arduino-Library-for-Stepper-Motor-28BYJ-48
A modified version of the official Arduino library exclusively for the stepper motor 28BYJ-48 (doesn't work with the official one)

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

  The circuits can be found at 
  http://www.arduino.cc/en/Tutorial/Stepper
