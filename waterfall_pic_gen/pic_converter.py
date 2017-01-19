import os, sys
from PIL import Image
import cv2

from imageresize import imageresize

WIDTH = 100
ASPECT_RATIO_MULT = 1.2 # ( orig_width/orig_height * ASPECT_RATIO_MULT is the new aspect ratio )


for infile in sys.argv[1:]:
    outfile = os.path.splitext(infile)[0] + ".jpg"
    if infile != outfile:
        try:
            im = Image.open(infile)
            print type(im)
            # im = im.convert('1')  # convert image to black and white
            width, height = im.size
            new_width = WIDTH
            new_height = int(round(height / width * new_width * ASPECT_RATIO_MULT))
            print new_width,new_height
            size = new_width , new_height
            # im.resize(size)
            im = cv2.resize(im, size, interpolation=cv2.INTER_CUBIC)
            # im = imageresize.resize_cover(im,size)
            im.save(outfile, "JPEG")
        except IOError:
            print "cannot create thumbnail for '%s'" % infile