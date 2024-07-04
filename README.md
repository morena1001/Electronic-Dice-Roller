# Electronic-Dice-Roller

This is an electronic dice roller that uses a button to generate a random number, and outputs that number as a combination of seven lights that represent the six sides of a die. This project was developed using an STM32F302R8 MCU and a breadboard that houses the LEDs for output and the button for input.

### GPIO PERIPHERALS

##### *PA10*
The external button that controls the "rolling" of the die is connected to pin PA10 via the CN9 connector, pin 3, named D2. The mode of PA10 is "External Interrupt Mode with Falling edge trigger detection", and is pulled up. The button has two pins, one side connects to GND while the other connects to the D2 GPIO pin.

##### *PA1*
The light controlling the top left LED in the electronic die is connected to pin PA1 via the CN8 connector, pin 2, named A1. The configuration of PA1 and the rest of the six lights controlling the other LEDs in the die are as follows. The output level is "Low", the mode is "Output Push Pull", there is no pull-up or pull-down, and the Maximum output speed is "Low".    

##### *PA4*
The light controlling the middle left LED in the die is connected to pin PA4 via the CN8 connector, pin 3, named A2.

##### *PA5*
The light controlling the bottom left LED in the die is connected to pin PA5 via the CN10 connector, pin 30, named D4.

##### *PA6*
The light controlling the center LED in the die is connected to pin PA6 via the CN10 connector, pin 28, named D5.

##### *PA7*
The light controlling the bottom right LED in the die is connected to pin PA7 via the CN10 connector, pin 26, named D6.

##### *PA8*
The light controlling the middle right LED in the die is connected to pin PA8 via the CN9 connector, pin 8, named D7.

##### *PA9*
The light controlling the top right LED in the die is connected to pin PA9 via the CN5 connector, pin 1, named D8.
