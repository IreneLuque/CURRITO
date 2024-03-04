import serial
import os
import datetime as dt
# from picamera import PiCamera
from time import sleep

#dmesg | grep -v disconnect | grep -Eo "tty(ACM|USB)." | tail -1
# destino='/home/pi/Pictures/Obstaculos'
# camara=PiCamera()
com=serial.Serial('/dev/ttyUSB0',9600)
com.flushInput()
while True:
    lectura=com.readline()
    line=lectura.decode('utf-8').strip()
    print(line)
#     if line=="1":
#         nombrefoto=os.path.join(destino,dt.datetime.now().strftime('%Y-%m-
#         %d_%H:%M:%S.jpg'))
#         camara.start_preview()
#         sleep(1)
#         camara.capture(nombrefoto)
#         camara.stop_preview()
