/**
 ********************************************************************************
 *
 * Software: Bombomduino
 * About: Braço robótico para resgatar gorosmeia..
 * Date: 25/05/2016
 * Version: 0.0.1
 * Developer: RodriguesFAS
 * Website: <htttp://rodriguesfas.com.br>
 *
 ********************************************************************************
 */


 #include <Servo.h>

 /* Servo movimentos na horizontal: para a direita e para esquerda.. */
Servo servo_HOR;         // Cria objeto servo motor.
int servo_HOR_PIN = 5;  // Define pino PWM conectado ao servo motor.
int portCom_HOR;       //  Variável para armazenardados do Joystick.

/* Servo movimentos na vertical: para cima e para baixo.. */
Servo servo_VER;
int servo_VER_PIN = 6;
int portCom_VER_UP_DOWN;

/* Servo movimentos para frente e para tras.. */
Servo servo_FR_TR;
int servo_FR_TR_PIN = 10;
int portCom_FR_TR;

/* Servo movimentos da grarra: abrir e fechar: */
Servo servo_GARRA;
int servo_GARRA_PIN = 11;
int portCom_GARRA;

/**
 * setup() - 
 */
 void setup(){
 	/* Define configuração de pinos.. */
 	servo_HOR.attach(servo_HOR_PIN);
 	servo_VER.attach(servo_VER_PIN);
 	servo_FR_TR.attach(servo_FR_TR_PIN);
 	servo_GARRA.attach(servo_GARRA_PIN);

 	/* Configura posição inicial do braço.. */
 	servo_HOR.write(0);
 	servo_VER.write(90);
 	servo_FR_TR.write(90);
 	servo_GARRA.write(180);
 }

/**
 * loop() - 
 */
 void loop(){

 	portCom_VER_UP_DOWN = analogRead(4); // X Joystick Rigth ..
 	portCom_VER_UP_DOWN = map(portCom_VER_UP_DOWN, 0, 1023, 0, 180);
 	servo_VER.write(portCom_VER_UP_DOWN);

 	portCom_GARRA = analogRead(5); // Y Joystick Riggth ..
 	portCom_GARRA = map(portCom_GARRA, 0, 1023, 0, 180);
 	servo_GARRA.write(portCom_GARRA);


 	portCom_HOR = analogRead(2); // Y Joystick Left ..
 	portCom_HOR = map(portCom_HOR, 0, 1023, 0, 180);
 	servo_HOR.write(portCom_HOR);

 	portCom_FR_TR = analogRead(1); // X Joystick Left ..
 	portCom_FR_TR = map(portCom_FR_TR, 0, 1023, 0, 180);
 	servo_FR_TR.write(portCom_FR_TR);

 	delay(15); /* Tempo de leitura do pin */
 }





