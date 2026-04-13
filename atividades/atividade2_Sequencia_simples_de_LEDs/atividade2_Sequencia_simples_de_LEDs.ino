const int leds[] = {8, 9, 10, 11}; // pinos dos 4 LEDs
const int quantidadeLeds = 4;

unsigned long intervalo = 200; // 200 ms
unsigned long ultimoTempo = 0;

int indiceAtual = 0;

void setup() {
  for (int i = 0; i < quantidadeLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  unsigned long tempoAtual = millis();

  // verifica se passou o tempo do intervalo
  if (tempoAtual - ultimoTempo >= intervalo) {
    ultimoTempo = tempoAtual;

    // apaga todos os LEDs
    for (int i = 0; i < quantidadeLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

    // acende o LED atual
    digitalWrite(leds[indiceAtual], HIGH);

    // avança para o próximo LED
    indiceAtual++;

    // volta para o início (loop)
    if (indiceAtual >= quantidadeLeds) {
      indiceAtual = 0;
    }
  }
}