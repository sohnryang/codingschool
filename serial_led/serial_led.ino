char a = 0;

void setup() {
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        a = Serial.read();
        if (a == '1') {
            Serial.println("Turning on");
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
        } else if (a == '0') {
            Serial.println("Turning off");
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
        }
    }
}
