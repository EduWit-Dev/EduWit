/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  No necesitas componentes externos. Utilizaremos el BOTÓN y LED1 integrados.

  PRUEBA Y OBSERVA:
  botonPresionado() entrega verdadero o falso. if utiliza ese resultado para
  decidir el estado de LED1. Cambia el LED o invierte ENCENDIDO y APAGADO para
  comprobar cómo una entrada puede controlar una salida.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar(); // Prepara el BOTÓN y los LEDs de la EduBoard.
}

void loop() {
  if (eduwit.botonPresionado()) {       // Comprueba si el BOTÓN está presionado.
    eduwit.fijarLed(LED1, ENCENDIDO);   // Enciende LED1 cuando la condición es verdadera.
  } else {
    eduwit.fijarLed(LED1, APAGADO);     // Apaga LED1 cuando el BOTÓN está libre.
  }
}
