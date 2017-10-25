/* Esse exemplo utiliza o sensor ultrassônico para ajustar a posição do servo motor
 * de acordo com a distância do obstáculo.
 */
#include <Servo.h> // Inclui a biblioteca de controle do servo motor
#define motor 7 // Define pino que está conectado o servo motor

Servo servo; // Cria objeto da classe Servo para representar nosso servo motor

#include <Ultrasonic.h> // Inclui a biblioteca do sensor ultrassônico
#define pino_echo 5 // Define pino echo do sensor ultrassônico
#define pino_trigger 4 // Define pino trigger do sensor ultrassônico

Ultrasonic sensor_distancia (pino_trigger, pino_echo); // Cria objeto da classe Ultrasonic e usa os pinos do sensor como parâmetro 

int dist; // Declara variável para armazenar o valor da distância
void setup() {
  Serial.begin (9600); // Inicia monitor serial
  servo.attach(motor); // Inicia servo no pino definido
  servo.write(0); // Inicia sistema com servo motor na posição 0

}

void loop() {

  dist = sensor_distancia.distanceRead(); // Atualiza valor da distância na variável "dist"
  if (dist > 0 && dist < 180){ // Só funciona se a distância estiver entre os limites do servo motor (0 a 180 graus)
    servo.write (dist); // Escreve valor da distância como posição do servo motor
    delay (50);
  }

}
