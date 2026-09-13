#include "EduBoardUNO.h"

// Proteccion de instanciacion: Solo se instancia si NO se compila para Nano/Profesional
#if !defined(ARDUINO_AVR_NANO) && !defined(USAR_EDUBOARD_PRO)
EduBoardUNO eduwit;
#endif

const uint8_t EduBoardUNO::PINS_LED[3] = {14, 18, 19};

EduBoardUNO::EduBoardUNO() {
  _servoActivo = false;
  COMANDO = '\0';
}

void EduBoardUNO::iniciar(unsigned long baudios) {
  pinMode(PIN_BOTON, INPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);

  pinMode(PIN_MA1, OUTPUT);
  pinMode(PIN_MA2, OUTPUT);
  pinMode(PIN_PWMA, OUTPUT);
  pinMode(PIN_MB1, OUTPUT);
  pinMode(PIN_MB2, OUTPUT);
  pinMode(PIN_PWMB, OUTPUT);

  for (uint8_t i = 0; i < 3; i++) {
    pinMode(PINS_LED[i], OUTPUT);
    digitalWrite(PINS_LED[i], LOW);
  }

  Serial.begin(baudios);
  apagar(AMBOS);
}

void EduBoardUNO::mover(MotorID motor, Direccion dir, int velocidad) {
  int velAcotada = constrain(velocidad, 0, 100);
  int pwm = map(velAcotada, 0, 100, 0, 255);

  uint8_t in1 = (dir == ADELANTE) ? HIGH : LOW;
  uint8_t in2 = (dir == ADELANTE) ? LOW : HIGH;

  if (motor == MA || motor == AMBOS) {
    digitalWrite(PIN_MA1, in1);
    digitalWrite(PIN_MA2, in2);
    analogWrite(PIN_PWMA, pwm);
  }
  if (motor == MB || motor == AMBOS) {
    digitalWrite(PIN_MB1, in1);
    digitalWrite(PIN_MB2, in2);
    analogWrite(PIN_PWMB, pwm);
  }
}

void EduBoardUNO::frenar(MotorID motor) {
  if (motor == MA || motor == AMBOS) {
    digitalWrite(PIN_MA1, HIGH);
    digitalWrite(PIN_MA2, HIGH);
    analogWrite(PIN_PWMA, 255);
  }
  if (motor == MB || motor == AMBOS) {
    digitalWrite(PIN_MB1, HIGH);
    digitalWrite(PIN_MB2, HIGH);
    analogWrite(PIN_PWMB, 255);
  }
}

void EduBoardUNO::apagar(MotorID motor) {
  if (motor == MA || motor == AMBOS) {
    digitalWrite(PIN_MA1, LOW);
    digitalWrite(PIN_MA2, LOW);
    analogWrite(PIN_PWMA, 0);
  }
  if (motor == MB || motor == AMBOS) {
    digitalWrite(PIN_MB1, LOW);
    digitalWrite(PIN_MB2, LOW);
    analogWrite(PIN_PWMB, 0);
  }
}

void EduBoardUNO::led(uint8_t numeroLed, EstadoLED estado) {
  if (numeroLed >= 1 && numeroLed <= 3) {
    uint8_t idx = numeroLed - 1;
    pinMode(PINS_LED[idx], OUTPUT);
    digitalWrite(PINS_LED[idx], (estado == ENCENDIDO) ? HIGH : LOW);
  }
}

bool EduBoardUNO::boton() {
  return digitalRead(PIN_BOTON) == HIGH;
}

void EduBoardUNO::esperarBoton() {
  while (digitalRead(PIN_BOTON) == LOW) {
    delay(5);
  }
  delay(20);
  while (digitalRead(PIN_BOTON) == HIGH) {
    delay(5);
  }
  delay(20);
}

bool EduBoardUNO::linea(uint8_t sensor, ColorLinea color) {
  int lectura = digitalRead(sensor);
  return (color == NEGRO) ? (lectura == HIGH) : (lectura == LOW);
}

int EduBoardUNO::leerAnalogico(uint8_t sensor) {
  return analogRead(sensor);
}

int EduBoardUNO::distancia(uint8_t sensor, int rangoMaxCm) {
  if (sensor == U3 && _servoActivo) {
    return rangoMaxCm;
  }

  uint8_t trig = (sensor == U1) ? 9 : (sensor == U2 ? 11 : 13);
  uint8_t echo = (sensor == U1) ? 10 : (sensor == U2 ? 12 : 14);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long timeoutUs = ((unsigned long)rangoMaxCm * 59) + 1500;
  unsigned long duracion = pulseIn(echo, HIGH, timeoutUs);

  if (duracion == 0) {
    return rangoMaxCm;
  }

  int distCalculada = (duracion * 0.0343) / 2;

  if (distCalculada <= 0 || distCalculada > rangoMaxCm) {
    return rangoMaxCm;
  }

  return distCalculada;
}

void EduBoardUNO::servo(int angulo) {
  if (!_servoActivo) {
    _miServo.attach(PIN_SERVO);
    _servoActivo = true;
  }
  int a = constrain(angulo, 0, 180);
  _miServo.write(a);
}

void EduBoardUNO::tono(int frecuenciaHz, int duracionMs, uint8_t pinBuzzer) {
  pinMode(pinBuzzer, OUTPUT);
  tone(pinBuzzer, frecuenciaHz, duracionMs);
  delay(duracionMs);
  noTone(pinBuzzer);
}

void EduBoardUNO::nota(NotasMusicales notaMusical, int duracionMs, uint8_t pinBuzzer) {
  tono((int)notaMusical, duracionMs, pinBuzzer);
}

void EduBoardUNO::leerBluetooth() {
  while (Serial.available() > 0) {
    char c = (char)Serial.read();
    if (c > 32 && c <= 126) {
      COMANDO = c;
    }
  }
}
