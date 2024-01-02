
import cv2 as cv
from matplotlib import pyplot as plt
import numpy as np
img = cv.imread('x.jpg',0)

equalize = cv.equalizeHist(img)
clahe=cv.createCLAHE(clipLimit=2.0,tileGridSize=(8,8))
cl1=clahe.apply(img) 
# display images


histogram_img = cv.calcHist([img],[0],None,[256],[0,256])
histogram_equ=cv.calcHist([equalize],[0],None,[256] , [0,256] )
histogram_cl=cv.calcHist([cl1],[0],None,[256] ,[0,256])


#display images 
images=[img,histogram_img,equalize,histogram_equ,cl1,histogram_cl]
titles = ['Original Image', 'Original Histogram', 'Equalized Image', 'Equalized Histogram', 'CLAHE Image', 'CLAHE Histogram']
#plt.figure(figsize=(12, 8))

for i in range(6):
    if i % 2 == 0:
        plt.subplot(3,2 ,i + 1)
        plt.imshow(images[i] , cmap="gray")
        plt.title(titles[i])
        #plt.xticks([]), plt.yticks([])
    else:
        plt.subplot(3,2, i + 1)
        plt.plot(images[i])
        plt.title(titles[i]) 



plt.show()

