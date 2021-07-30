#define pin_1 12 // --- SpnEn
#define pin_2 13 // --- SpnDir
#define pin_3 17 // --- CoolEn
#define pin_4 14 // --- Abort
#define pin_5 15 // --- Hold
#define pin_6 16 // --- Resume

int* pins_1 = new int[6] {pin_1, pin_2, pin_3, pin_4, pin_5, pin_6};
int* pins_2 = new int[6] {pin_1, pin_2, pin_3, pin_4, pin_5, pin_6};

bool check = false;
void setup()
{
  Serial.begin(9600);
}

void CheckIt(int * pins_1, int * pins_2)
{
  int box1 = 0;
  int box2 = 0;
  for (int i = 0; i < 6; i++)
  {
    pinMode(pins_1[0], OUTPUT);
    pinMode(pins_1[1], INPUT);
    pinMode(pins_1[2], INPUT);
    pinMode(pins_1[3], INPUT);
    pinMode(pins_1[4], INPUT);
    pinMode(pins_1[5], INPUT);
    digitalWrite(pins_1[0], HIGH);
    digitalWrite(pins_1[1], LOW);
    digitalWrite(pins_1[2], LOW);
    digitalWrite(pins_1[3], LOW);
    digitalWrite(pins_1[4], LOW);
    digitalWrite(pins_1[5], LOW);
    if  (digitalRead(pins_1[1]) && digitalRead(pins_1[2]) && digitalRead(pins_1[3]) && digitalRead(pins_1[4]) && digitalRead(pins_1[5])) {
      check = true;
    }
    else {
      Serial.println("Floop break detected");
      Serial.end();
    }
    box1 = pins_1[0];
    pins_1[0] = pins_1[i + 1];
    pins_1[i + 1] = box1;
  }
  for (int j = 0; j < 6; j++)
  {
    pinMode(pins_2[0], OUTPUT);
    pinMode(pins_2[1], INPUT_PULLUP);
    pinMode(pins_2[2], INPUT_PULLUP);
    pinMode(pins_2[3], INPUT_PULLUP);
    pinMode(pins_2[4], INPUT_PULLUP);
    pinMode(pins_2[5], INPUT_PULLUP);
    digitalWrite(pins_2[0], LOW);
    if  (!digitalRead(pins_2[1]) && !digitalRead(pins_2[2]) && !digitalRead(pins_2[3]) && !digitalRead(pins_2[4]) && !digitalRead(pins_2[5])) {
      check = true;
    }
    else {
      Serial.println("Floop break detected");
      Serial.end();
    }
    box2 = pins_2[0];
    pins_2[0] = pins_2[j + 1];
    pins_2[j + 1] = box2;
  }
}

void loop()
{
  CheckIt(pins_1, pins_2);
  if  (check == true) {
    Serial.println("Floop break was not detected");
    Serial.end();
  }
}
