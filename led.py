#!/usr/bin/env python
# -*- coding: utf-8 -*-

# CPCDOS, RASPBERRY PI, ARDUINO par Esteban Cadic le 06/04/2016
# Partie : Raspberry Pi : Python

import serial # module permettant la communication série
import sys # module permettant, dans notre cas, de récupérer un argument

argument2 = sys.argv[1] # on récupère l'argument2 (le 1er étant le nom du script)

ser = serial.Serial('/dev/ttyACM0', 9600) # on établie la communication entre le raspberry pi et l'arduino

ser.write(str(argument2)) # on envoie l'argument2 à l'arduino