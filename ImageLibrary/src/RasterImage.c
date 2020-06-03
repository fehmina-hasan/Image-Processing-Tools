/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: RasterImage.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include "../include/ImageIO_TGA.h"
#include "../include/RasterImage.h"
#include "../include/ImageIO.h"


/**	Writes a new Image with all the allocated raster content
 * @param filePath	pointer to the file path
 */
RasterImage readImage(char* filePath){

	if(strcmp( (filePath + strlen(filePath) - 4 ),".tga") == 0){
		
		RasterImage picture;
		ImageType type;
		unsigned short int width;
		unsigned short int height;

		picture.raster = readTGA(filePath, &width, &height, &type);

		picture.width = width;

		picture.height = height;

		picture.type = type;

		//Taken from main.c
		switch (picture.type){

			case RGBA32_RASTER:
				picture.bytesPerPixel = 4;
				break;
				
			case GRAY_RASTER:
				picture.bytesPerPixel = 1;
				break;

			case FLOAT_RASTER:	
				picture.bytesPerPixel = 4;
				break;
		}

		picture.bytesPerRow = picture.bytesPerPixel * width;

		char** r2D = (char**) calloc(height , sizeof(char*));

		//Taken from the lab05 excersize to fit this assignment
		for(int i = 0; i < height; i++){
			r2D[i] = picture.raster + i * picture.bytesPerRow;
		}

		picture.raster2D = (void*)r2D;


		return picture;
	}

	else{
		printf("File needs to have the .tga extension \n");
		exit(0);
	}
}

/**	Writes a new Image with all the allocated raster content
 * @param width		width of the new image created 
 * @param height	Height of the new image created
 * @param type		type of new image created
 * @param wordSizeRowPadding 	(ignore)
 */
RasterImage newImage(unsigned short width, unsigned short height, ImageType type, unsigned char wordSizeRowPadding){
	
	RasterImage picture;

	picture.width = width;

	picture.height = height;

	picture.type = type;

	switch (picture.type){
		case RGBA32_RASTER:
			picture.bytesPerPixel = 4;
			break;
			
		case GRAY_RASTER:
			picture.bytesPerPixel = 1;
			break;

		case FLOAT_RASTER:
			picture.bytesPerPixel = 4;
			break;	
	}

	picture.bytesPerRow = picture.bytesPerPixel * width;

	picture.raster = (void*) malloc(height*picture.bytesPerRow);

	unsigned char** r2D = (unsigned char**) malloc(height * sizeof(char*));

	for(int i = 0; i < height; i++){
		r2D[i] = picture.raster + i * picture.bytesPerRow;
	}

	picture.raster2D = (void*)r2D;

	return picture;
}

/**	Writes a new Image with all the allocated raster content
 * @param filePath	pointer to the file path
 * @param picture	pointer to the RasterImage object to filled.
 */
int writeImage(char* filePath, RasterImage* picture){

	if(strcmp(filePath + strlen(filePath) - 4,".tga") == 0){
		return writeTGA(filePath, picture->raster, picture->width, picture->height, picture->type);
	}
	else{
		printf("File needs to have the .tga extension\n");
		return 0;
	}
	
}

/**	Frees all heap-allocated storage for a Rasterimage object
 *	@param img	pointer to the RasterImage object to delete.
 */
void freeImage(RasterImage* picture){
	//free-ing all the heap allocated storage in reverse chronological order as discussed in lab05
	//to be on the safe side and have everything freed
	free(picture->raster2D);
	free(picture->raster);
	free(picture);

}

