/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta un sensor compatible con 5 V en S1.

  PRUEBA Y OBSERVA:
  leerDigital() clasifica la señal como 0 o 1; leerAnalogico() conserva niveles
  entre 0 y 1023. Abre el Monitor Serie a 9600 baudios, cambia la condición del
  sensor y después prueba el mismo código con S2 o S3.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar(); // Prepara S1 como entrada y abre Serial a 9600 baudios.
}

void loop() {
  bool estadoDigital = eduwit.leerDigital(S1); // Obtiene un estado de 0 o 1.
  int valorAnalogico = eduwit.leerAnalogico(S1); // Obtiene un nivel de 0 a 1023.

  Serial.print("Digital: ");       // Escribe la etiqueta de la primera lectura.
  Serial.print(estadoDigital);     // Muestra el estado digital.
  Serial.print("  Analogico: ");  // Separa e identifica la segunda lectura.
  Serial.println(valorAnalogico); // Muestra el valor analógico y termina la línea.

  delay(250); // Reduce la velocidad de actualización para facilitar la lectura.
}
