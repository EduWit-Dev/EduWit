// Kits, tarjetas y codigos disenados para aprender mas facil. Busca mas informacion en https://eduwit.com.mx/
// Ejemplo: Evasion de obstaculos con medicion ultrasonica
// Tarjeta: Arduino UNO + EduBoard UNO

#include <EduWit.h>

void setup() {
  Serial.begin(9600);
  eduwit.iniciar();
  eduwit.esperarBoton();
}

void loop() {
  int dist = eduwit.distancia(U1, 200);
  Serial.println(dist);

  if (dist < 20) {
    eduwit.frenar(AMBOS);
    eduwit.led(LED1, ENCENDIDO);
    delay(200);

    eduwit.mover(MA, ATRAS, 80);
    eduwit.mover(MB, ADELANTE, 80);
    delay(350);
    
    eduwit.led(LED1, APAGADO);
  } else {
    eduwit.mover(AMBOS, ADELANTE, 100);
  }
}
