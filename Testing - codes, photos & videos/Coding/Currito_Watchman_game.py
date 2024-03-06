#  Grabar un rato y enviar video por correo
import os
import cv2
import time
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders


def modo_vigia(nombre_video, tiempo_grabacion):
	
	cap = cv2.VideoCapture(0)
	salida = cv2.VideoWriter(nombre_video, cv2.VideoWriter_fourcc(*'XVID'),20.0,(640,480))

	print("Empieza a grabar")
	tiempo_inicio = time.time()
	while (time.time() - tiempo_inicio) < tiempo_grabacion:
		_, frame = cap.read()
		salida.write(frame)

	cap.release()
	salida.release()
	cv2.destroyAllWindows()


def enviar_correo(nombre_video):

	ruta_adjunto = nombre_video
	nombre_adjunto = nombre_video


	direccion_fuente = "practica32021mlop@gmail.com"
	password = "Patata_12"
	direccion_destino = ['martajlopez98@gmail.com', 'pepemaestre@gmail.com']

	# Creamos el objeto mensaje
	mensaje = MIMEMultipart()
	
	# Establecemos los atributos del mensaje
	mensaje['From'] = direccion_fuente
	mensaje['To'] = ", ".join(direccion_destino)
	mensaje['Subject'] = 'Currito te vigila'

	# Agregamos el cuerpo del mensaje como objeto MIME de tipo texto
	mensaje.attach(MIMEText('Modo vigia activado', 'plain'))
	
	# Abrimos el archivo que vamos a adjuntar
	archivo_adjunto = open(ruta_adjunto, 'rb')
	# Creamos un objeto MIME base
	adjunto_MIME = MIMEBase('application', 'octet-stream')
	# Y le cargamos el archivo adjunto
	adjunto_MIME.set_payload((archivo_adjunto).read())
	# Codificamos el objeto en BASE64
	encoders.encode_base64(adjunto_MIME)
	# Agregamos una cabecera al objeto
	adjunto_MIME.add_header('Content-Disposition', "attachment; filename= %s" % nombre_adjunto)
	# Y finalmente lo agregamos al mensaje
	mensaje.attach(adjunto_MIME)

	server = smtplib.SMTP('smtp.gmail.com', 587)
	server.starttls()
	server.login(direccion_fuente, password)

	mensaje = mensaje.as_string()

	server.sendmail(direccion_fuente, direccion_destino, mensaje)
	server.quit()


if __name__ == "__main__":
	nombre_video = 'salida.avi'
	tiempo_grabacion = 10

	while True:
		entrada_desde_arduino = input("Realmente esto lo manda el arduino: ")

		if entrada_desde_arduino == "modovigia":
			modo_vigia(nombre_video, tiempo_grabacion)
			enviar_correo(nombre_video)
			if os.path.exists(nombre_video):
				os.remove(nombre_video)
				
			break

		else:
			print(entrada_desde_arduino)
			entrada_desde_arduino = input("Realmente esto lo manda el arduino: ")

