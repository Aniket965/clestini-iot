# clestini-iot
This contains the code for touch detection using SONAR system designed using Arduino UNO and Ulrasonic sensor and servo motor.
> To find angle we will be using servo motor to find shortest distance at which the object is placed(while moving the ultrasound sensor slowly from 0 to 90 degree using servo), as shortest distance from ultrasound sensor, the object will be perpendicular to the ultrasound sensor we can then calculate angle thus we can find the angle at which ultrasound is perpendicular thus we can find by how much angle sensor has rotated.

----
<img width="287" alt="screen shot 2018-03-31 at 10 41 58 pm" src="https://user-images.githubusercontent.com/22680912/38166142-967e542c-353c-11e8-8c64-db180f0557b2.png">

----
## 🏃 Start
> Tested on Ardiuno uno
- connect trigger pin and echo pin of ultra sound sensor to 2 and 4 respectively and vcc to 5v, gnd to gnd
- connect servo Signal wire to pin number 9 and vcc to 5v and gnd to gnd.
- upload the code to ardiuno

## Observing Serial Output
> Serial output contains 3 comma seprated values first one is angle, second one is  vertical distance which is shown by red line in fig and third one is horizontal distance which is shown by blue color.



> **NOTE** the code is configured when servo is set to 90 degree which is 45 degree from front face of ultra sound sensor
