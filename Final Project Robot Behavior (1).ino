//Motor Control
//

int rightEn = 9;
int forRight = 4;
int revRight = 5;
int leftEn = 6;
int forLeft = 7;
int revLeft = 8;

int val = 0;
void setup()
{
  val = analogRead(A1);
  Serial.println(val);
  pinMode(rightEn, OUTPUT);
  pinMode(forRight, OUTPUT);
  pinMode(revRight, OUTPUT);
}

void loop()
{
  Serial.println(val);
  analogWrite (rightEn, 255);
  analogWrite (leftEn, 255);
  forward();
  delay(1000);
  rightTurn();
  delay(1000);
  Serial.println(val);
  analogWrite (rightEn, 128);
  analogWrite (leftEn, 128);
  delay(1000);
  rightTurn();
  delay(1000);
}

void rightFor(){
  digitalWrite(revRight, LOW);
  digitalWrite(forRight, HIGH);
}

void rightRev(){
  digitalWrite(forRight, LOW);
  digitalWrite(revRight, HIGH);
}
void leftFor(){
  digitalWrite(revLeft, LOW);
  digitalWrite(forLeft, HIGH);
}

void leftRev(){
  digitalWrite(forLeft, LOW);
  digitalWrite(revLeft, HIGH);
}

void forward(){
  rightFor();
  leftFor();
}

void rightTurn(){
  rightRev();
  leftFor();
}

void leftTurn(){
  rightFor();
  leftRev();
}