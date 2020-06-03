/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: mirrorH.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/mirrorH.h"

/**	Flip the Image Horizontally
 * @param Original	RasterImage of an image
 * @param copy    	pointer to an RasterImage image
 */
void mirrorH(RasterImage Original, RasterImage* copy){

	//Access to rasters
	unsigned char* imgRaster = (unsigned char*)Original.raster;
	unsigned char* copyRaster = (unsigned char*)copy->raster;
	
	//convert the image horizontally
	for(unsigned short i = 0; i < Original.height; i++){
		for(unsigned short j = 0; j < Original.width; j++){
			copyRaster[i*Original.bytesPerRow + 4*j] = imgRaster[i *Original.bytesPerRow + 4* (Original.width-j)];
			copyRaster[i*Original.bytesPerRow + 4*j + 1] = imgRaster[i *Original.bytesPerRow + 4* (Original.width-j) + 1];
			copyRaster[i*Original.bytesPerRow + 4*j + 2] = imgRaster[i *Original.bytesPerRow + 4* (Original.width-j) + 2];
			copyRaster[i*Original.bytesPerRow + 4*j + 3] = imgRaster[i *Original.bytesPerRow + 4* (Original.width-j) + 3];
		}
	}
}




