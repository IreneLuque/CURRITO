import os
from picamera import PiCamera
import time

destino = "/home/pi/Documents/currito/videos"
camara = PiCamera()

def grabo_video():
    nombre = os.path.join(destino, "video1.h264")
    camara.start_preview()
    camara.start_recording(nombre)

def paro_video():
    camara.stop_recording()
    camara.stop_preview()
    
while True:
    grabo_video()
    inicio = time.time()
    
    if (time.time()-inicio) > 20:
        paro_video()
        break
    break