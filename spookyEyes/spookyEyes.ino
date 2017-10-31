/*
   Spooky eyes blink at different rates based on ambient light levels
   (useful for frightening squirrels and other gentle passers by)

   Light level detection is auto-ranging and blink rate is tweaked by a potentiometer 
   on pin A3. An ATTiny85 does the computing, powered by a 3V lithium battery (2032). 
   A photocell in a 5.6kΩ voltage divider circuit provides analog light level input 
   to pin A2. Two LEDs are driven by pins 0 and 1 of the ATTiny.
   
   See e.g. http://highlowtech.org/wp-content/uploads/2011/10/ATtiny45-85.png for the 
   chip pinout to be sure you're matching software numbers to hardware numbers properly.

   10/31/17
   released to the public domain by the author
   Robert Zacharias, rzach@cmu.edu
*/

                              // pin assignments on ATTiny85
const int LEDpin1 = 0;        // LED on hardware pin 5 (lower right corner)
const int LEDpin2 = 1;        // another LED on hardware pin 6 (one above lower right corner)
const int potPin = A3;        // 10k potentiometer wiper on hardware pin 2 (one below upper left corner)
const int photosensePin = A2; // voltage divider from photocell to hardware pin 3 (one above lower left corner)

long last = 0; // will be used for blink timing

// start the eye LEDs in opposite states (change both to same value to blink in synchrony)
bool LEDstate1 = false;
bool LEDstate2 = true;

// variables to store highest and lowest values seen
int highestSeen, lowestSeen;

void setup() {
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(photosensePin, INPUT);
}

void loop() {
  int photoVal = analogRead(photosensePin);

  // set highest and lowest values based on ongoing observation; these start fresh on chip restart
  if (photoVal > highestSeen) highestSeen = photoVal;
  if (photoVal < lowestSeen) lowestSeen = photoVal;
  
  int photoScale = map(photoVal, lowestSeen, highestSeen, 10, 200);

  int potVal = analogRead(potPin);
  float multiplier = mapfloat(potVal, 0, 1023, 0.25, 4);

  int wait = photoScale * multiplier; // use pot to adjust blink rate

  // flip LED states if it has been long enough
  if (millis() - last > wait) {
    LEDstate1 = !LEDstate1;
    LEDstate2 = !LEDstate2;
    last = millis();
  }

  digitalWrite(LEDpin1, LEDstate1);
  digitalWrite(LEDpin2, LEDstate2);
}


// Arduino's built in map() function does integer math only, so it's necessary to define with floats to get float results
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
