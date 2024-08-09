# Electronic-Dice-Roller

This is an electronic dice roller that uses a button to generate a random number, and outputs that number in both usart2 to a terminal and i2c to an LCD. This project was developed using an STM32F302R8 MCU and a breadboard that houses the LCD for output and the button for input.

### GPIO PERIPHERALS

##### *PA10*
The external button that controls the "rolling" of the die is connected to pin PA10 via the CN10 connector, pin 33, named D2. The mode of PA10 is "External Interrupt Mode with Falling edge trigger detection", and is pulled up. The button has two pins, one side connects to GND while the other connects to the D2 GPIO pin.

##### *PB7*
the SDA pin of the LCD is connected to the pin PB7 via the CN7 connector, pin 21, opposite of the pin named GND.  

##### *PB8*
The SCL pin of the LCD is connected to the pin PB8 via the CN10 connector, pin 3, named D15.
