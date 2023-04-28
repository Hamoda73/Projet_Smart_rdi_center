#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define Password_Length 5

Servo myservo;
int pos = 0;

char Data[Password_Length];
char Master[Password_Length] = "0000";
byte data_count = 0, master_count = 0;

bool Pass_is_good;
bool door = false;
char customKey;
char data;


/*---preparing keypad---*/

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);


/*--- Main Action ---*/
void setup()
{
  myservo.attach(9, 2000, 2400);
  ServoClose();
  Serial.begin(9600);
}


void loop()
{
  if(Serial.available())
  {
  if (door == true)
  {
    customKey = customKeypad.getKey();
    if (customKey == '#')
    {
      ServoClose();
      delay(3000);
      door = false;
    }
  }
  }
  else
    Open();

}

void loading (char msg[]) {

  for (int i = 0; i < 3; i++) {
    delay(1000);
  }
}

void clearData()
{
  while (data_count != 0)
  { 
    Data[data_count--] = 0;
  }
  return;
}

void ServoClose()
{
  for (pos = 90; pos >= 0; pos -= 10) { 
    myservo.write(pos);
  }
}

void ServoOpen()
{
  for (pos = 0; pos <= 90; pos += 10) {
    myservo.write(pos);  
  }
}

void Open()
{ 
  customKey = customKeypad.getKey();
  if (customKey)
  {
    Data[data_count] = customKey;
    data_count++;
  }

  if (data_count == Password_Length - 1)
  {
    if (!strcmp(Data, Master))
    {
      Serial.write('0000');
      ServoOpen();
      door = true;
      loading("Waiting");
      delay(1000);
      ServoClose();
      door = false;      
    }
    else
    {
      door = false;
      Serial.write('1234');
    }
    delay(1000);
    clearData();
  }
}