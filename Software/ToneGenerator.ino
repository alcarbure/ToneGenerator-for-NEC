/*

 * Arduino sqare Generator
 * by Albert Declaye for Plecotus
 * April 2021

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 
 * Use Arduino Pro Mini Atmega328P-16Mhz 5V 

*/


//#define DEBBUGING
#define PIN_CLOCK     10   // Pin clock PWM
#define PIN_RANGE     A5   // Reglage range (vitesse horloge 4 ï¿½ 1 mhz)
#define PIN_BATTERY   A3   // 0-1024 => 0 to 4.5V*2
#define ONTIME     600000   // Max time before watchdog alarm -10min

#define SPAS 93  // selector pas

// real frequency [] = {2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 17000, 18000, 19000, 20000, 25000, 40000};
uint16_t Frequency[] = {4000, 2000, 1333, 1000, 800, 667, 571, 500, 471, 444, 421, 400, 320, 200};
uint16_t Volume[]   = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // not yet used
uint16_t LowBattery[] ={16198, 18182, 20408, 22908, 24270, 27242, 30578}; // si la sol fa mi rï¿½ do


unsigned int SelectorRead;
int dummy         = 0;
int selected      = -1;
int ToneSelected  = 0;
int BatValue      = 0;
int i =0;
unsigned long lastTime=0;  // milisecond timer
unsigned long actualtime=0;

void checkFreq() {
  SelectorRead = (unsigned int)analogRead(PIN_RANGE);
/*
#if defined(DEBBUGING)
  Serial.print("Position read:");
  Serial.println(SelectorRead, DEC);
#endif
*/
  dummy = SPAS/2;
  for(ToneSelected=0;ToneSelected<11;ToneSelected++)
  {
    if(dummy > SelectorRead)
    {
       break;
    }else{
      dummy += SPAS;
    }  
   }


   if(selected != ToneSelected){
#if defined(DEBBUGING)
  Serial.print("Selected :");
  Serial.println(ToneSelected, DEC);
#endif
     selected =ToneSelected;
     ICR1 = Frequency[selected];
     //OCR Registers, which control the PWM duty cycle.-> power out
     OCR1A = ICR1/Volume[selected]; 
     OCR1B = ICR1/Volume[selected]; 
     
    lastTime = millis(); // refresh watchdog
   }
}

//-----------------------------------------------
// SetUp
//-----------------------------------------------

void setup(void)
{
#if defined(DEBBUGING)
  Serial.begin(115000);  
  while (!Serial);       //  wait for the serial monitor to open
#endif
  //DDRD = 0xFF;//all outputs
  pinMode(PIN_CLOCK, OUTPUT);  // sets the digital pin as output
  pinMode(PIN_RANGE, INPUT);   // sets the digital pin as inpout (ADC)
  pinMode(PIN_BATTERY, INPUT);   // sets the digital pin as inpout (ADC)

  lastTime = millis(); // init watchdog

/*  // 8-2-1Mhz Generator on pin 9
  // Reset TCCR1A
  TCCR1A &= ~((1<<COM1A1) | (1<<COM1A0) | (1<<WGM11) | (1<<WGM10));
  // Reset TCCR1B
  TCCR1B &= ~((1<<WGM13) | (1<<WGM12) | (1<<CS12) | (1<<CS11) | (1<<CS10));
  // Toggle OC1A/OC1B on Compare Match
  TCCR1A |= (0<<COM1A1) | (1<<COM1A0);
  TCCR1A |= (0<<WGM11) | (0<<WGM10);
  // CTC Mode
  TCCR1B |= (0<<WGM13) | (1<<WGM12);
  // 1 = No prescaling
  // 1=8 Mhz, 2=1Mhz, 3=125Khz, 4=31250hz, 5=15625Hz
  TCCR1B |= (0<<CS12) | (0<<CS11) | (1<<CS10);
  // Clockgen in OCR1A : 1=8 Mhz, 3=2Mhz, 7=1Mhz
  //OCR1A = 1;
  */
  
  /*

   Generation d'une PMW a frequence varuiable sur la pin 10
   Create a PMW signal on pin10
   Set Timer1 to phase and frequency correct mode. NON-inverted mode
   Output on OC1B (10)
   */
  TCCR1A = _BV(COM1A1) | _BV(COM1B1); // => TCCR1A = ((1<<COM1A1) | (1<<COM1B1));
  
  // Set prescaler to clk/1 (outputs from 122,072Hz to 4MHz
  TCCR1B = _BV(WGM13) | _BV(CS10);
  /*
   freq PWM max = 8Mhz -> ICR est le diviseur de cette frequence
   C'est donc le Registre ICR, qui contrôle la longueur totale des impulsions PWM
   Avec une frequence de 8000000/IRC1 = 8000000/4= 2000000Hz = 2MHz
   2=4Mhz - 3=2.666Mhz - 4=2Mhz - 5=1.6Mhz - 6=1.333Mhz -7=1.1429Mhz ect
  */
  
  ICR1 = 1000; // value 2 makes pulse width = 2 clock cycles (with clk/1 prescaler)
  // les registres OCR,  contrôlent le cycle de service PWM.
  // OCR1A et OCR1B doit etre compris entre 0 et IRC1/2 pour varier le volume
  OCR1A = ICR1/2;
  OCR1B = ICR1/2; 
  
  checkFreq();
  switch (selected){
    case 9:{
       ICR1 = 354; // 22.5Khz
      break;}
    case 10: {
       ICR1 = 320; // 25Khz
      break;} 
    case 11: {
       ICR1 = 250; // 32Khz
      break;} 
  } 
  

  // detect and playind if low battery
  BatValue = analogRead(PIN_BATTERY);
  
#if defined(DEBBUGING)
  Serial.print("Power :");
  Serial.println(BatValue, DEC);
#endif

  if (BatValue < 790){
    // Battery low play si...do if <7.8V
    OCR1A = ICR1/2;
    OCR1B = ICR1/2; 
    for(i=0;i<6;i++){
      ICR1 = LowBattery[i];
      delay(300);
    }  
    // down power level 
    for(i=50; i<ICR1; i+=(ICR1/25)){
      delay(100);
      OCR1A = ICR1/i; 
      OCR1B = ICR1/i; 
    }
    ICR1 = 100;
    delay(900);
  }
}



//-----------------------------------------------
//Main
//-----------------------------------------------

void loop(void)
{ 
  delay(100);
  checkFreq();
  // watchdog
  actualtime = millis(); 
  if(actualtime > (lastTime + ONTIME)){
    ICR1 = 16198;
    OCR1A = ICR1/2; 
    OCR1B = ICR1/2; 
    delay(250);
    ICR1 = 18182;
    OCR1A = ICR1/2; 
    OCR1B = ICR1/2; 
    delay(150);
   }
  
}
