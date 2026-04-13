const int potPin = A0;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  int valorPot = analogRead(potPin); // 0 a 1023

  // Converte para porcentagem (0 a 100)
  float porcentagem = (valorPot / 1023.0) * 100.0;

  int ledsLigados = 0;

  // Define quantos LEDs devem acender
  if (porcentagem >= 25) ledsLigados++;
  if (porcentagem >= 50) ledsLigados++;
  if (porcentagem >= 75) ledsLigados++;
  if (porcentagem >= 90) ledsLigados++;

  // Atualiza LEDs individualmente
  digitalWrite(led1, ledsLigados >= 1 ? HIGH : LOW);
  digitalWrite(led2, ledsLigados >= 2 ? HIGH : LOW);
  digitalWrite(led3, ledsLigados >= 3 ? HIGH : LOW);
  digitalWrite(led4, ledsLigados >= 4 ? HIGH : LOW);
}