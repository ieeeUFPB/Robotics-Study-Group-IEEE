/* Esse exemplo recebe números no monitor serial e os imprime
 */
int valor; // Declara variável que armazenará valores de entrada do monitor serial

void setup() {
  Serial.begin(9600); // Inicia monitor serial
}

void loop() {
  if (Serial.available() > 0){ // Condição que espera um valor ser escrito no monitor
    valor = Serial.parseInt(); // Armazena número inteiro digitado no minitor dentro da variável
    Serial.println (valor); // Imprime valor inserido
  }

}
