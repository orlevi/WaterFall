#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Binarize (make it black and white) an image with Pyhton."""

from PIL import Image
from scipy.misc import imsave
import numpy
import ntpath
import os
import cv2

WIDTH = 100
ASPECT_RATIO_MULT = 4 # ( orig_width/orig_height * ASPECT_RATIO_MULT is the new aspect ratio )

def resize_image(img):
    width, height = img.size
    img = numpy.array(img)
    new_width = WIDTH
    new_height = int(round(height / width * new_width * ASPECT_RATIO_MULT))
    print new_width, new_height
    size = new_width, new_height
    # im.resize(size)
    img = cv2.resize(img, size, interpolation=cv2.INTER_CUBIC)
    return img

def binarize_image(img_path, target_path, threshold):
    """Binarize an image."""
    image_file = Image.open(img_path)
    full_file_name = ntpath.basename(img_path)
    filename, file_extension = os.path.splitext(full_file_name)
    image = image_file.convert('L')  # convert image to monochrome
    image = resize_image(image)
    image = binarize_array(target_path, filename, image, threshold)
    print image
    imsave(target_path + filename + ".png", image)


def binarize_array(file_path, filename, numpy_array, threshold=200):
    """Binarize a numpy array."""
    arr = []
    for i in range(len(numpy_array)):
        new = []
        for j in range(len(numpy_array[0])):
            if numpy_array[i][j] > threshold:
                numpy_array[i][j] = 255
                new.append(1)
            else:
                numpy_array[i][j] = 0
                new.append(0)
        arr.append(new)
    print arr
    numpy.savetxt(file_path + filename + ".csv", arr, fmt = '%i', delimiter=",")
    return numpy_array


def get_parser():
    """Get parser object for script xy.py."""
    from argparse import ArgumentParser, ArgumentDefaultsHelpFormatter
    parser = ArgumentParser(description=__doc__,
                            formatter_class=ArgumentDefaultsHelpFormatter)
    parser.add_argument("-i", "--input",
                        dest="input",
                        help="read this file",
                        metavar="FILE",
                        required=True)
    parser.add_argument("-o", "--output",
                        dest="output",
                        help="write binarized file hre",
                        metavar="FILE",
                        required=True)
    parser.add_argument("--threshold",
                        dest="threshold",
                        default=200,
                        type=int,
                        help="Threshold when to show white")
    return parser


if __name__ == "__main__":
    args = get_parser().parse_args()
    binarize_image(args.input, args.output, args.threshold)