/*
 * DRV8833 - Library for the DRV8833 dual motor driver carrier.
 * The DRV8833 can be found here: https://www.pololu.com/product/2130
 * The DRV8833 data sheet can be found here: https://www.pololu.com/file/download/drv8833.pdf?file_id=0J534
 *
 * Library: DRV8833
 * File: DRV8833.cpp
 *
 * Defines the class for the library.
 * v1.0
 *
 * Created March 16, 2015, by Aleksandr J. Spackman.
 *
 * This code is not yet in the public domain.
 *
 */

#include "Arduino.h"
#include "DRV8833.h"

DRV8833::DRV8833()
{
	// Does nothing.
	// Use attachMotorA() and attachMotorB().
}

void DRV8833::motorAReverse()
{
	if (this->motorAAttached) // If motor A is attached...
	{
		// ...then put it in reverse.
		digitalWrite(this->a1, LOW);
		digitalWrite(this->a2, HIGH);
	}
}

void DRV8833::motorAReverse(int speed, bool decay)
{
	if (this->motorAAttached) // If motor A is attached...
	{
		if (decay == SLOW_DECAY) {
			analogWrite(this->a1, 255 - speed);
			digitalWrite(this->a2, HIGH);
		} else {
			// ...then put it in reverse.
			digitalWrite(this->a1, LOW);
			analogWrite(this->a2, speed);
		}
	}
}

void DRV8833::motorAForward()
{
	if (this->motorAAttached) // If motor A is attached...
	{
		// ...then put it in forward.
		digitalWrite(this->a1, HIGH);
		digitalWrite(this->a2, LOW);
	}
}

void DRV8833::motorAForward(int speed, bool decay)
{
	if (this->motorAAttached) // If motor A is attached...
	{
		
		if (decay == SLOW_DECAY) {
			digitalWrite(this->a1, HIGH);
			analogWrite(this->a2, 255 - speed);
		} else {
			// ...then put it in forward.
			analogWrite(this->a1, speed);
			digitalWrite(this->a2, LOW);
		}
	}
}

void DRV8833::motorAStop(bool decay)
{
	if (this->motorAAttached) // If motor A is attached...
	{
		if (decay == FAST_DECAY) {
			digitalWrite(this->a1, LOW);
			digitalWrite(this->a2, LOW);
		} else {
			// ...then stop it.
			digitalWrite(this->a1, HIGH);
			digitalWrite(this->a2, HIGH);
		}
	}
}

void DRV8833::motorBReverse()
{
	if (this->motorBAttached) // If motor B is attached...
	{
		// ...then put it in reverse.
		digitalWrite(this->b1, LOW);
		digitalWrite(this->b2, HIGH);
	}
}

void DRV8833::motorBReverse(int speed, bool decay)
{
	if (this->motorBAttached) // If motor B is attached...
	{
		if (decay == SLOW_DECAY) {
			analogWrite(this->b1, 255 - speed);
			digitalWrite(this->b2, HIGH);
		} else {
			// ...then put it in reverse.
			digitalWrite(this->b1, LOW);
			analogWrite(this->b2, speed);
		}
	}
}

void DRV8833::motorBForward()
{
	if (this->motorBAttached) // If motor B is attached...
	{
		// ...then put it in forward.
		digitalWrite(this->b1, HIGH);
		digitalWrite(this->b2, LOW);
	}
}

void DRV8833::motorBForward(int speed, bool decay)
{
	if (this->motorBAttached) // If motor B is attached...
	{
		if (decay == SLOW_DECAY) {
			digitalWrite(this->b1, HIGH);
			analogWrite(this->b2, 255 - speed);
		} else {
			// ...then put it in forward.
			analogWrite(this->b1, speed);
			digitalWrite(this->b2, LOW);
		}
	}
}

void DRV8833::motorBStop(bool decay)
{
	if (this->motorBAttached) // If motor B is attached...
	{
		if (decay == FAST_DECAY) {
			digitalWrite(this->b1, LOW);
			digitalWrite(this->b2, LOW);
		} else {
			// ...then stop it.
			digitalWrite(this->b1, HIGH);
			digitalWrite(this->b2, HIGH);
		}
	}
}

void DRV8833::attachMotorA(int a1, int a2)
{
	if (!this->motorAAttached) // If motor A is NOT attached...
	{
		// ...attach motor A to the input pins.
		pinMode(a1, OUTPUT);
		pinMode(a2, OUTPUT);
		this->a1 = a1;
		this->a2 = a2;

		// Show the motor is attached.
		this->motorAAttached = true;

		// Initialize as LOW.
		digitalWrite(this->a1, LOW);
		digitalWrite(this->a2, LOW);
	}
}

void DRV8833::attachMotorB(int b1, int b2)
{
	if (!this->motorBAttached) // If motor B is NOT attached...
	{
		// ...attach motor A to the input pins.
		pinMode(b1, OUTPUT);
		pinMode(b2, OUTPUT);
		this->b1 = b1;
		this->b2 = b2;

		// Show the motor is attached.
		this->motorBAttached = true;

		// Initialize as LOW.
		digitalWrite(this->b1, LOW);
		digitalWrite(this->b2, LOW);
	}
}
