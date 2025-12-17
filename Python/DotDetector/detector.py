import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# other path for my webcam: path = "/dev/v4l/by-id/usb-046d_HD_Webcam_C525_C0C86EA0-video-index0"
path = "/home/java/Videos/Competition Videos/Dot Detector Data/Tagged, Red.mp4"
capture = cv.VideoCapture(path)

# spooky mystery variable that I forgot what it does
i = 0

# thresholds for binary thresholding
max_thresh = 255
thresh = 75

# dilation and erosion strength
erosion_strength = 8
dilation_strength = 8

# iterations of dilating and erosion to reduce noise
iterations = 10

# lower and upper bounds for dot detection
s1 = 100
s2 = 1000

# display scaling factor
scaling_factor = 1

while True:

    ret, Frame = capture.read()

    if ret == True:

        # displays original input
        resize_original = cv.resize(Frame, None, fx=scaling_factor, fy=scaling_factor, interpolation=cv.INTER_LINEAR)
        cv.imshow('Original', resize_original)

        # dots is the contour of the dots
        dots = []

        # sets display to frame for later purposes
        Display = Frame

        # makes a grayscale feed
        gray = cv.cvtColor(Frame, cv.COLOR_BGR2GRAY)

        # threshold
        th, threshed = cv.threshold(gray, thresh, max_thresh, cv.THRESH_BINARY)

        # remove noise via dilation and erosion
        erosion_kernel = np.ones((erosion_strength, erosion_strength), np.uint8)
        dilation_kernel = np.ones((dilation_strength, dilation_strength), np.uint8)
        for i in range(0, iterations):
            threshed = cv.erode(threshed, erosion_kernel)
            threshed = cv.dilate(threshed, dilation_kernel)

        # findcontours
        cnts = cv.findContours(threshed, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)[-2]


        # detects all dots and appends it to dots, adds text onto all dots
        for cnt in cnts:
            if s1 < cv.contourArea(cnt) < s2:
                M = cv.moments(cnt)
                cX = int(M["m10"] / M["m00"])
                cY = int(M["m01"] / M["m00"])
                cv.putText(Display, str(cv.contourArea(cnt)), (cX - 20, cY - 20), cv.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 1)
                dots.append(cnt)

        # appends the current sum of dots onto dot_sum
        with open("output.txt", "a") as output:
            output.write(str(i) + " "  + str(len(dots)) + "\n")
            # mystery variable strikes again (it adds the index for each entry in output)
            i = i + 1

        # draws green lines on contours, blue borders on dots
        cv.drawContours(Display, cnts, -1, (0, 255, 0), 3)
        cv.drawContours(Display, dots, -1, (255, 0, 0), 5)

        # resizes display
        resize_display = cv.resize(Display, None, fx=scaling_factor, fy=scaling_factor, interpolation=cv.INTER_LINEAR)
        resize_gray = cv.resize(gray, None, fx=scaling_factor, fy=scaling_factor, interpolation=cv.INTER_LINEAR)
        resize_threshed = cv.resize(threshed, None, fx=scaling_factor, fy=scaling_factor, interpolation=cv.INTER_LINEAR)

        # shows the frame
        cv.imshow('Result', resize_display)
        cv.imshow('Gray', resize_gray)
        cv.imshow('Threshold Map', resize_threshed)

        # ends program when q is pressed
        if cv.waitKey(30) & 0xFF == ord('q'):
            break

    else:
        break

cv.destroyAllWindows()
