#include <Servo.h>

int a1[] = { 1, 3,5,  2, 4 };
int a2[] = { 2,5,  1, 3, 4 };
int a3[] = { 4, 1, 3,5 , 2 };
int a4[] = { 1, 2, 3, 4,5};
int a5[] = { 3,5,  2, 4, 1 };

int a6[] = { 5, 3, 1, 4, 2 };
int a7[] = { 2, 4, 5, 1, 3 };
int a8[] = { 3, 1, 4, 2, 5 };
int a9[] = { 5, 2, 3, 1, 4 };
int a10[] = { 4, 3, 2, 5, 1 };

int a11[] = { 1, 5, 4, 3, 2 };
int a12[] = { 3, 2, 1, 5, 4 };
int a13[] = { 2, 1, 5, 4, 3 };
int a14[] = { 4, 5, 3, 2, 1 };
int a15[] = { 5, 4, 2, 1, 3 };


int buttonPin = 2;

Servo s1, s2, s3, s4, s5, s6;

void setup() {
    Serial.begin(9600); // Initialize serial monitor
    s1.attach(9);
    s2.attach(10);
    s3.attach(11);
    s4.attach(5);
    s5.attach(3);
    s6.attach(6);
    pinMode(buttonPin, INPUT);
}

void loop() {
    s1.write(1);
    s2.write(1);
    s3.write(1);
    s4.write(1);
    s5.write(1);
    s6.write(1);
    delay(400);

    int power = digitalRead(buttonPin);
    if (power == LOW) {
        Serial.println("ok");

        int num = random(1, 15); 
        int *sequence;

        switch (num) {
            case 1: sequence = a1; break;
            case 2: sequence = a2; break;
            case 3: sequence = a3; break;
            case 4: sequence = a4; break;
            case 5: sequence = a5; break;
            case 6: sequence = a6; break;
            case 7: sequence = a7; break;
            case 8: sequence = a8; break;
            case 9: sequence = a9; break;
            case 10: sequence = a10; break;
            case 11: sequence = a11; break;
            case 12: sequence = a12; break;
            case 13: sequence = a13; break;
            case 14: sequence = a14; break;
           
            default: return;
        }

        for (int i = 0; i < 5; i++) {
            int servoNum = sequence[i];

            Servo* servos[] = { &s1, &s2, &s3, &s4, &s5};
            servos[servoNum - 1]->write(180);
            delay(200);
            servos[servoNum - 1]->write(1);
            delay(1000);
        }

        delay(1000);
}
}