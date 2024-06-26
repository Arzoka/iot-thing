#include <Arduino.h>
#include <AccelStepper.h>

// Pin definitions
const int STEPPER_1_PINS[] = {2, 3, 4, 5};
const int STEPPER_2_PINS[] = {6, 7, 8, 9};
const int STEPPER_3_PINS[] = {10, 11, 12, 13};
const int BUTTON_PINS[] = {A1, A0, A2};

// Stepper settings
const int STEPS_PER_REVOLUTION = 2048;
const char *const STEPPER_MODEL = "28BYJ-48";

AccelStepper steppers[] = {
        AccelStepper(AccelStepper::FULL4WIRE, STEPPER_1_PINS[0], STEPPER_1_PINS[1], STEPPER_1_PINS[2],
                     STEPPER_1_PINS[3]),
        AccelStepper(AccelStepper::FULL4WIRE, STEPPER_2_PINS[0], STEPPER_2_PINS[1], STEPPER_2_PINS[2],
                     STEPPER_2_PINS[3]),
        AccelStepper(AccelStepper::FULL4WIRE, STEPPER_3_PINS[0], STEPPER_3_PINS[1], STEPPER_3_PINS[2],
                     STEPPER_3_PINS[3])
};

void setup() {
    Serial.begin(9600);
    Serial.println("Serial started on 9600 baud");

    for (auto &BUTTON_PIN: BUTTON_PINS) {
        pinMode(BUTTON_PIN, INPUT);
        Serial.print("Pin ");
        Serial.print(BUTTON_PIN);
        Serial.println(" set as input");
    }

    for (auto &stepper: steppers) {
        stepper.setMaxSpeed(500);
        stepper.setAcceleration(200);
        Serial.println("Stepper set up");
    }

    for (auto &stepper: steppers) {
        Serial.println(stepper.currentPosition());
        stepper.setCurrentPosition(0);
        stepper.moveTo(STEPS_PER_REVOLUTION);
        stepper.runToPosition();
        Serial.println("Stepper moved to 0");
    }

    Serial.println("Setup complete, happy playing!");
}

void loop() {
    static int lastButtonStates[3] = {LOW, LOW, LOW}; // Previous state of buttons
    int buttonStates[3];

    for (int i = 0; i < 3; i++) {
        buttonStates[i] = digitalRead(BUTTON_PINS[i]);
        Serial.println(buttonStates[i]);
        if (buttonStates[i] != lastButtonStates[i]) {
            delay(10); // Debouncing delay
            buttonStates[i] = digitalRead(BUTTON_PINS[i]);
        }
        lastButtonStates[i] = buttonStates[i];
    }

    for (int index = 0; index < 3; ++index) {
        if (buttonStates[index] == HIGH) {
            Serial.print("Button ");
            Serial.print(index);
            Serial.println(" pressed");

            // Rotate the appropriate stepper 180 degrees (512 steps)
            steppers[index].moveTo(STEPS_PER_REVOLUTION / 2);
            steppers[index].runToPosition();

            delay(1000);

            // Move back to the original position
            steppers[index].moveTo(STEPS_PER_REVOLUTION);
            steppers[index].runToPosition();

            delay(1000);
        }
    }
}
