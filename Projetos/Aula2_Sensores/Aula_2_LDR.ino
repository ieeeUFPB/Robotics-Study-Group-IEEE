int ldr_pin = A0; 
int led_pin = 11; 

void setup() {
  Serial.begin (9600);
  pinMode (led_pin, OUTPUT); // Definindo pino digital para o LED
  pinMode (ldr_pin, INPUT); // Definindo pino analógico para sensor LDR (Luminosidade)
  
  digitalWrite(led_pin, LOW);
}

void loop() {
 int luminosidade = analogRead (ldr_pin); // Capturando valor da luminosidade (0-1023)
  Serial.println(luminosidade); // Exibindo no monitor Serial valor
 if (luminosidade > 500){ // Condição para ligar LED de acordo com a luminosidade
  digitalWrite (led_pin, HIGH);
 }
 else{
  digitalWrite (led_pin, LOW);
 }
delay (10);
}
