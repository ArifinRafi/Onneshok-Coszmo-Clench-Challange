int R_IS = 8;
int L_IS = 9;
int R_EN = 7;
int L_EN = 6;

//motor1, motor3 and motor5
int RPWM_1 = 3;
int LPWM_1 = 5;

//motor2, motor4 and motor 6
int RPWM_2 = 10;
int LPWM_2 = 11;


int speed1 = 200;
int speed2 = 200;



void setup() {
  //define pinmode


  pinMode(R_IS, OUTPUT);
  pinMode(L_IS, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  
  //motor1, motor3
  pinMode(RPWM_1 , OUTPUT);
  pinMode(LPWM_1, OUTPUT);

  //motor2, motor4 and motor6
  pinMode(RPWM_2 , OUTPUT);
  pinMode(LPWM_2, OUTPUT);
  

  digitalWrite(R_IS, LOW);
  digitalWrite(L_IS, LOW);
  
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()>0) {
  char state = Serial.read();

  if (state == 'w') {
    forward();
    Serial.print("f");
  }
  else if (state == 'x') {
   reset();
  }
  else if (state == 's') {
   backward();
  }
  else if (state == 'd') {
   right();
  }
  else if (state == 'a') {
   left();
  }
  
 }
  
}
  


void forward() {
  analogWrite(RPWM_1, speed1);
  analogWrite(RPWM_2, speed1);
  analogWrite(LPWM_2, 0);
  analogWrite(LPWM_2, 0);
}

void backward() {
  analogWrite(LPWM_1, speed1);
  analogWrite(LPWM_2, speed1);
  analogWrite(RPWM_1, 0);
  analogWrite(RPWM_2, 0);
}


void right() {
  analogWrite(RPWM_1, speed2);
  analogWrite(RPWM_2, 0);
  analogWrite(LPWM_2, speed2);
  analogWrite(LPWM_1, 0);
  
}

void left() {
  
  analogWrite(RPWM_2, speed2);
  analogWrite(RPWM_1, 0);
  analogWrite(LPWM_1, speed2);
  analogWrite(LPWM_2, 0);
}

void reset() {
  analogWrite(RPWM_1, 0);
  analogWrite(RPWM_2, 0);
  analogWrite(LPWM_1, 0);
  analogWrite(LPWM_2, 0);
  
}
