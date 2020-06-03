/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: gray.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/gray.h"



/**	Function used to turn the Image gray
	@param Original	RasterImage of an image
	@param copy    	pointer to an RasterImage image
 */
void gray(RasterImage Original, RasterImage* copy){
	//Access to rasters
	unsigned char* imgRaster = (unsigned char*)Original.raster;
	unsigned char* copyRaster = (unsigned char*)copy->raster;

	unsigned int imgBytesPerRow;

	imgBytesPerRow = Original.width * 4;

	for(unsigned int i = 0; i < Original.height; i++){
			for(unsigned int j = 0; j < Original.width; j++){

				copyRaster[i*imgBytesPerRow + 4*j] = imgRaster[i*imgBytesPerRow + 4*j + 1/3];
				copyRaster[i*imgBytesPerRow + 4*j + 1] = imgRaster[i*imgBytesPerRow + 4*j + 1/3];
				copyRaster[i*imgBytesPerRow + 4*j + 2] = imgRaster[i*imgBytesPerRow + 4*j + 1/3];
				copyRaster[i*imgBytesPerRow + 4*j + 3] = imgRaster[i*imgBytesPerRow + 4*j + 3];
			}
		}
}

