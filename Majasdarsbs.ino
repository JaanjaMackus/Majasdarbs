int poga=PB3;

int ledViens=PA2;
int ledDivi=PA3;
int ledTris=PA4;
int ledChetri=PA5;
int ledPieci=PA6;
int ledSeshi=PA7;
int ledSpetinji=PA8;
int ledAstonji=PA11;
int ledDevinji=PA12;
int ledDesmit=PA15;

int ledSaraksts[10] = {ledViens, ledDivi, ledTris, ledChetri, ledPieci, ledSeshi, ledSpetinji, ledAstonji, ledDevinji, ledDesmit};

int ieprieksejais{0};
int aktualais{0};
int skaitiklis{0};
uint32_t timer{0};


void setup() {
  // put your setup code here, to run once:
  pinMode(poga, INPUT);

  for(int i=0;i<10;i++){
    pinMode(ledSaraksts[i], OUTPUT);
  }

}

void loop() {

  while(true){
    if(millis()-timer>100){
      ieprieksejais = aktualais;
      aktualais = ledSaraksts[skaitiklis];
      digitalWrite(ieprieksejais, LOW);
      digitalWrite(aktualais, HIGH);
      timer=millis();
      skaitiklis = skaitiklis + 1;
      if(skaitiklis==10){
        skaitiklis = 0;
      }
    }
    if(digitalRead(poga)== HIGH) break;
  }

  while(true){
     if(millis()-timer>100){
      ieprieksejais = aktualais;
      aktualais = ledSaraksts[skaitiklis];
      digitalWrite(ieprieksejais, LOW);
      digitalWrite(aktualais, HIGH);
      timer=millis();
      skaitiklis = skaitiklis - 1;
      if(skaitiklis<0){
        skaitiklis = 9;
      }
    }
    if(digitalRead(poga)== HIGH) break;

  }
  // put your main code here, to run repeatedly:

}
