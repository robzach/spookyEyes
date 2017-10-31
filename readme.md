# Spooky Eyes

A (slightly) spooky project for a combined [IDeATe](http://ideate.andrew.cmu.edu) and 
[MechE MakerWing](https://www.cmu.edu/me/news/archive/2015/hamerschlag-makerwing.html)  Halloween 
at Carnegie Mellon University.

# Let's make it!

## Parts list

* 1 ATTiny85 microcontroller
* 1 220Ω resistor
* 1 photoresistor
* 1 10kΩ potentiometer
* 2 LEDs
* 1 medium solderless breadboard
* ~8 male–male jumper wires
* 6 female–male jumper wires (optional—for extending light sensor and LEDs off the breadboard)
* 1 2032 3V lithium coin cell battery
* 1 coin cell battery holder
* spooky thing to put your LEDs and light sensor onto

## If you are comfortable with electronics and reading a schematic

1. The Arduino sketch has been preloaded onto the ATTiny85 chip. Just build the circuit as the 
schematic indicates, and the LEDs should begin blinking as soon as the chip is powered.

## If you are newer to electronicsland

1. Welcome! We're glad you're here.

2. Let's start with the ATTiny85 chip, which will drive the whole project. The one we're 
supplying has been pre-programmed with instructions to read the ambient light level and combine 
that with information from the potentiometer to establish the rate at which the LEDs will blink.

Put the chip onto the breadboard like so:
![placing the chip](images/placingTheChip.jpg)

**Pay attention to the dot on the chip and make sure it's in the upper left corner!**

This tutorial refers to the *software* numbers each of the chip's 
hardware pins use. For instance, if you make an attachment to software pin 0, that means the 
chip's lower right pin, which has hardware number 5. Here's a schematic of the chip showing the 
hardware and software numbers:
![ATTiny85 pinout with hardware and software pin designations](images/attiny85pinout.png)
Image from Sparkfun, shared under the [CC BY-SA 4.0 
license](https://creativecommons.org/licenses/by-sa/4.0/)

3. Now we can add some LEDs. This tutorial refers to the *software* numbers each of the chip's 
hardware pins use. For instance, if you make an attachment to software pin 0, that means the 
chip's lower right pin, which has hardware number 5.
