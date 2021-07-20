// Определим пины для управления и питания шагового двигателя Nema 17

const int stepX = 2; //пин(выход) для вращения
const int dirX  = 5; //пин(выход) для указания НАПРАВЛЕНИЯ вращения [ "-"В - против часовой; "+"В - по часовой]
const int enPin = 8; //пин(выход) для питания драйвера? A4988

void setup() 
{
  pinMode(stepX, OUTPUT); //пин подает напряжение
  pinMode(dirX, OUTPUT); //пин подает напряжение
  pinMode(enPin, OUTPUT); //пин подает напряжение
  digitalWrite(enPin, LOW); //для питания двигателя установим сигнал 0 (LOW) [чтобы питание отключить, нужно подать +5В (HIGH)]
}

void loop()
{
  digitalWrite(dirX, LOW); //вращается ПРОТИВ часовой стрелки
  
  //Поворачивается на 360 градусов ПРОТИВ часовой стрелки
  for(int i = 0; i < 200; i++)
  {
    digitalWrite(stepX, LOW);
    delay(100);
    digitalWrite(stepX, HIGH);
  }
  digitalWrite(dirX, HIGH); //вращается ПО часовой стрелки
  
  //Поворачивается на 360 градусов ПО часовой стрелки
  for(int k = 0; k < 200; k++)
  {
    digitalWrite(stepX, HIGH);
    delay(100);
    digitalWrite(stepX, LOW);
  }
}
