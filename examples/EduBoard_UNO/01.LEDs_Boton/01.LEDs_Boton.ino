// Kits, tarjetas y codigos disenados para aprender mas facil. Busca mas informacion en https://eduwit.com.mx/
// Ejemplo: Encendido de LEDs con el Boton Integrado
// Tarjeta: Arduino UNO + EduBoard UNO

#include <EduWit.h>

void setup() {
  eduwit.iniciar();
}

void loop() {
  if (eduwit.boton()) {
    eduwit.led(LED1, ENCENDIDO);
    eduwit.led(LED2, ENCENDIDO);
    eduwit.led(LED3, ENCENDIDO);
  } else {
    eduwit.led(LED1, APAGADO);
    eduwit.led(LED2, APAGADO);
    eduwit.led(LED3, APAGADO);
  }
}
