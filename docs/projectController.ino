const int B = 7;     // the number of the button pin
const int CL = 6;    // the number of the button pin
const int CU = 5;    // the number of the button pin
const int CR = 4;    // the number of the button pin
const int CD = 3;    // the number of the button pin
const int A = 2;     // the number of the button pin
const int ST = 10;   // the number of the button pin
const int SEL = 11;  // the number of the button pin
int AV = 0;          // the number of the analog pin
int AH = 2;          // the number of the analog pin

void setup() 
{
  // used for escape key
  pinMode(8,INPUT);
  digitalWrite(8,HIGH);
  // used for return key
  pinMode(12,INPUT);
  digitalWrite(12,HIGH);
  // used with a jumper wire to toggle keyboard on and off
  // in place to prevent Arduino Micro from only being recognized
  // as keyboard, which would make uploading new sketch difficult.
  pinMode(13,INPUT);
  digitalWrite(13,HIGH);
  Keyboard.begin();
}

void loop() 
{
  while(digitalRead(13))// while jumper wire is removed
  {
    // jumper wire setup similar to pin 13
    if(digitalRead(8))
    {
      Keyboard.press(KEY_ESC);
      Keyboard.release(KEY_ESC);
      delay(500); // prevent escape key spamming
    }
    // jumper wire setup similar to pin 13
    if(digitalRead(12))
    {
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);
      delay(500); // prevent return key spamming
    }
    
    // KEYPRESS
    // check if any buttons have been pressed
    // if they have press a key on keyboard
    if(digitalRead(B) == HIGH)
    {
      Keyboard.press('n');
    }
    if(digitalRead(CL) == HIGH)
    {
      Keyboard.press('j');
    }
    if(digitalRead(CU) == HIGH)
    {
      Keyboard.press('i');
    }
    if(digitalRead(CR) == HIGH)
    {
      Keyboard.press('l');
    }
    if(digitalRead(CD) == HIGH)
    {
      Keyboard.press('k');
    }
    if(digitalRead(A) == HIGH)
    {
      Keyboard.press('m');
    }
      if(digitalRead(ST) == HIGH)
    {
      Keyboard.press('f');
    }
    if(digitalRead(SEL) == HIGH)
    {
      Keyboard.press('h');
    }
    if(analogRead(AH) < 200)
    {
      Keyboard.press('a');
    }
    if(analogRead(AH) > 520)
    {
      Keyboard.press('d');
    }
    if(analogRead(AV) < 180)
    {
      Keyboard.press('w');
    }
    if(analogRead(AV) > 480)
    {
      Keyboard.press('s');
    }

    // RELEASE
    // check if any buttons have become low
    // if they have release the corresponding key
    if(digitalRead(B) == LOW)
    {
      Keyboard.release('n');
    }
    if(digitalRead(CL) == LOW)
    {
      Keyboard.release('j');
    }
    if(digitalRead(CU) == LOW)
    {
      Keyboard.release('i');
    }
    if(digitalRead(CR) == LOW)
    {
      Keyboard.release('l');
    }
    if(digitalRead(CD) == LOW)
    {
      Keyboard.release('k');
    }
    if(digitalRead(A) == LOW)
    {
      Keyboard.release('m');
    }
      if(digitalRead(ST) == LOW)
    {
      Keyboard.release('f');
    }
    if(digitalRead(SEL) == LOW)
    {
      Keyboard.release('h');
    }
    // handle vertical release in one statement
    if(analogRead(AH) > 200 && analogRead(AH) < 500)
    {
      Keyboard.release('a');
      Keyboard.release('d');
    }
    // handle horizontal release in one statement
    if(analogRead(AV) > 210 && analogRead(AV) < 470)
    {
      Keyboard.release('w');
      Keyboard.release('s');
    }
  }
  Keyboard.end();
}
