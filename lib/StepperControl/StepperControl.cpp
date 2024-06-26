// lib/StepperControl/StepperControl.cpp
#include "StepperControl.h"
#include <Arduino.h>
#include <AccelStepper.h>

// External declarations
extern AccelStepper steppers[];

// Function Definition
void rotateTarget(int targetNumber) {
    if (targetNumber < 0 || targetNumber >= NUM_STEPPERS) {
        Serial.println("Invalid target number!");
        return;
    }

    AccelStepper stepper = steppers[targetNumber];

    stepper.setMaxSpeed(100);
    stepper.setAcceleration(100);
    stepper.moveTo(STEPS_PER_REVOLUTION / 2); // Rotate 180 degrees
    delay(SECOND_ROTATE_COOLDOWN * 1000);
    stepper.moveTo(0); // Rotate back to 0 degrees
    delay(SECOND_ROTATE_COOLDOWN * 1000);
}
