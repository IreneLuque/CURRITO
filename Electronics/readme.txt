-This folder contains the example initialization codes of the electronic elements presented in Section II of the paper.

-To initiate the servos, servo.attach function is used, which takes as arguments
the pin to which the servo is connected and the pulse widths (in ms) corresponding to the maximum (180º)
and minimum (0º) angles. The pins chosen for each element may vary, as well as the specific functionalities 
of each element: the goal is to allow the user to start up all the elements.

-The library needed for some of the examples presented is <Adafruit_NeoPixel.h>.



- LED ring: To program the LED ring, a specific library 
is needed: Adafruit.NeoPixel library. We declare
a variable associated with the LED strip and specify the
number of pixels, connection pin, and type and colors
of the strip. We can configure which pixels we want 
to light and their colors (RGB) or brightness. 

- Ultrasonic Sensor: On the other hand, the Ultrasonic Sensor operates by sending a
high value through the TRIGGER pin and waiting for
a result through the ECHO pin. The result is the time
elapsed between the moment the wave was sent and its
return after bouncing off an object. This information is
then converted into a distance value using the speed of
sound in air.

- Microphone: Microphone pin needs to be declared as an input, 
as is function is to pick up sounds from the outside; values read 
will be stored as digital variables.

- Speaker: its pin will be declared as an output, where specific 
functions will be used by specifying frequency in hertz and note 
duration. Arduino provides a range of functions to make the most 
of each of the devices.

-RPi Camera: as explained in the document, RPi camera is coded in Python and serial port communication is needed. Some camera 
examples oriented to photographs and videos are added. Communication between the Arduino and Raspberry Pi
is established through the serial port by connecting the USB-B of the Arduino to one of the USB-A ports on the
RPi. The camera on the RPi-4B is programmed using the Thonny Python IDE.


