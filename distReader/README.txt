The distance reader displays the distance of an object from an ultrasonic sensor in centimeters.

About Ultrasonic sensor:

The ultrasonic sensor has 4 terminals. 
-VCC (connected to the 5V pin)
-Trig (connected to digital pin 9)
-Echo (connected to digital pin 10)
-GND (connected to ground)

-The trig is capable of sending an ultrasonic wave towards the object from the transducer of the ultrasonic sensor.
-The echo is responsible for detecting the wave reflected by the object through the receiver.

About Code:

-I use long for the distance reading because it returns a length of time in microseconds, which could be very large.

-I turn the trigger on for 10 microseconds to send the ultrasound wave and then call pulseIn to find the amount of time it takes the soundwave 
to hit the target and come back (essentially, 2x the actual amount of time it takes the soundwave to hit the object).

-The third parameter of 30000 in pulseIn just means that if the ultrasonic wave does not come back after 30000 microseconds, 
the function call will end instead of hanging.

-Distance = time * speed. The speed of sound is 0.0343 meters per microsecond (we use microseconds because time is measured in microseconds). 
The time value in the distance formula is 2x the actual time it takes to hit the object, so we account for this by dividing the speed by 2. 
This gives the distance in centimeters.
