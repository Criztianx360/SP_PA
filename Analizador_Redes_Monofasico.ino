/*  EmonLibrary examples in openenergymonitor.org, Licence GNU GPL V3 
 *  Last modified by:    
 *  Cristian Daniel Chiñas Palacios
 *  cristian.chinas@alumno.udg.mx
 *  +34 602 14 56 73 (Spain)
 *  +52 331 804 35 19 (Mexico)
 *  September 27th, 2016 */

#include "EmonLib.h"                                // Include Emon Library
EnergyMonitor emon1;                                // Create an instance

void setup()
{  
  Serial.begin(9600);                               // Data rate in bits per second(baud) for serial transmission
  
  emon1.voltage(2, 246, 5.7);                       // Voltage: input pin, calibration, phase_shift
  emon1.current(1, 29.6);                           // Current: input pin, calibration.
}

void loop()
{
  emon1.calcVI(20,2000);                            // Calculate all. No.of half wavelengths (crossings), time-out
  emon1.calcF(50);                                  // 50 zero crossings
  emon1.serialprint();                              // Print out all variables (realpower, apparent power, Vrms, Irms, power factor)
  
  float Vrms            = emon1.Vrms;               //extract Vrms into Variable
  float Frequency       = emon1.frequency;          //extract Frequency into variable
  float Irms            = emon1.Irms;               //extract Irms into Variable
  float RealPower       = emon1.realPower;          //extract Real Power into variable
  float ApparentPower   = emon1.apparentPower;      //extract Apparent Power into variable
  float ReactivePower   = emon1.reactivePower;      //extract Reactive Power into variable
  float PowerFactor     = emon1.powerFactor;        //extract Power Factor into Variable
}
