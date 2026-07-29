#include <Servo.h>

const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
const int SERVO_PIN = 9;
const int LED_PIN = 4;

Servo myServo;

long duration;
float distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(0);

  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 10) {
    myServo.write(90);
    digitalWrite(LED_PIN, HIGH);
  } else {
    myServo.write(0);
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}