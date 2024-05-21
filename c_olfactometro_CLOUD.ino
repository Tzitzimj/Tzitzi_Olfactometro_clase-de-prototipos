-/////////Esta parte es para conectar a wifi///////

// Pines para las válvulas o relés??
const int Solenoid1 = 13;
const int Solenoid2 = 12;
const int Solenoid3 = 11;
const int ValveVaccum = 10;
const int ValvePP = 8;
const int ValvePN = 7; 

/////////////////////// L I B R A R I E S ////////////////////////////
#include <QueueArray.h>


// Estados de la máquina de estado 

enum State {
   IDLE,
   START,
   ODOR_RELEASE,
   VACCUM_ON
}
QueueArray<int> event_queue;

  //Eventos que ocurren en los estados 

  enum Event {
  INITIAL_SETUP,
  BUTTON_LIMONENO_PRESSED,
  BUTTON_ACETATO_DE_AMILO_PRESSED,
  BUTTON_BUTIRATO_DE_ETILO_PRESSED,
  VALVE_VACCUM_ON,
  WAIT_INTERSTIMULUS,
  }

   // Se indican los pines de las válvulas solenoides como salidas 
  pinMode(Solenoid1, OUTPUT);
  pinMode(Solenoid2, OUTPUT);
  pinMode(Solenoid3, OUTPUT);
  pinMode(Solenoid4, OUTPUT);
  pinMode(ValveVaccum, OUTPUT);
  pinMode(ValvePP, OUTPUT);
  pinMode(ValvePN, OUTPUT);

//Global variables
unsigned long timeToOdor; // Variable para almacenar el tiempo de incio del odorante
unsigned long timeToVaccum // Variable para almacenar el tiempo de generar vácio
unsigned long timeToInterstimulus // Variable para almacenar el tiempo de interestímulo 
const unsigned long durationOfOdor = 10000; // Duración en milisegundos (10 segundos)
const unsigned long durationOfVaccum = 50000; // Duración en milisegundos (50 segundos)
const unsigned long durationOfInterstimulus = 120000; // Duración en milisegundos (2 minutos)

void setup() {
    // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  
}

//Director 

//INITIAL_SETUP
 if (allRedy) {
   IDLE ();
   event_queue.enqueue (START);
 }
/*
  Since OdorSelect is READ_WRITE variable, onOdorSelectChange() is
  executed every time a new value is received from IoT Cloud.
*/

void onOdorSelectChange()  {
  // Add your code here to act upon OdorSelect change
}
/*
  Since Start is READ_WRITE variable, onStartChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onStartChange()  {
  // Add your code here to act upon Start change
}

 //onOdorSelectChange 
   if (onOdorSelectChange) //seleccionar el odorante
   {
      event_queue.enqueue(onStartChange)
   }
   if (onStartChange) //activar odorante Limoneno
   {
      event_queue.enqueue(buttonLimonenoPressed)
   }
   if (buttonLimonenoPressed) //activar válvula vacio
   {
      event_queue.enqueue(valveVaccumOn)
   }
   if (valveVaccumOn) //Tiempo de espera interestímulo
   {
      event_queue.enqueue(waitInterStimulus)
   }
   if (waitInterStimulus) //Seleccionar el odorante  
   {
      event_queue.enqueue(onOdorSelectChange)
   } ////////
    if (onOdorSelectChange) //seleccionar el odorante
   {
      event_queue.enqueue(onStartChange)
   }
   if (onStartChange) //activar odorante Acetato de amilo
   {
      event_queue.enqueue(buttonAcetatoDeAmiloPressed)
   }
   if (buttonAcetatoDeAmiloPressed) //activar válvula vacio
   {
      event_queue.enqueue(valveVaccumOn)
   }
   if (valveVaccumOn) //Tiempo de espera interestímulo
   {
      event_queue.enqueue(waitInterStimulus)
   }/////
   if (onOdorSelectChange) //seleccionar el odorante
   {
      event_queue.enqueue(onStartChange)
   }
   if (onStartChange) //activar odorante Butirato de etilo
   {
      event_queue.enqueue(buttonButiratoDeEtiloPressed)
   }
   if (buttonButiratoDeEtiloPressed) //activar válvula vacio
   {
      event_queue.enqueue(valveVaccumOn)
   }
   if (valveVaccumOn) //Tiempo de espera interestímulo
   {
      event_queue.enqueue(waitInterStimulus)
   }

// Event Handler

while (!event_queue.isEmpty()){
   Event currentEvent = event_queue.dequeue();
}







/*void handleOdorant1Event (Event event) {
   if (event == BUTTON_PRESSED) {
      duration = 10000;
   if (millis () - starTime > duration) {
      currentState = END_ODORANT_1;
   }
   else {digitalWrite (Solenoid1, HIGH);
        digitalWrite (ValvePN, HIGH);
        }
   }
}
void handleEndOdorant1Event(Event event) {
   if (event == BUTTON_PRESSED) {
      duration = 50000;
   if (millis() - startTime > duration) {
      currentState = WAIT_INTERST_1;
   }
   else {digitalWrite (Solenoid1, LOW);
        digitalWrite (ValvePN, LOW);
        digitalWrite (ValveVaccum, HIGH);
        }
   }
}

void handleWaitInterest1Event(Event event) {
   if (event == BUTTON_PRESSED) {
      currentState = BUTTON_PRESSED2 //Avanza al sigueiente estado de presionar el boton 2
      duration = 120000; //REVISAR ESTO
      startTime = millis; ()
   } 
   else {
   if (millis () - startTime >= 120000) { // Si han pasado 2 minutos
      currentState = BUTTON_PRESSED2
      startTime = millis ();

   digitalWrite(ValvePP, LOW);
   digitalWrite(ValvePN, LOW);
   digitalWrite(ValveVaccum, LOW); 
   digitalWrite(Solenoid1, LOW);
   digitalWrite(Solenoid2, LOW);  
   digitalWrite(Solenoid3, LOW);
   digitalWrite(Solenoid4, LOW); 
   
   }
   }
}
}
*/