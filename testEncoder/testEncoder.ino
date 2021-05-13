int motor1pin1 = 7;
int motor1pin2 = 9;
int motor2pin1 = 8;
int motor2pin2 = 10;
int en_L = 12;
int en_R = 13;
int encoder_L = 2;
int encoder_R = 3;
volatile unsigned int pulses_L = 0;
volatile unsigned int pulses_R = 0;

void countL() {
  // This function is called by the interrupt
  pulses_L++;
}

void countR() {
  // This function is called by the interrupt
  pulses_R++;
}

void setup() {
  // put your setup code h18ere, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);;
  pinMode(en_L, OUTPUT);
  pinMode(en_R, OUTPUT);
  pinMode(encoder_L, INPUT);
  pinMode(encoder_R, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(3), countL, RISING); //count the rising pulse
  attachInterrupt(digitalPinToInterrupt(2), countR, RISING); //count the rising pulse
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(12, 0); //ENA pin
  analogWrite(13, 100); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  Serial.print("Motor L:");
  Serial.println(pulses_L);
  Serial.print("Motor R:");
  Serial.println(pulses_R);
  delay(1000);


}
