import serial
import requests
ser = serial.Serial('/dev/cu.usbmodem111301', 9600)

while(True):
    if ser.readable():
        val = ser.readline()
        jsontext = val.decode()
        print(jsontext)
        if jsontext.find("#") != -1:
            continue
        r = requests.post("http://220.69.209.30:3801/items", data=jsontext)
        print(r.text)