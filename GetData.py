import serial

ser = serial.Serial('/dev/cu.usbmodem111301', 9600)

while(True):
    if ser.readable():
        val = ser.readline()
        print(val.decode()) 