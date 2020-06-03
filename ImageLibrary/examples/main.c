//====================================================================================
//	Simple demo program for reading and writing image files.
//====================================================================================

/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>  

#include "../include/ImageIO_TGA.h"
#include "../include/RasterImage.h"
#include "../include/ImageIO.h"



int main(int argc, char* argv[]){

	//read the image
	RasterImage image = readImage(argv[1]);

	//create a new image
	RasterImage copyImage = newImage(image.width, image.height, image.type,0);

	//assign the rasters
	unsigned char* imgRaster = (unsigned char*)image.raster;
	unsigned char* copyRaster = (unsigned char*)copyImage.raster;

	unsigned int imgBytesPerRow;

	imgBytesPerRow = image.width * 4;

	//Using the same for loop structure and execution as Prof. Herve had in his main.c file
	for (unsigned short i=0; i< image.height; i++){
		for (unsigned short j=0; j< image.width; j++){
			copyRaster[i*imgBytesPerRow + 4*j] = imgRaster[i*imgBytesPerRow + 4*j];
			copyRaster[i*imgBytesPerRow + 4*j + 1] = 0;
			copyRaster[i*imgBytesPerRow + 4*j + 2] = imgRaster[i*imgBytesPerRow + 4*j + 2];
			copyRaster[i*imgBytesPerRow + 4*j + 3] = imgRaster[i*imgBytesPerRow + 4*j + 3];
		}
	}
	


	/*This is the code used to display the output image name
	e.g bottles [gray].tga
*/
	char* arg1 = argv[1];
	int nameSize = 0;
	int slash = 0;

	char* name = (char*)calloc(strlen(argv[1])*2,sizeof(char));
	char* nameShortened = (char*)calloc(strlen(argv[1]),sizeof(char));

	for(unsigned int i = strlen(arg1) - 4; i >= 0; i--){
		char* temp = (char*)calloc(strlen(argv[1]),sizeof(char));
		strcat(temp,"/");
		strcat(temp, &arg1[i+1]);
		if(strcmp(&arg1[i], temp ) == 0 ) {
			slash = i;
			break;
		}
		nameSize++;
	}

	strcpy(nameShortened,arg1);

	for(unsigned int i = strlen(arg1) - 4 ; i > slash -1 ; i--) strcpy(nameShortened,&arg1[i]);
		
  	name = strndup(nameShortened, strlen(nameShortened)-4);
	char* outputDirectory = (char*)calloc(strlen(argv[2])+ nameSize,sizeof(char));

	strcat(outputDirectory, argv[2]);

	char* directory = argv[2];
	char* edit = " [main]";

	if(strcmp(&directory[strlen(directory)-1],"/") == 0){
		strcat(outputDirectory, name);
		strcat(outputDirectory, edit);
		strcat(outputDirectory, ".tga");
	}
	else{
		strcat(outputDirectory, "/");
		strcat(outputDirectory, name);
		strcat(outputDirectory, edit);
		strcat(outputDirectory, ".tga");
	}


	//output the image in the desired directory as a tga file.
    int outErr = writeImage(outputDirectory, &copyImage);
    if (outErr !=0) printf("Writing out of the image failed.\n");
    printf("Done!\n");
	
    return 0;
}

