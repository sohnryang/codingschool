const int MOTOR_PINS[] = {8, 9, 10, 11};
const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
const int LED_PIN = 13;

void forward() {
    digitalWrite(MOTOR_PINS[0], HIGH);
    digitalWrite(MOTOR_PINS[1], LOW);
    digitalWrite(MOTOR_PINS[2], LOW);
    digitalWrite(MOTOR_PINS[3], HIGH);
}

void right_turn() {
    digitalWrite(MOTOR_PINS[0], HIGH);
    digitalWrite(MOTOR_PINS[1], LOW);
    digitalWrite(MOTOR_PINS[2], HIGH);
    digitalWrite(MOTOR_PINS[3], LOW);
}

void left_turn() {
    digitalWrite(MOTOR_PINS[0], LOW);
    digitalWrite(MOTOR_PINS[1], HIGH);
    digitalWrite(MOTOR_PINS[2], LOW);
    digitalWrite(MOTOR_PINS[3], HIGH);
}

void backward() {
    digitalWrite(MOTOR_PINS[0], LOW);
    digitalWrite(MOTOR_PINS[1], HIGH);
    digitalWrite(MOTOR_PINS[2], HIGH);
    digitalWrite(MOTOR_PINS[3], LOW);
}

void setup() {
    for (int i = 0; i < 4; ++i)
        pinMode(MOTOR_PINS[i], OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

long measure() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    long result = ((duration / 2.9) / 2);
    return result;
}

void loop() {
    while (measure() > 500) forward();
    digitalWrite(LED_PIN, HIGH);
    while (measure() <= 500) right_turn();
    digitalWrite(LED_PIN, LOW);
}
