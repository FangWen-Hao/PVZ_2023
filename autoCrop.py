import os
import cv2

# Change the following variables to your needs
FOLDER_PATH = "Resources/Zombies/BMP/DeadState/BoomDie"
BACKGROUND_COLOR = (255, 255, 255)
####################

FILES_PATH = os.listdir(FOLDER_PATH)
INF = float("inf")

offsets = {"TOP": INF, "BOTTOM": INF, "LEFT": INF, "RIGHT": INF}
images = [cv2.imread(FOLDER_PATH + "/" + file) for file in FILES_PATH]

def getOffset(image):
    def getTopOffset(image):
        for y in range(image.shape[0]):
            for x in range(image.shape[1]):
                if not (image[y, x] == BACKGROUND_COLOR).all():
                    return y
                
    def getBottomOffset(image):
        for y in range(image.shape[0] - 1, -1, -1):
            for x in range(image.shape[1]):
                if not (image[y, x] == BACKGROUND_COLOR).all():
                    return image.shape[0] - y
            
    def getLeftOffset(image):
        for x in range(image.shape[1]):
            for y in range(image.shape[0]):
                if not (image[y, x] == BACKGROUND_COLOR).all():
                    return x
    
    def getRightOffset(image):
        for x in range(image.shape[1] - 1, -1, -1):
            for y in range(image.shape[0]):
                if not (image[y, x] == BACKGROUND_COLOR).all():
                    return image.shape[1] - x

    offsets["TOP"] = min(offsets["TOP"], getTopOffset(image))
    offsets["BOTTOM"] = min(offsets["BOTTOM"], getBottomOffset(image) - 1)
    offsets["LEFT"] = min(offsets["LEFT"], getLeftOffset(image))
    offsets["RIGHT"] = min(offsets["RIGHT"], getRightOffset(image) - 1)

for image in images:
    getOffset(image)

for i, image in enumerate(images):
    crop_image = image[offsets["TOP"]:image.shape[0] - offsets["BOTTOM"], offsets["LEFT"]:image.shape[1] - offsets["RIGHT"]]
    cv2.imwrite(FOLDER_PATH + "/" + FILES_PATH[i], crop_image)
