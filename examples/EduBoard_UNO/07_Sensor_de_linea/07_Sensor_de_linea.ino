/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta un sensor de línea digital en S1 y calibra su umbral.

  PRUEBA Y OBSERVA:
  detectaLinea() compara la señal con NEGRO o BLANCO. Abre el Monitor Serie a
  9600 baudios y acerca el sensor a ambas superficies. Cambia S1 o el color de
  comparación para explorar otros puertos y condiciones.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar(); // Prepara S1 y abre Serial a 9600 baudios.
}

void loop() {
  if (eduwit.detectaLinea(S1, NEGRO)) { // Comprueba si S1 corresponde a negro.
    Serial.println("NEGRO");            // Muestra el color detectado.
  } else {
    Serial.println("BLANCO");           // Muestra el estado contrario.
  }

  delay(250); // Mantiene el resultado visible antes de repetir la lectura.
}
