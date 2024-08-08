import cv2
import numpy as np

camera = cv2.VideoCapture(0)

min_rgb_color = 0
max_rgb_color = 255

def nope():
    pass

cv2.namedWindow("Trackbars")
cv2.createTrackbar("H_min","Trackbars",0,180,nope)
cv2.createTrackbar("H_max","Trackbars",180,180,nope)
cv2.createTrackbar("S_min","Trackbars",0,max_rgb_color,nope)
cv2.createTrackbar("S_max","Trackbars",255,max_rgb_color,nope)
cv2.createTrackbar("V_min","Trackbars",0,max_rgb_color,nope)
cv2.createTrackbar("V_max","Trackbars",255,max_rgb_color,nope)

while True:
    h_min = cv2.getTrackbarPos("H_min","Trackbars")
    h_max = cv2.getTrackbarPos("H_max", "Trackbars")
    s_min = cv2.getTrackbarPos("S_min", "Trackbars")
    s_max = cv2.getTrackbarPos("S_max", "Trackbars")
    v_min = cv2.getTrackbarPos("V_min", "Trackbars")
    v_max = cv2.getTrackbarPos("V_max", "Trackbars")

    _,img = camera.read()
    img2 = cv2.inRange(cv2.cvtColor(img,cv2.COLOR_BGR2HSV), np.array([h_min,s_min,v_min]), np.array([h_max,s_max,v_max]))
    cv2.imshow("IMG",img)
    cv2.imshow("IMG2",img2)
    cv2.waitKey(1)