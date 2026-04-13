const int botaoA = 2;
const int botaoB = 3;
const int led1 = 13;

const unsigned long tempoDebounce = 50; // 50 ms

// Variáveis botão A
int estadoA = HIGH;
int ultimoEstadoA = HIGH;
unsigned long ultimoTempoA = 0;

// Variáveis botão B
int estadoB = HIGH;
int ultimoEstadoB = HIGH;
unsigned long ultimoTempoB = 0;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  int leituraA = digitalRead(botaoA);
  int leituraB = digitalRead(botaoB);

  // ===== Debounce botão A =====
  if (leituraA != ultimoEstadoA) {
    ultimoTempoA = millis();
  }

  if ((millis() - ultimoTempoA) > tempoDebounce) {
    if (leituraA != estadoA) {
      estadoA = leituraA;
    }
  }

  ultimoEstadoA = leituraA;

  // ===== Debounce botão B =====
  if (leituraB != ultimoEstadoB) {
    ultimoTempoB = millis();
  }

  if ((millis() - ultimoTempoB) > tempoDebounce) {
    if (leituraB != estadoB) {
      estadoB = leituraB;
    }
  }

  ultimoEstadoB = leituraB;

  // ===== Lógica do LED =====
  // Botão pressionado = LOW
  if (estadoA == LOW && estadoB == LOW) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}