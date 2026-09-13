#ifndef EDUBOARD_UNO_H
#define EDUBOARD_UNO_H

#include <Arduino.h>
#include <Servo.h>
#include "EduWit_Constantes.h"

// Identificadores de actuadores exclusivos de la EduBoard UNO
enum MotorID : uint8_t { MA = 0, MB = 1, AMBOS = 2 };
enum LEDID : uint8_t { LED1 = 1, LED2 = 2, LED3 = 3 };
enum SensorLineaID : uint8_t { S1 = A1, S2 = A2, S3 = A3 };
enum UltrasonicoID : uint8_t { U1 = 1, U2 = 2, U3 = 3 };

class EduBoardUNO {
  private:
    Servo _miServo;
    bool _servoActivo;

    // Mapeo fisico de pines EduBoard UNO - REV3
    static const uint8_t PIN_MA1 = 2;
    static const uint8_t PIN_MA2 = 4;
    static const uint8_t PIN_PWMA = 3;
    static const uint8_t PIN_MB1 = 7;
    static const uint8_t PIN_MB2 = 8;
    static const uint8_t PIN_PWMB = 5;
    static const uint8_t PIN_BOTON = 6;
    static const uint8_t PIN_SERVO = 13;
    static const uint8_t PINS_LED[3]; // A0 (14), A4 (18), A5 (19)

  public:
    volatile char COMANDO;

    EduBoardUNO();

    void iniciar(unsigned long baudios = 9600);

    // Control de motores (0 a 100%)
    void mover(MotorID motor, Direccion dir, int velocidad);
    void frenar(MotorID motor);
    void apagar(MotorID motor);

    // Sensores y entradas
    bool boton();
    void esperarBoton();
    bool linea(uint8_t sensor, ColorLinea color);
    int leerAnalogico(uint8_t sensor);
    int distancia(uint8_t sensor, int rangoMaxCm = 200);

    // Actuadores
    void led(uint8_t numeroLed, EstadoLED estado);
    void servo(int angulo);
    void tono(int frecuenciaHz, int duracionMs, uint8_t pinBuzzer = S1);
    void nota(NotasMusicales notaMusical, int duracionMs, uint8_t pinBuzzer = S1);

    // Comunicacion Bluetooth
    void leerBluetooth();
};

// Declaracion externa de la instancia
extern EduBoardUNO eduwit;

#endif
