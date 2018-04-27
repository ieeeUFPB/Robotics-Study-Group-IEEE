/*
 * O objetivo desse programa é fazer acionamento de pinos (leds) sem interrupções
 * no programa. Com isso é possível trabalhar com diversos dispositivos "ao mesmo
 * tempo".
 */

#define LEDA 2 // Seta pino p/ led A
#define LEDB 3 // Seta pino p/ led B

int tempoAnteriorA = 0; // Inicia tempo anterior do LED A em 0 quando a placa liga
int tempoAnteriorB = 0; // Inicia tempo anterior do LED B em 0 quando a placa liga
int estLed = HIGH; // Inicia estado do led A em nível lógico alto
int estLedB = HIGH; // Inicia estado do led A em nível lógico alto

void setup() {
  pinMode(LEDA, OUTPUT); // Seta pino do Led A como saída
  pinMode(LEDB, OUTPUT); // Seta pino do led B como saída
}

void loop() {
  int tempoAtualA = millis(); // Atualiza tempo atual para o LED A
  int tempoAtualB = millis(); // Atualiza tempo atual para o LED B
  /*
   * Nesse if, sempre que o tempoAtual for atualizado é comparado com o tempo
   * desde o início do programa e quando a diferença é de 1000ms(1 sec) o estado
   * do led é atualizado. Depois o tempoAnterior é atualizado e o loop continua
   * atualizando o valor de tempoAtual até a diferença ser de 100ms(1 sec) de novo
   * e novamente atualizar o estado do led
   */
  if ((tempoAtualA - tempoAnteriorA) >= 1000){
    digitalWrite(LEDA, estLed);
    tempoAnteriorA = millis();
    estLed = !estLed;
  }

  /*
   * Nesse if, sempre que o tempoAtual for atualizado é comparado com o tempo
   * desde o início do programa e quando a diferença é de 1000ms(1 sec) o estado
   * do led é atualizado. Depois o tempoAnterior é atualizado e o loop continua
   * atualizando o valor de tempoAtual até a diferença ser de 100ms(1 sec) de novo
   * e novamente atualizar o estado do led
   */
  if ((tempoAtualB - tempoAnteriorB) >= 500){
    digitalWrite(LEDB, estLedB);
    tempoAnteriorB = millis();
    estLedB = !estLedB;
  }
}
