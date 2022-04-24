import serial
import speech_recognition as sr
import pyttsx3

engine = pyttsx3.init()
engine.say("Hi, what can I do for you?")
engine.runAndWait()

listener = sr.Recognizer()
arduino = serial.Serial("COM12", 115200)

actions = ["left", "right", "forward", "reverse", "on", "off"]

while True:
    try:
        with sr.Microphone() as source:
            print("...Listening...")
            voice = listener.listen(source)
            command = listener.recognize_google(voice)
            print(command)

        for i in range(0, len(actions)):
            if actions[i] in command:
                arduino.write(actions[i].encode())
    except:
        pass
