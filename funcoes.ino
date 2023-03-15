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


