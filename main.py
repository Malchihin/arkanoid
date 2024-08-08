import cv2
import numpy as np

camera = cv2.VideoCapture(1)

min_rgb_color = 0
max_rgb_color = 255

def nope():
    pass

cv2.namedWindow("Trackbars")
cv2.createTrackbar("R_min","Trackbars",0,max_rgb_color,nope)
cv2.createTrackbar("R_max","Trackbars",0,max_rgb_color,nope)
cv2.createTrackbar("G_min","Trackbars",0,max_rgb_color,nope)
cv2.createTrackbar("G_max","Trackbars",0,max_rgb_color,nope)
cv2.createTrackbar("B_min","Trackbars",0,max_rgb_color,nope)
cv2.createTrackbar("B_max","Trackbars",0,max_rgb_color,nope)

while True:
    r_min = cv2.getTrackbarPos("R_min","Trackbars")
    r_max = cv2.getTrackbarPos("R_max", "Trackbars")
    g_min = cv2.getTrackbarPos("G_min", "Trackbars")
    g_max = cv2.getTrackbarPos("G_max", "Trackbars")
    b_min = cv2.getTrackbarPos("B_min", "Trackbars")
    b_max = cv2.getTrackbarPos("B_max", "Trackbars")

    _,img = camera.read()
    img2 = cv2.inRange((img,cv2.COLOR_BGR2HSV), np.array([b_min,g_min,r_min]), np.array([b_max,g_max,r_max]))
    cv2.imshow("IMG",img)
    cv2.imshow("IMG2",img2)
    cv2.waitKey(1)