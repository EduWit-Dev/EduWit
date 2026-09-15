/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta el servomotor en SERVO respetando GND, 5V y SIG.

  PRUEBA Y OBSERVA:
  girarServo() recibe una posición entre 0 y 180 grados. El tiempo entre órdenes
  permite que el mecanismo alcance cada posición. Cambia los ángulos y observa
  el recorrido útil de tu servomotor.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar(); // Prepara la conexión del servomotor.
}

void loop() {
  eduwit.girarServo(30);  // Coloca el servomotor cerca de un extremo.
  delay(1000);            // Da tiempo para alcanzar la posición.

  eduwit.girarServo(150); // Coloca el servomotor cerca del otro extremo.
  delay(1000);            // Da tiempo antes de repetir el movimiento.
}
