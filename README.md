
#Autonomous Obstacle-Avoiding Robot
The code provided implements an autonomous robot that can navigate and avoid obstacles using an ultrasonic sensor and motor control. The robot is controlled by an Arduino board and uses the Servo and NewPing libraries for servo motor and ultrasonic sensor functionality, respectively.

#Components Used
Servo motor
Ultrasonic sensor (trigPin, echoPin)
Motor control pins: LeftSideForward, LeftSideBackward, RightSideForward, RightSideBackward
Motor speed control pins: SpeedRight, SpeedLeft

#Setup
Set up the pin modes for the motor control pins, trigPin, and echoPin.
Attach the servo motor to pin 7 and set its initial position to 115 degrees.
Calibrate the ultrasonic sensor by taking several initial readings.

#Operation
The robot operates in a continuous loop, performing the following actions:

Read the distance to the nearest obstacle using the ultrasonic sensor (cm = readPing()).
Check if the distance is less than 50 cm.
If true, an obstacle is detected, and the robot needs to avoid it.
Stop the robot (Stop()).
Move backward for 550 milliseconds (Backward()).
Stop the robot again.
Look to the right and measure the distance (cmRight = lookRight()).
Look to the left and measure the distance (cmLeft = lookLeft()).
Stop the robot.
If both cmLeft and cmRight are less than 20 cm, it means there is an obstacle on both sides.
Stop the robot.
Move backward for 1300 milliseconds.
Stop the robot again.
Look to the right and measure the distance.
Look to the left and measure the distance.
Stop the robot.
If cmLeft is greater than cmRight, turn right for 520 milliseconds (Right()).
If cmRight is greater than cmLeft, turn left for 510 milliseconds (Left()).
If false, no obstacle is detected, and the robot can move forward (Forward()).

#Functions
lookRight(): Rotates the servo motor to the right, takes a distance reading, returns the distance, and resets the servo position.
lookLeft(): Rotates the servo motor to the left, takes a distance reading, returns the distance, and resets the servo position.
readPing(): Sends an ultrasonic pulse, calculates the distance to the nearest obstacle, and returns the distance.
Stop(): Stops the robot by setting all motor control pins to LOW.
Forward(): Moves the robot forward by setting the appropriate motor control pins and applying PWM speed control.
Backward(): Moves the robot backward by setting the appropriate motor control pins and applying PWM speed control.
Left(): Turns the robot left by controlling the motor control pins and applying PWM speed control.
Right(): Turns the robot right by controlling the motor control pins and applying PWM speed control.

#Usage
Connect the servo motor, ultrasonic sensor, and motor control pins to the Arduino board.
Upload the code to the Arduino board.
Make sure to adjust the pin assignments and motor control logic if necessary, depending on your specific setup.
Monitor the serial output to see the distance readings and movement commands of the robot.
