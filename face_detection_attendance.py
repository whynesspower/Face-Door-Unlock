import cv2        #openCV
import numpy as np  # supportinig Lib for OpenCV
import face_recognition   #To Create Recognizer
import os  #To access Operating System
from datetime import datetime  # To get the system's Date and time
import time
import httplib2
http = httplib2.Http()

path = 'image_folder'
images = []
classNames = []
myList = os.listdir(path)
print(myList)
for cl in myList:
    curImg = cv2.imread(f'{path}/{cl}')
    images.append(curImg)   
    classNames.append(os.path.splitext(cl)[0])  
print(classNames)

def findEncodings(images):
    encodeList = []
    for img in images:
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        encode = face_recognition.face_encodings(img)[0]
        encodeList.append(encode)
    return encodeList

encodeListKnown = findEncodings(images)
print('Encoding Complete')

cap = cv2.VideoCapture(0)