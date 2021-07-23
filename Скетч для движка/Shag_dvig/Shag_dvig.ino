// Определим пины для управления и питания шагового двигателя Nema 17

const int stepX = 2; //пин(выход) для вращения
const int dirX  = 5; //пин(выход) для указания НАПРАВЛЕНИЯ вращения [ "-"В - против часовой; "+"В - по часовой]
const int enPin = 8; //пин(выход) для питания драйвера? A4988
int ob = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(stepX, OUTPUT); //пин подает напряжение
  pinMode(dirX, OUTPUT); //пин подает напряжение
  pinMode(enPin, OUTPUT); //пин подает напряжение
  digitalWrite(enPin, HIGH); //для питания двигателя установим сигнал 0 (LOW) [чтобы питание отключить, нужно подать +5В (HIGH)]
}

void loop()
{
  if (Serial.available() > 0)
  {
    String oboroti = Serial.readStringUntil('\n');
    int N = oboroti.toInt();
    for (int i = 0; i < N; i++)
    {
      digitalWrite(enPin, LOW);

      digitalWrite(dirX, HIGH); //вращается ПО часовой стрелки

      //Поворачивается на 360 градусов ПРОТИВ часовой стрелки
      for (int j = 0; j < 190; j++)
      {
        digitalWrite(stepX, LOW);
        delay(5);
        digitalWrite(stepX, HIGH);
      }
      
      digitalWrite(dirX, LOW); //вращается ПРОТИВ часовой стрелки
      
      //Поворачивается на 360 градусов ПО часовой стрелки
      for (int k = 0; k < 190; k++)
      {
        digitalWrite(stepX, HIGH);
        delay(5);
        digitalWrite(stepX, LOW);
      }
      digitalWrite(enPin, HIGH);
      ob++;
      Serial.print("Number of revolutions: ");
      Serial.println(ob);
    }
  }
}
