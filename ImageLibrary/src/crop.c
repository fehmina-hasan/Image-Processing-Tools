/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
25th Feb 2020
File name: crop.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/mirrorV.h"


/** Crop the Image according to the measurements entered
 * @param Original  RasterImage of an image
 * @param copy      pointer to an RasterImage image
 * @param ULx       Upper Left X co-ordinate
 * @param ULy       Upper Left Y co-ordinate
 * @param LRx       Lower Right X co-ordinate
 * @param LRy       Lower Right Y co-ordinate
 */
void crop(RasterImage Original, RasterImage* copy , unsigned short ULx, unsigned short ULy, unsigned short LRx, unsigned short LRy){
    unsigned char* imgRaster = (unsigned char*)Original.raster;
    unsigned char* copyRaster = (unsigned char*)copy->raster;

    for(unsigned short i = 0; i < copy->height; i++){
        for(unsigned short j = 0; j < copy->width; j++){
            copyRaster[i*copy->bytesPerRow + 4*j] = imgRaster[ ( i + ULx )*Original.bytesPerRow + 4* (j + ULy ) ];
            copyRaster[i*copy->bytesPerRow + 4*j + 1] = imgRaster[( i + ULx )*Original.bytesPerRow + 4* (j + ULy ) + 1];
            copyRaster[i*copy->bytesPerRow + 4*j + 2] = imgRaster[( i + ULx )*Original.bytesPerRow + 4* (j + ULy ) + 2];
            copyRaster[i*copy->bytesPerRow + 4*j + 3] = imgRaster[( i + ULx )*Original.bytesPerRow + 4* (j + ULy ) + 3];
        }
    }

}