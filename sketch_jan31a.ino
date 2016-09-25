//**********************************************************************************************
//********************Updated CODE HERE*********************************************************
int echoPin = 3; //Ultrasonic echo and trig Pins
int trigPin = 4;

int photocellPin = A0; //For the light senseor

int LEDPin = 13; //LED

float KEY = 8.1;

const int sensorDark = 650; // Sensetiviy of light
bool playSound = false;

int note1 = 60; //C5
int note2 = 62; //D5
int note3 = 64; //E5
int note4 = 65; //F5
int note5 = 67; //G5
int note6 = 69; //A5
int note7 = 71; //B5
int note8 = 72; //C6
int note9 = 74; //D6
int note10 = 76; //E6
int note11 = 77; //F6
int note12 = 79; //G6
int note13 = 81; //A6
int note14 = 83; //B6
int note15 = 84; //C7


void setup() {
  // put your setup code here, to run once:
    // set up serial
    Serial.begin(9600);
    // set the pinmode on our ultrasonic echo, and tric pins
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);

    pinMode(LEDPin, OUTPUT);


}

void noteOn(int cmd, int pitch, int velocity)     // Function to play the notes
{
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue;
  analogValue = analogRead(photocellPin); //Reading in photocell values
  Serial.print("Light Value: ");
  Serial.println(analogValue);

  float distanceCentimeters;
  int pulseLenMicroseconds;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);

  // measure the pulse length from the echo pin
  pulseLenMicroseconds = pulseIn(echoPin, HIGH);

  // calculate the distance using the speed of sound
  distanceCentimeters = pulseLenMicroseconds / 29.387 / 2;

  // print it out over serial
  Serial.println(distanceCentimeters);

  if(analogValue < sensorDark)
  {
    playSound = true;
  }
  else
  {
    playSound = false;
  }

  if(playSound && distanceCentimeters < KEY*1)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note1, 0x7F);    // Play C5
    }
    else if(playSound && distanceCentimeters < KEY*2)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note2, 0x7F);    // Play D5
    }
    else if(playSound && distanceCentimeters < KEY*3)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note3, 0x7F);    // Play E5
    }
    else if(playSound && distanceCentimeters < KEY*4)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note4, 0x7F);    // Play F5
    }
    else if(playSound && distanceCentimeters < KEY*5)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note5, 0x7F);    // Play G5
    }
    else if(playSound && distanceCentimeters < KEY*6)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note6, 0x7F);    // Play A5
    }
    else if(playSound && distanceCentimeters < KEY*7)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note7, 0x7F);    // Play B5
    }
    else if(playSound && distanceCentimeters < KEY*8)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note8, 0x7F);    // Play C6
    }
    else if(playSound && distanceCentimeters < KEY*9)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note9, 0x7F);    // Play D6
    }
    else if(playSound && distanceCentimeters < KEY*10)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note10, 0x7F);    // Play E6
    }
    else if(playSound && distanceCentimeters < KEY*11)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note11, 0x7F);    // Play F6
    }
    else if(playSound && distanceCentimeters < KEY*12)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note12, 0x7F);    // Play G6
    }
    else if(playSound && distanceCentimeters < KEY*13)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note13, 0x7F);    // Play A6
    }
    else if(playSound && distanceCentimeters < KEY*14)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note14, 0x7F);    // Play B6
    }
    else if(playSound && distanceCentimeters < KEY*15)
    {
        digitalWrite(LEDPin, HIGH);
        noteOn(0x90, note15, 0x7F);    // Play C7
    }
    else
    {
        digitalWrite(LEDPin, LOW);
        noteOn(0x90, note1, 0x00);
        noteOn(0x90, note2, 0x00);
        noteOn(0x90, note3, 0x00);
        noteOn(0x90, note4, 0x00);
        noteOn(0x90, note5, 0x00);
        noteOn(0x90, note6, 0x00);
        noteOn(0x90, note7, 0x00);
        noteOn(0x90, note8, 0x00);
        noteOn(0x90, note9, 0x00);
        noteOn(0x90, note10, 0x00);
        noteOn(0x90, note11, 0x00);
        noteOn(0x90, note12, 0x00);
        noteOn(0x90, note13, 0x00);
        noteOn(0x90, note14, 0x00);
        noteOn(0x90, note15, 0x00);
    }

    delay(100);

}
