 #include <Servo.h>
 
 Servo twist;
 const int buttonPin = 2;
 
 const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
const int buzzerPin = 8;
const int ledPin1 = 12;
const int ledPin2 = 13;
 
int counter = 0;
 int buttonState = LOW;

void beep(int note, int duration) {
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0) {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  } else {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(50);
 
  //Increment counter
  counter++;
}
 
void setup() {
  twist.attach(4);
  twist.write(0);
  delay(2000);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    digitalWrite(ledPin2, HIGH);

    twist.write(90);
    firstSection();
    twist.write(180);
    secondSection();

    

    beep(f, 250);  
    twist.write(170);
    beep(gS, 500);  
    twist.write(160);
    beep(f, 350);  
    twist.write(140);
    beep(a, 125);
    twist.write(160);
    beep(cH, 500);
    twist.write(130);
    beep(a, 375);  
    twist.write(100);
    beep(cH, 125);
    twist.write(70);
    beep(eH, 650);

    delay(500);
   
    secondSection();
   
    //Variant 2
    beep(f, 250);  
    twist.write(70);
    beep(gS, 500);
    twist.write(45);
    beep(f, 375);  
    twist.write(125);
    beep(cH, 125);
    twist.write(140);
    beep(a, 500);  
    twist.write(50);
    beep(f, 375);  
    twist.write(140);
    beep(cH, 125);
    twist.write(135);
    beep(a, 650);  
   
    delay(650);
  } 
}

void firstSection() {
  beep(a, 500);
  twist.write(90);
  beep(a, 500);    
  twist.write(100);
  beep(a, 500);
  twist.write(120);
  beep(f, 350);
  twist.write(100);
  beep(cH, 150);  
  twist.write(150);
  beep(a, 500);
  twist.write(75);
  beep(f, 350);
  twist.write(135);
  beep(cH, 150);
  twist.write(100);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
   twist.write(120);
 beep(eH, 500);
  twist.write(150);
  beep(eH, 500);  
  twist.write(180);
  beep(fH, 350);
  twist.write(90);
  beep(cH, 150);
  twist.write(75);
  beep(gS, 500);
  twist.write(90);
  beep(f, 350);
  twist.write(30);
  beep(cH, 150);
  twist.write(175);
  beep(a, 650);
 
  delay(500);
}
 
void secondSection() {
  beep(aH, 500);
  twist.write(90);
  beep(a, 300);
  twist.write(90);
  beep(a, 150);
  twist.write(90);
  beep(aH, 500);
  twist.write(90);
  beep(gSH, 325);
  twist.write(90);
  beep(gH, 175);
  twist.write(90);
  beep(fSH, 125);
  twist.write(90);
  beep(fH, 125);    
  twist.write(90);
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  twist.write(180);
  beep(dSH, 500);
  twist.write(130);
  beep(dH, 325);  
  twist.write(80);
  beep(cSH, 175);  
  twist.write(30);
  beep(cH, 125);  
  twist.write(50);
  beep(b, 125);  
  twist.write(70);
  beep(cH, 250);  
 
  delay(350);
}
