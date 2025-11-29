
int red = 2;
int green= 3;
int yellow =4;
int data;

void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop()
{
  while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);
  
    if(data == 'R')
    {
      digitalWrite (red, HIGH);
      digitalWrite(green, 0);
      digitalWrite(yellow, 0);
    }
    if(data == 'G')
    {
      digitalWrite(green, 1);
      digitalWrite (red, LOW);
      digitalWrite(yellow, 0);

    }
    if(data == 'Y')
    {
      digitalWrite(green, 0);
      digitalWrite (red, LOW);
      digitalWrite(yellow, 1);

    }
    if(data == 'S')
    {
      digitalWrite(green, 0);
      digitalWrite (red, LOW);
      digitalWrite(yellow, 0);

    }
    
    
    
  }
}
