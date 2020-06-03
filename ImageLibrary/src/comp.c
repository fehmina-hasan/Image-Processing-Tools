/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: comp.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/comp.h"


/**	Compare two Images to see if they are identical or not
 * @param img1		The first Image 
 * @param im2		The second Image
 * @param result	Stores a value of either 0: identical or 1: not identical
 */
int comp(RasterImage img1, RasterImage img2, int value){

	//store the raster
	unsigned char* imgRaster1 = img1.raster;
	unsigned char* imgRaster2 = img2.raster;

	if(img1.width != img2.width ) value = 1;
	
	if(img1.height != img2.height ) value = 1;
	
	//compare pixel by pixel
	for(unsigned int i = 0; i < imgRaster1[img1.width]; i++){
		for(unsigned int j = 0; j <imgRaster2[img2.height]; j++){
			if(imgRaster1[i*img1.bytesPerRow + 4*j] != imgRaster2[i*img2.bytesPerRow + 4*j]) value = 1;
			else if(imgRaster1[i*img1.bytesPerRow + 4*j + 1] != imgRaster2[i*img2.bytesPerRow + 4*j + 1]) value = 1;
			else if(imgRaster1[i*img1.bytesPerRow + 4*j + 2] != imgRaster2[i*img2.bytesPerRow + 4*j + 2]) value = 1;
			else if(imgRaster1[i*img1.bytesPerRow + 4*j + 3] != imgRaster2[i*img2.bytesPerRow + 4*j + 3]) value = 1;
		}
	}
	return value;
}


