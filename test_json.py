import time
import json
from serial import Serial
import serial
from pprint import pprint
import random

if __name__ == "__main__":
    print ("Ready...")
    ser  = Serial("/dev/cu.usbserial-1420", baudrate= 9600, 
           timeout=2.5, 
           parity=serial.PARITY_NONE, 
           bytesize=serial.EIGHTBITS, 
           stopbits=serial.STOPBITS_ONE
        )
    data = {"anger": {"vals": 42, "color": 29}, "anticipation": {"vals": 60, "color": 54}, "joy": {"vals": 48, "color": 74}, "trust": {"vals": 24, "color": 73}, "fear": {"vals": 24, "color": 90}, "surprise": {"vals": 42, "color": 128}, "sadness": {"vals": 18, "color": 200}, "disgust": {"vals": 36, "color": 233}}

    data=json.dumps(data)
    if ser.isOpen():
        ser.write(data.encode('ascii'))
        ser.flush()
        try:
            incoming = ser.readline().decode("utf-8")
            print (incoming)
        except Exception as e:
            print (e)
            pass
        ser.close()
    else:
        print ("opening error")


















#BINOD COMMENTING HIS CODE
ser  = Serial("/dev/cu.usbserial-1420", baudrate= 9600, timeout=2.5) #BINOD











