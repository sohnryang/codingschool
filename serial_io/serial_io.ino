char a = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        a = Serial.read();
        Serial.println(a);
    } else {
        Serial.println("No input");
    }
}
