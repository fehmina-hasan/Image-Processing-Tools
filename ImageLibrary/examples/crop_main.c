/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
25th Feb 2020
File name: crop_main.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/crop.h"

int main(int argc, char* argv[]){
    
    if (argc != 7){                                          
        printf("Not the right amount of arguments.\n");
        exit(0);
    }

   
    if (argv[1] < 0 || argv[2] < 0 || argv[3] < 0 || argv[4] < 0){// checking for negative ints
        printf("The arguments are not valid \n");
        exit(EXIT_FAILURE);
    }

    unsigned short ULx = atoi(argv[3]); // x coordinate
    unsigned short ULy = atoi(argv[4]); // y coordinate
    unsigned short LRx = atoi(argv[5]); // width value
    unsigned short LRy = atoi(argv[6]); // height value

    //reads 1st image from input
    RasterImage img = readImage(argv[1]);

    //create a new image
    RasterImage copy = newImage((ULx + LRx), (ULy + LRy), img.type,0);

    //calls the crop function from the crop.c file
    crop(img, &copy, ULx, ULy, LRx, LRy);


/*This is the code used to display the output image name
    e.g bottles [crop].tga
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
    char* edit = " [crop]";

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