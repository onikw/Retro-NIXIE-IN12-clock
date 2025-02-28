#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

int godz;
int min;
int rok;
int mies;
int dzien;
int p[4];
int j=0;
unsigned long OnTimer = 0;
DateTime now;

#define pushBtn 17
#define A1 3
#define B1 4
#define C1 5
#define D1 6
#define A2 7
#define B2 8
#define C2 9
#define D2 10
#define A3 11
#define B3 12
#define C3 13
#define D3 14
#define A4 15
#define B4 16
#define C4 2
#define D4 1

char A[4] = {A1, A2, A3, A4};
char B[4] = {B1, B2, B3, B4};
char C[4] = {C1, C2, C3, C4};
char D[4] = {D1, D2, D3, D4};

int zero;
int one;
int two;
int three;
int hour;
int minute;

void setup() {
  ////Serial.begin(57600);

  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(pushBtn, INPUT_PULLUP);

  for (char i = 0; i < 4; i++)
  {
    digitalWrite(A[i], HIGH);
    digitalWrite(B[i], HIGH);
    digitalWrite(C[i], HIGH);
    digitalWrite(D[i], HIGH);
  }
  Wire.begin();
  if (!rtc.begin())
  {
    //Serial.println("Nie znaleziono DS3231");
    while (1);
  }
  if (rtc.lostPower())
  {
    //Serial.println("RTC utracił zasilanie, ustawiamy czas!");
  }

}
void loop()
{

  if (!digitalRead(pushBtn))
  {
    OnTimer = millis();    //trzyma czs od którego wcisneliśmy przycisk

    while (!digitalRead(pushBtn) && millis()-OnTimer < 2000)
    {
      delay(100);
    }
    if(millis()-OnTimer >= 2000)
    {
      ustaw();
    }
    else
    {
      //Serial.println("nie ustawiam");
    }

  }
  now = rtc.now();
  hour = now.hour();
  minute = now.minute();
  //Serial.print(hour);
  //Serial.print(':');
  //Serial.print(minute);
  //Serial.print(':');
  //Serial.print(now.second(), DEC);
  //Serial.println();

  zero = (hour / 10) % 10;
  one = hour % 10;
  two =  (minute / 10) % 10;
  three = minute % 10;
  if (three==0 && now.second() < 7)
  {
    for(int i=0 ;i<10;i++)
    {
      j=i;
      if (j<9)
        j++;
      else
        j=0;
      writenumber(0, i);
      writenumber(1, i);
      writenumber(2, i);
      writenumber(3, j);
      delay(2000);
    }

  }
  writenumber(0, zero);
  writenumber(1, one);
  writenumber(2, two);
  if (three<9)
    three++;
  else
    three=0;
  writenumber(3, three);
  delay(1000);
}
void ustaw()
{
      //Serial.println("ustawiam");
      p[1]=p[2]=p[3]=p[0]=0;
      j=0;
      while (j<4)
      {
        for (int k=0;k<4;k++)
        {
          if(k!=j)
          {
          off(k);
          }
        }
        if(j==3 && p[j]==9)
          writenumber(j,0);
        else if (j==3)
          writenumber(j,p[j]+1);
        else
          writenumber(j,p[j]);
        //Serial.print(p[0]);
        //Serial.print(";");
        //Serial.print(p[1]);
        //Serial.print(";");
        //Serial.print(p[2]);
        //Serial.print(";");
        //Serial.print(p[3]);
        //Serial.println(); // Dodaje nową linię na końcu

        if (!digitalRead(pushBtn))
        {
          OnTimer = millis();    //trzyma czs od którego wcisneliśmy przycisk
          while (!digitalRead(pushBtn) && millis()-OnTimer < 2000)
          {
            delay(100);
          }
          delay(100);
          if(millis()-OnTimer >= 2000)
          {

            j++;

          }
          else
          {
            if (p[j]<9)
              p[j]++;
            else
              p[j]=0;
          }
          delay(100);
        }
        delay(200);

      }
      now = rtc.now();
      godz=p[0]*10+p[1];
      min=p[2]*10+p[3];
      rok=now.year();
      mies=now.month();
      dzien=now.day();
      if (godz>23 || min> 59)
      {
      }
      else
      {
      rtc.adjust(DateTime(rok, mies, dzien, godz, min, 0));
      }


}
void writenumber(int a, int b) {
  switch (b) {
    case 1:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 2:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 3:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 4:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 5:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 6:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 7:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 8:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 9:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], HIGH);
      break;
    case 0:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], HIGH);
      break;
  }
}

void off(int a) {
  digitalWrite(A[a], HIGH);
  digitalWrite(B[a], HIGH);
  digitalWrite(C[a], HIGH);
  digitalWrite(D[a], HIGH);
}
