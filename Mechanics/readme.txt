- This folder contains the example initialization codes of the mechanic elements presented in Section II of the paper.

- To initiate the servos, servo.attach function is used, which takes as arguments
the pin to which the servo is connected and the pulse widths (in ms) corresponding to the maximum (180º)
and minimum (0º) angles. The pins chosen for each element may vary, as well as the specific functionalities 
of each element: the goal is to allow the user to start up all the elements.

- Wheels initiation and control: To control the movement
of the wheels, the four connectors on the motor shield
are utilized. Two of them regulate the speed of the
wheels (0-255) and the other two determine the direction
of rotation (HIGH for forward motion and LOW for
backward motion). First, we set the names and types
of connections using the pinMode function . After that, we can encode the movement of
the robot.



