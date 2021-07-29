// --- Переменные для запуска двигателя --- //
#define stepX 2 // --- пин(выход) для вращения
#define dirX  5 // --- пин(выход) для указания НАПРАВЛЕНИЯ вращения [ "-"В - против часовой; "+"В - по часовой]
#define enPin 8 // --- пин(выход) для питания драйвера A4988

// --- Переменные для проверки шлейфа --- //
#define pin_1 12 // --- SpnEn
#define pin_2 13 // --- SpnDir
#define pin_3 17 // --- CoolEn
#define pin_4 14 // --- Abort
#define pin_5 15 // --- Hold
#define pin_6 16 // --- Resume

const long Interval = 100; // --- интервал проверки шлейфа
unsigned long previousMillis = 0;  // --- храним время предыдущего срабатывания проверки
bool check = false;

void setup() {
  Serial.begin(9600);
  pinMode(stepX, OUTPUT); //пин подает напряжение
  pinMode(dirX, OUTPUT); //пин подает напряжение
  pinMode(enPin, OUTPUT); //пин подает напряжение
  digitalWrite(enPin, HIGH); //для питания двигателя установим сигнал 0 (LOW) [чтобы питание отключить, нужно подать +5В (HIGH)]
}

// --- Функция проверки шлейфа --- //
void CheckFloop() {
  unsigned long currentMillis = millis();

  if  (currentMillis - previousMillis >= Interval) {
    previousMillis = currentMillis;
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

    //if  (check == true) {
    //Serial.println("Floop break was not detected");
    //}
  }
}

void loop() {
  int ob = 0;
  if (Serial.available() > 0) {
    String oboroti = Serial.readStringUntil('\n');
    long int N = oboroti.toInt();

    for (int i = 0; i < N; i++) {

      digitalWrite(enPin, LOW);

      digitalWrite(dirX, HIGH); //вращается ПО часовой стрелки
      //Поворачивается на 360 градусов ПРОТИВ часовой стрелки

      for (int j = 0; j < 190; j++) {
        digitalWrite(stepX, LOW);
        delay(2);
        digitalWrite(stepX, HIGH);
        CheckFloop();
      }

      digitalWrite(dirX, LOW); //вращается ПРОТИВ часовой стрелки
      //Поворачивается на 360 градусов ПО часовой стрелки

      for (int k = 0; k < 190; k++) {
        digitalWrite(stepX, HIGH);
        delay(2);
        digitalWrite(stepX, LOW);
        CheckFloop();
      }

      digitalWrite(enPin, HIGH);
      ob++;
      Serial.print("Number of revolutions: ");
      Serial.println(ob);
      if  (ob == N) {
        if  (check == true) {
          Serial.println("Floop break was not detected");
        }
      }
    }
  }
}
