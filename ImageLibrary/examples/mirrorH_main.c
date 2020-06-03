/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: mirrorH_main.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/mirrorH.h"

int main(int argc, char* argv[]){

	//Make sure we get the right amount of arguments
	if(argc != 3){
		printf("Not the right amount of arguments. \n");
	}

	//reads 1st image from input
	RasterImage img = readImage(argv[1]);

	//create a new image
	RasterImage copy = newImage(img.width, img.height, img.type,0);

	//call the mirrorH function from mirrorH.c
	mirrorH(img,&copy);



/*This is the code used to display the output image name
	e.g bottles [MirrorH].tga
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
	char* edit = " [mirrorH]";

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
	int output = writeImage(outputDirectory, &copy);
    if (output != 0) printf("Writing out of the image failed.\n");
	
    printf("Done!\n");

	return 0;
}