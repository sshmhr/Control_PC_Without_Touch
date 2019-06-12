import pyautogui
import serial
import time

arduino = serial.Serial('com18', 9600)
time.sleep(5)

while True:

    hand_position = str(arduino.readline())

    if 'both_far' in hand_position:
        # Start/stop a slideshow
        pyautogui.typewrite('f5', 0.3)

    if 'both_near' in hand_position:
        pyautogui.typewrite('m', 0.3)

    if 'right_hand_in' in hand_position:
        pyautogui.hotkey('ctrl', '+')

    if 'right_hand_out' in hand_position:
        pyautogui.hotkey('ctrl', '-')

    if 'left_hand_in' in hand_position:
        pyautogui.typewrite('right')

    if 'left_hand_out' in hand_position:
        pyautogui.typewrite('left')

    hand_position = ""
