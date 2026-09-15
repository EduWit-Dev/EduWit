/*
  Desarrollado por EduWit: https://eduwit.com.mx

  CONEXIONES:
  Conecta en S1 un módulo LED compatible con 5 V: señal en S, alimentación en V
  y tierra en G. No conectes un LED suelto sin una resistencia adecuada.

  PRUEBA Y OBSERVA:
  S1 también representa un pin del Arduino. pinMode() lo prepara como salida y
  digitalWrite() establece un nivel alto o bajo. Cambia S1 por S2 o S3 y modifica
  los tiempos para utilizar otro puerto o velocidad de parpadeo.
*/

#include <EduWit.h>

void setup() {
  eduwit.iniciar();     // Prepara la EduBoard antes de usar sus puertos.
  pinMode(S1, OUTPUT);  // Configura la señal de S1 como salida digital.
}

void loop() {
  digitalWrite(S1, HIGH); // Entrega un nivel alto en la señal de S1.
  delay(500);             // Mantiene el módulo encendido medio segundo.

  digitalWrite(S1, LOW);  // Entrega un nivel bajo en la señal de S1.
  delay(500);             // Mantiene el módulo apagado medio segundo.
}
