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

// --- Функция проверки шлейфа --- //
void CheckFloop() {
  unsigned long currentMillis = millis();
  if  (currentMillis - previousMillis >= Interval) {
    previousMillis = currentMillis;
    int* pins_1 = new int[6] {pin_1, pin_2, pin_3, pin_4, pin_5, pin_6};
    int box = 0;

    for (int i = 0; i < 6; i++)
    {
      pinMode(pins_1[0], OUTPUT);
      pinMode(pins_1[1], INPUT_PULLUP);
      pinMode(pins_1[2], INPUT_PULLUP);
      pinMode(pins_1[3], INPUT_PULLUP);
      pinMode(pins_1[4], INPUT_PULLUP);
      pinMode(pins_1[5], INPUT_PULLUP);
      digitalWrite(pins_1[0], LOW);
      if  (!digitalRead(pins_1[1]) && !digitalRead(pins_1[2]) && !digitalRead(pins_1[3]) && !digitalRead(pins_1[4]) && !digitalRead(pins_1[5])) {
        check = true;
      }
      else {
        Serial.println("Floop break detected");
        Serial.end();
      }
      box = pins_1[0];
      pins_1[0] = pins_1[i + 1];
      pins_1[i + 1] = box;
    }
    delete[] pins_1;
    pins_1 = nullptr;
    //if  (check == true) {
    //Serial.println("Floop break was not detected");
    //}
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(stepX, OUTPUT); //пин подает напряжение
  pinMode(dirX, OUTPUT); //пин подает напряжение
  pinMode(enPin, OUTPUT); //пин подает напряжение
  digitalWrite(enPin, HIGH); //для питания двигателя установим сигнал 0 (LOW) [чтобы питание отключить, нужно подать +5В (HIGH)]
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
