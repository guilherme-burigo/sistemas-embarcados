const int botaoA = 2;
const int led1 = 8; // pino PWM

const unsigned long tempoDebounce = 50;

int estadoBotao = HIGH;
int ultimoEstadoBotao = HIGH;
unsigned long ultimoTempo = 0;

int nivelBrilho = 0; // 0 a 4 (0%, 25%, 50%, 75%, 100%)

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  int leitura = digitalRead(botaoA);

  // ===== Debounce =====
  if (leitura != ultimoEstadoBotao) {
    ultimoTempo = millis();
  }

  if ((millis() - ultimoTempo) > tempoDebounce) {
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      // Detecta clique (quando pressionado)
      if (estadoBotao == LOW) {
        nivelBrilho++;
        if (nivelBrilho > 4) {
          nivelBrilho = 0;
        }
      }
    }
  }

  ultimoEstadoBotao = leitura;

  // ===== Controle de brilho =====
  // PWM vai de 0 a 255
  int brilhoPWM = (nivelBrilho * 255) / 4;

  analogWrite(led1, brilhoPWM);
}