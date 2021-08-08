import serial

ser = serial.Serial('/dev/cu.usbmodem111301', 9600)

while(True):
    if ser.readable():
        val = ser.readline()
        jsontext = val.decode()
        print(jsontext)
        if jsontext.find("#") != -1:
            continue
        f = open("busData.json", "w")
        f.write(jsontext)
        f.close()