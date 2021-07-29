#define pin_1 12 // --- SpnEn
#define pin_2 13 // --- SpnDir
#define pin_3 17 // --- CoolEn
#define pin_4 14 // --- Abort
#define pin_5 15 // --- Hold
#define pin_6 16 // --- Resume
bool check = false;
void setup()
{
  Serial.begin(9600);

}

void loop()
{
  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, INPUT);
  pinMode(pin_3, INPUT);
  pinMode(pin_4, INPUT);
  pinMode(pin_5, INPUT);
  pinMode(pin_6, INPUT);
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
  digitalWrite(pin_5, LOW);
  digitalWrite(pin_6, LOW);
  if  (digitalRead(pin_2) && digitalRead(pin_3) && digitalRead(pin_4) && digitalRead(pin_5) && digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  pinMode(pin_1, INPUT);
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, INPUT);
  pinMode(pin_4, INPUT);
  pinMode(pin_5, INPUT);
  pinMode(pin_6, INPUT);
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, HIGH);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
  digitalWrite(pin_5, LOW);
  digitalWrite(pin_6, LOW);
  if  (digitalRead(pin_1) && digitalRead(pin_3) && digitalRead(pin_4) && digitalRead(pin_5) && digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  pinMode(pin_1, INPUT);
  pinMode(pin_2, INPUT);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, INPUT);
  pinMode(pin_5, INPUT);
  pinMode(pin_6, INPUT);
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, HIGH);
  digitalWrite(pin_4, LOW);
  digitalWrite(pin_5, LOW);
  digitalWrite(pin_6, LOW);
  if  (digitalRead(pin_1) && digitalRead(pin_2) && digitalRead(pin_4) && digitalRead(pin_5) && digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  pinMode(pin_1, INPUT);
  pinMode(pin_2, INPUT);
  pinMode(pin_3, INPUT);
  pinMode(pin_4, OUTPUT);
  pinMode(pin_5, INPUT);
  pinMode(pin_6, INPUT);
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, HIGH);
  digitalWrite(pin_5, LOW);
  digitalWrite(pin_6, LOW);
  if  ( digitalRead(pin_1) && digitalRead(pin_2) && digitalRead(pin_3) && digitalRead(pin_5) && digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  pinMode(pin_1, INPUT);
  pinMode(pin_2, INPUT);
  pinMode(pin_3, INPUT);
  pinMode(pin_4, INPUT);
  pinMode(pin_5, OUTPUT);
  pinMode(pin_6, INPUT);
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
  digitalWrite(pin_5, HIGH);
  digitalWrite(pin_6, LOW);
  if  (digitalRead(pin_1) && digitalRead(pin_2) && digitalRead(pin_3) && digitalRead(pin_4) && digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  pinMode(pin_1, INPUT);
  pinMode(pin_2, INPUT);
  pinMode(pin_3, INPUT);
  pinMode(pin_4, INPUT);
  pinMode(pin_5, INPUT);
  pinMode(pin_6, OUTPUT);
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
  digitalWrite(pin_5, LOW);
  digitalWrite(pin_6, HIGH);
  if  (digitalRead(pin_1) && digitalRead(pin_2) && digitalRead(pin_3) && digitalRead(pin_4) && digitalRead(pin_5)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  //==================================//

  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, INPUT_PULLUP);
  pinMode(pin_3, INPUT_PULLUP);
  pinMode(pin_4, INPUT_PULLUP);
  pinMode(pin_5, INPUT_PULLUP);
  pinMode(pin_6, INPUT_PULLUP);
  digitalWrite(pin_1, LOW);
  if  (!digitalRead(pin_2) && !digitalRead(pin_3) && !digitalRead(pin_4) && !digitalRead(pin_5) && !digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  pinMode(pin_1, INPUT_PULLUP);
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, INPUT_PULLUP);
  pinMode(pin_4, INPUT_PULLUP);
  pinMode(pin_5, INPUT_PULLUP);
  pinMode(pin_6, INPUT_PULLUP);
  digitalWrite(pin_2, LOW);
  if  (!digitalRead(pin_1) && !digitalRead(pin_3) && !digitalRead(pin_4) && !digitalRead(pin_5) && !digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }
  pinMode(pin_1, INPUT_PULLUP);
  pinMode(pin_2, INPUT_PULLUP);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, INPUT_PULLUP);
  pinMode(pin_5, INPUT_PULLUP);
  pinMode(pin_6, INPUT_PULLUP);
  digitalWrite(pin_3, LOW);
  if  (!digitalRead(pin_1) && !digitalRead(pin_2) && !digitalRead(pin_4) && !digitalRead(pin_5) && !digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }

  pinMode(pin_1, INPUT_PULLUP);
  pinMode(pin_2, INPUT_PULLUP);
  pinMode(pin_3, INPUT_PULLUP);
  pinMode(pin_4, OUTPUT);
  pinMode(pin_5, INPUT_PULLUP);
  pinMode(pin_6, INPUT_PULLUP);
  digitalWrite(pin_4, LOW);
  if  (!digitalRead(pin_1) && !digitalRead(pin_2) && !digitalRead(pin_3) && !digitalRead(pin_5) && !digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }

  pinMode(pin_1, INPUT_PULLUP);
  pinMode(pin_2, INPUT_PULLUP);
  pinMode(pin_3, INPUT_PULLUP);
  pinMode(pin_4, INPUT_PULLUP);
  pinMode(pin_5, OUTPUT);
  pinMode(pin_6, INPUT_PULLUP);
  digitalWrite(pin_5, LOW);
  if  (!digitalRead(pin_1) && !digitalRead(pin_2) && !digitalRead(pin_3) && !digitalRead(pin_4) && !digitalRead(pin_6)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }

  pinMode(pin_1, INPUT_PULLUP);
  pinMode(pin_2, INPUT_PULLUP);
  pinMode(pin_3, INPUT_PULLUP);
  pinMode(pin_4, INPUT_PULLUP);
  pinMode(pin_5, INPUT_PULLUP);
  pinMode(pin_6, OUTPUT);
  digitalWrite(pin_6, LOW);
  if  (!digitalRead(pin_1) && !digitalRead(pin_2) && !digitalRead(pin_3) && !digitalRead(pin_4) && !digitalRead(pin_5)) {
    check = true;
  }
  else {
    Serial.println("Floop break detected");
    Serial.end();
  }

  if  (check == true) {
    Serial.println("Floop break was not detected");
    Serial.end();
  }
}
