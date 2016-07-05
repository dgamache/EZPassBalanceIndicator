/* Sketch ET156 Lab 3 Analog Input with Green Yellow Red indicators
David Gamache
Use potentiometer to enter a brightness to light an LED
6/28/16
*/
unsigned int brightness=0;
unsigned int data_in = 0;
int redLed=7;
int yellowLed=4;
int greenLed=2;

// Set up the i/o
void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

// poll the potentiometer and 
void loop()
{
  data_in = analogRead(0); // returns 0 to 1023
  Serial.print("data_in: ");
  Serial.println(data_in);
  brightness = ((float)data_in / 1023.0) * 255.0;
  // calculate the value to drive the brightness of the LED
  // Red zone is less than 200: Balance is low
  if (data_in < 200)
  {
    Serial.print("Red data_in: ");
    Serial.println(data_in);
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  // Yellow zone is less than 500 (and greater than or equal to 200
  else if (data_in < 500)
  {
    Serial.print("Yellow data_in: ");
    Serial.println(data_in);
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  // Green zone is 500 or over
   else if (data_in <= 1023)
  {
    Serial.print("Green data_in: ");
    Serial.println(data_in);
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);

  }
  delay(400);// wait before testing the pot again
}
