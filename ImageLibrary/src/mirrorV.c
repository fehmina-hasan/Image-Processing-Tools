/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: mirrorV.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/mirrorV.h"

/**	Flip the Image Vertically
 * @param Original	RasterImage of an image
 * @param copy    	pointer to an RasterImage image
 */
void mirrorV(RasterImage Original, RasterImage* copy){
	
	//Access to rasters
	unsigned char* imgRaster = (unsigned char*)Original.raster;
	unsigned char* copyRaster = (unsigned char*)copy->raster;
	
	for(unsigned short i = 0; i < Original.height; i++){
		for(unsigned short j = 0; j < Original.width; j++){
			copyRaster[i*Original.bytesPerRow + 4*j] = imgRaster[(Original.height-i-1)*Original.bytesPerRow + 4*j];
			copyRaster[i*Original.bytesPerRow + 4*j + 1] = imgRaster[(Original.height-i-1)*Original.bytesPerRow + 4*j + 1];
			copyRaster[i*Original.bytesPerRow + 4*j + 2] = imgRaster[(Original.height-i-1)*Original.bytesPerRow + 4*j + 2];
			copyRaster[i*Original.bytesPerRow + 4*j + 3] = imgRaster[(Original.height-i-1)*Original.bytesPerRow + 4*j + 3];
		}
	}
}
