import cv2
import sys

#read the image to be dilated
image = cv2.imread("../assets/dilation.png")

#check if the input image exits
if image is None:
    print("Input image not found")
    sys.exit()

#Create a structiong element/kernel which will be used for dilation
dilationSize = 6
element = cv2.getStructuringElement(cv2.MORPH_CROSS, (2*dilationSize + 1, 2* dilationSize + 1), (dilationSize, dilationSize))

#Apply dilate function on input image. Dilation will increase brightness, First Parameter is the original image, 
#second is the dilated image
dilatedImage = cv2.dilate(image, element)

#Create windows to diaplay images
cv2.namedWindow("input image", cv2.WINDOW_NORMAL)
cv2.namedWindow("dilated image", cv2.WINDOW_NORMAL)

#Display the images
cv2.imshow("input image", image)
cv2.imshow("dilated image", dilatedImage)

#Press esc on keyboard to exit the program
cv2.waitKey(0)

#close all the opened windows
cv2.destroyAllWindows()