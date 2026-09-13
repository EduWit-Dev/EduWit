// Kits, tarjetas y codigos disenados para aprender mas facil. Busca mas informacion en https://eduwit.com.mx/
// Ejemplo: Melodia Himno a la Alegria en conector S1
// Tarjeta: Arduino UNO + EduBoard UNO

#include <EduWit.h>

void tocarMelodia() {
  eduwit.nota(MI4, 250, S1);
  eduwit.nota(MI4, 250, S1);
  eduwit.nota(FA4, 250, S1);
  eduwit.nota(SOL4, 250, S1);
  eduwit.nota(SOL4, 250, S1);
  eduwit.nota(FA4, 250, S1);
  eduwit.nota(MI4, 250, S1);
  eduwit.nota(RE4, 250, S1);
}

void setup() {
  eduwit.iniciar();
}

void loop() {
  if (eduwit.boton()) {
    eduwit.led(LED1, ENCENDIDO);
    tocarMelodia();
    eduwit.led(LED1, APAGADO);
  }
}
