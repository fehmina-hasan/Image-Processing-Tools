/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: comp_main.c 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


#include "../include/ImageIO_TGA.h"
#include "../include/ImageIO.h"
#include "../include/RasterImage.h"
#include "../include/comp.h"

int main(int argc, char* argv[]){

	//reads 1st image from input
	RasterImage img1 = readImage(argv[1]);

	//reads 2nd image from input
	RasterImage img2 = readImage(argv[2]);

	int value = 0;
	//calls comp from comp.c
	int result = comp(img1,img2,value);

	if(result == 1) printf("images are not identical\n");
	else printf("images are identical!\n");

	printf("Done!\n");
	return result;
}