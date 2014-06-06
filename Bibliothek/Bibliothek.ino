class Stripe{
 public:
   Stripe(int r, int g, int b);
   void RGB(int r, int g, int b);
   void Black();
   void Fade(int led, int time);
   void Rand();
   int _r;
   int _b;
   int _g;
};
Stripe::Stripe(int r, int g, int b){
  _r = r;
  _b = b;
  _g = g;
}
void Stripe::RGB(int r, int g, int b){
  analogWrite(_r,r);
  analogWrite(_g,g);
  analogWrite(_b,b);
}
void Stripe::Black(){
  RGB(0,0,0);
}
void Stripe::Fade(int led,int time){
  Black();
  int d = time / 102;
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(led, fadeValue);
    delay(d);
  }
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    analogWrite(led, fadeValue);
    delay(d);
  }
}
void Stripe::Rand(){
  RGB(random(255),random(255),random(255));
}
Stripe s(10, 11, 9);
int BM = 7;
void setup() {
  randomSeed(analogRead(0));
  pinMode(BM, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(BM)==HIGH){
     s.RGB(255,255,255);
     delay(10000);
  }else{
    s.Black();
  }
  delay(100);
}
