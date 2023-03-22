
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// definine os pinos
#define cinto 13
#define setaEsquerda 8
#define setaDireita 9


DFRobotDFPlayerMini myDFPlayer;
void setaDireitaLigada();
void setaEsquerdaLigada();
void falaDeMontao(void (*func)(), int pino);
void coloqueOcinto();
void falaUmaVez(void (*func)(), int pino);


void setup() {
  SoftwareSerial mySoftwareSerial(10, 11);  // RX, TX
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  //Definições iniciais
  myDFPlayer.setTimeOut(500);  //  Timeout serial 500ms
  myDFPlayer.volume(30);       //  Volume (de 0 até 30)
  myDFPlayer.EQ(10);           //  Equalização normal
}

void loop() {
  // falaUmaVez(coloqueOcinto, cinto);
  // falaDeMontao(setaDireitaLigada, setaDireita);
  // falaDeMontao(setaEsquerdaLigada, setaEsquerda);

  // delay(2000);
  bloqueio_desliga(8, 9, 13);
}







