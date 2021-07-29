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
int ob = 0;


void setup() {
  Serial.begin(9600);
  pinMode(stepX, OUTPUT); //пин подает напряжение
  pinMode(dirX, OUTPUT); //пин подает напряжение
  pinMode(enPin, OUTPUT); //пин подает напряжение
  digitalWrite(enPin, HIGH); //для питания двигателя установим сигнал 0 (LOW) [чтобы питание отключить, нужно подать +5В (HIGH)]
}

// --- Функция проверки шлейфа --- //
void Check() {
  unsigned long currentMillis = millis();

  if  (currentMillis - previousMillis >= Interval) {
    previousMillis = currentMillis;
    pinMode(pin_1, OUTPUT);
    pinMode(pin_2, INPUT_PULLUP);
    pinMode(pin_3, INPUT_PULLUP);
    pinMode(pin_4, INPUT_PULLUP);
    pinMode(pin_5, INPUT_PULLUP);
    pinMode(pin_6, INPUT_PULLUP);
    digitalWrite(pin_1, LOW);

    if  (digitalRead(pin_2) || digitalRead(pin_3) || digitalRead(pin_4) || digitalRead(pin_5) || digitalRead(pin_6)) {
      Serial.println("Floop break detected");
    }
  }
}

void loop() {

  if (Serial.available() > 0) {
    String oboroti = Serial.readStringUntil('\n');
    long int N = oboroti.toInt();

    for (int i = 0; i < N; i++) {

      digitalWrite(enPin, LOW);

      digitalWrite(dirX, HIGH); //вращается ПО часовой стрелки
      //Поворачивается на 360 градусов ПРОТИВ часовой стрелки

      for (int j = 0; j < 190; j++) {
        digitalWrite(stepX, LOW);
        delay(5);
        digitalWrite(stepX, HIGH);
        Check();
      }

      digitalWrite(dirX, LOW); //вращается ПРОТИВ часовой стрелки
      //Поворачивается на 360 градусов ПО часовой стрелки

      for (int k = 0; k < 190; k++) {
        digitalWrite(stepX, HIGH);
        delay(5);
        digitalWrite(stepX, LOW);
        Check();
      }

      digitalWrite(enPin, HIGH);
      ob++;
      Serial.print("Number of revolutions: ");
      Serial.println(ob);
    }
  }
}
