import pyautogui
import serial
import time

arduino = serial.Serial('com18', 9600)
time.sleep(5)

while True:

    hand_position = str(arduino.readline())

    if 'both_far' in hand_position:
        pyautogui.typewrite('space', 0.3)

    if 'both_near' in hand_position:
        pyautogui.typewrite('m', 0.3)

    if 'right_hand_in' in hand_position:
        pyautogui.hotkey('ctrl', 'left')

    if 'right_hand_out' in hand_position:
        pyautogui.hotkey('ctrl', 'right')

    if 'left_hand_in' in hand_position:
        pyautogui.hotkey('ctrl', 'down')

    if 'left_hand_out' in hand_position:
        pyautogui.hotkey('ctrl', 'up')

    hand_position = ""
