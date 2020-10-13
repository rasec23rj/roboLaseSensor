#include <Servo.h>

#define POS_INICIAL 90
#define X_MINIMO 30
#define Y_MINIMO 50
#define X_INTERVALO 12
#define Y_INTERVALO 4
#define LASER D1
#define PIR D2
#define TEMPO_LASER 10
Servo servoX;
Servo servoY; 

void setup() {
    servoX.attach(D3);
    servoY.attach(D4);
    servoX.write(POS_INICIAL);
    servoY.write(POS_INICIAL);

    pinMode(LASER, OUTPUT);
    digitalWrite(LASER, LOW);
    pinMode(PIR, INPUT);
    Serial.begin(9600);
}

void loop() {
    int trigger = digitalRead(PIR);
    if(trigger == HIGH){
        liga_laser();
        Serial.println("Detectado");
    } else {
        desliga_laser();
        Serial.println("NÃO Detectado");
    }
   
}

// FUNÇÕES AUXILIARES

void posiciona_motores() {
    int posicaoX = (random(0, (X_INTERVALO)) * 10 + X_MINIMO);
    int posicaoY = (random(0, (Y_INTERVALO)) * 10 + Y_MINIMO);
    servoX.write(posicaoX);
    servoY.write(posicaoY);
      
}

void liga_laser() {
    for (int i = 0; i <= TEMPO_LASER/2; ++i){
        digitalWrite(LASER, HIGH);
        posiciona_motores();
        delay(2000);
    }
}

void desliga_laser() {
    digitalWrite(LASER, LOW);
    servoX.write(POS_INICIAL);
    servoY.write(POS_INICIAL);
}
