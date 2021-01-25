#define echoPin 3
#define triggerPin 2
#define ledPin 13

int delaymili = 1000;
int maximumRangeCm = 200;
int minimumRangeCm = 0;


long duration, distanceCm; // variables globales para almacenar la duración del pulso que devuele el sensor al medir la distancia y la distancia en Centimetros

// Configuro los pines del arduino
void setup() {
	Serial.begin(9600);
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(ledPin, OUTPUT);
}

void loop() {
	initTrigger();

	duration = pulseIn(echoPin, HIGH);
	distanceCm = microsecCm(duration)-1;

	if (distanceCm >= maximumRangeCm || distanceCm <= minimumRangeCm) {
		Serial.println("FUERA DE RANGO");
		//digitalWrite(ledPin, HIGH); 
	}
	else {
		Serial.print("Distancia en centimetros es: ");
		Serial.println(distanceCm);
		delay(delaymili);
    if(distanceCm<=5){
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin, LOW);
    }
	}
}

// Funcion que retorna la distancia en centimetros apartir de convertir la duración del pulso en distancia
long microsecCm(long microsecond) {
	return microsecond / 58;
}

// Inicia el sensor para la medicion de distancia
void initTrigger() {
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
}
