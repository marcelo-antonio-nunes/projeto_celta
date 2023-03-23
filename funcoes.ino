void falaDeMontao(void (*func)(), int pino) {
  pinMode(pino, INPUT);
  if (digitalRead(pino)) {
    func();
  }
}
void falaUmaVez(void (*func)(), int pino) {
  pinMode(pino, INPUT);
  static int flag = 0;
  if (digitalRead(pino)) {
    if (!flag) {
      func();
      flag = !flag;
    }
  } else {

    flag = 0;
  }
}

void bloqueio_desliga(int bt, int aux, int trava) {
  static int count = 0;
  static bool flag_trava = false;
  static unsigned long atual;
  pinMode(bt, INPUT);
  pinMode(aux, INPUT);
  pinMode(trava, OUTPUT);
  if (!digitalRead(bt)) {
    if (millis() - atual > 50) {
      if (!flag_trava) {
        if (!digitalRead(aux)) {
          count++;
        }
        if (count == 3) {
          digitalWrite(trava, !digitalRead(trava));
          count = 0;
        }
        flag_trava = true;
        atual = millis();
      }
    }
  } else {
    flag_trava = false;
  }
}

void chave_liga_desliga(int bt, int led, int i) {
  const int numero_de_bottons = 10;
  static bool flag[numero_de_bottons];
  static unsigned long atual;
  pinMode(bt, INPUT);
  pinMode(led, OUTPUT);
  if (!digitalRead(bt)) {
    if (millis() - atual > 50) {
      if (!flag[i]) {
        digitalWrite(led, !digitalRead(led));
        flag[i] = true;
        atual = millis();
      }
    }
  } else {
    flag[i] = false;
  }
}

void executa_agendado(void(*func)(), int tempo, int index){
	static unsigned long atual[20] ={0};
	if(millis() - atual[index] > (tempo * 60000)){
		func();
		atual[index] = millis();
		}
}