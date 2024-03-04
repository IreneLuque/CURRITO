from picamera import PiCamera
from time import sleep
import os

destino_videos = '/home/pi/Documents/currito/videos'
destino_fotos = '/home/pi/Documents/currito/fotos'

nombre_fotos = os.path.join(destino_fotos,"foto1.jpg")
nombre_videos = os.path.join(destino_videos,"video.h264")

camera = PiCamera()
camera.start_preview()
camera.start_recording(nombre_videos)
sleep(5)
camera.stop_recording()
camera.stop_preview()