# Control_PC_Without_Touch
This was a project I worked on in my third year of engineering ( June 2019 ) I used Arduino along with 2 Ultrasonic sensors. using a combination of these I was able to perform 4 actions without touching the computer ( by using the position of my hand ).The application was based on the relative position of my hand with respect to the 2 sensors located on the left and right side of the computerscreen. 


[![VR Game](http://img.youtube.com/vi/7Ow-aXys7FY/0.jpg)](http://www.youtube.com/watch?v=7Ow-aXys7FY&ab_channel=SuyashMehraE "SLP VR Game Using Unity")

Process. 

1. The sensors track the obstacles ( Hand ) in front of it at regular intervals of time. each sensor calculate the distance of my hand if its beyond a certain limit ( 50 - 70CM ) its considered far, if its between 0-25 cm, its considered near.

2. depending on the distance of each hand a total of 8 actions can be performed ( L(left hand) - near & R- near , L - far & R - far , L - near & R - far, L - far & R - near, only L  near, only R near, only L far, only R far ) . 

3. Every combination can correspond to a different action on the computer. ( Each combination simulates a particular set of keys pressed on the keyboard , ex if left hand and right hand both are far, we can map it to ( ctrl + A ). This is done using the pyautogui module. 

4. Using these gestures I programmed VLC media player and Photos app to perform various functions ( next photo, prev photo, zoom in, zoom out, increase/decrease volume, ext track , previous track , adjust brightness, rewind , forward )

5. The application cound also track if the hand is moving far or near to the computer. this is then used for applications such as increasing/decreasing the volume if the hand comes near / goes away from the screen respectively. 

Tech and software packages used : 

1. Aurdrino

2. Python

3. 2 - Ultrasonic sensors

4. Python

5. pyautogui ( To simulate key presses ) and pyserial module ( to get the data from the sensors ) ( python modules ) 
