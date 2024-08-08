import cv2
import numpy as np

cap = cv2.VideoCapture("/dev/video2")

while True:

    ret, frame = cap.read()
    if not ret:
        break


    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_yellow = np.array([20, 100, 100])
    upper_yellow = np.array([30, 255, 255])

    mask = cv2.inRange(hsv_frame, lower_yellow, upper_yellow)

    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    if contours:
        largest_contour = max(contours, key=cv2.contourArea)
        x, y, w, h = cv2.boundingRect(largest_contour)

        cropped_frame = frame[y:y+h, x:x+w]
        
        cv2.imshow('Cropped Frame', cropped_frame)
    else:

        cv2.imshow('Cropped Frame', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
