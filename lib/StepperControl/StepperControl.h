// lib/StepperControl/StepperControl.h
#ifndef STEPPER_CONTROL_H
#define STEPPER_CONTROL_H

#include <Arduino.h>
#include <Stepper.h>

// Function Declaration
void rotateTarget(int targetNumber);

extern const int NUM_STEPPERS;
extern const int STEPS_PER_REVOLUTION;
extern const int SECOND_ROTATE_COOLDOWN;

#endif // STEPPER_CONTROL_H
