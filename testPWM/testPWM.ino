int motor1pin1 = 7;
int motor1pin2 = 9;

int motor2pin1 = 8;
int motor2pin2 = 18;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(12, 100); //ENA pin
  analogWrite(13, 100); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);
  Serial.write(45); // send a byte with the value 45
  int bytesSent = Serial.write("hello");  //send the string "hello" and return the length of the string.

}
