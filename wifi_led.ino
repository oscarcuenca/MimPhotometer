
/*
 NodeMCU Parpadeo/Blink por Dani No www.esploradores.com
 Hace parpadear un LED conectado a la salida D1 (GPIO05) del módulo NodeMCU.
 Este código de ejemplo es de público dominio.
 */


// LED variables section
// Which Arduino pin goes to which LED
int redPin = A0;

// A place to store the values coming from the analog port
int sensorValueRed =0;

//A place to store the maximum value for each LED
int maxRed = 0;

                                        
// the following variable is long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long timeSinceLastSensorHigh = 0;
int dataWritten = 0;

// Data Buffers for the LCD
char databuff1[16];
char databuff2[16];
char dispbuff[16];

 
void setup() {                          // La función “setup” incializa las configuraciones de 
                                        // los diferentes elementos del programa.
Serial.begin(115200);         // Start the Serial communication to send messages to the computer

// Set the Analog Pins
// Why are we setting input pins to output?
// We're doing this to prevent "leakage" from the pins.
// Setting the pins to output activates a pullup resistor,
// which makes it difficult for voltage to come into the Arduino,
// until we're ready for it.

Serial.println("Setting up the Analog Pins");
pinMode(redPin, OUTPUT);
digitalWrite(redPin, LOW);


//Set up LCD virtual

sprintf(databuff1,"Wakeup Test");
sprintf(dispbuff,"%-16s",databuff1);
Serial.println(dispbuff);


}
 
void loop() {                 // La función “loop” se ejecuta una y otra vez, indefinidamente.
 
/*
Back in setup(), we enabled a pullup resistor on the analog pins, which
made it difficult for electricity to come into the analog pins.
Here, we disable the pullup resistor, wait 10ms for the pin to stabilize,
read the voltage coming into the pin, then reenable the pullup
resistor.
*/

pinMode(redPin, INPUT);
delay(3000);
Serial.println("Reading red: ");
sensorValueRed= analogRead(redPin);
pinMode(redPin, OUTPUT);
Serial.println(sensorValueRed);
delay(10);

Serial.println("Comparing sensor values...");

// Here we compare each sensor to its maximum value.
// If any of the sensors has reached a new peak, sound a tone
if (sensorValueRed>maxRed)

{
Serial.println("Valor máximo Rojo...");
Serial.println(maxRed);
timeSinceLastSensorHigh = millis();
}

// Here we reset the old maximum value with a new one, if necessary
if(sensorValueRed>maxRed) 
{
maxRed = sensorValueRed;
}
}


