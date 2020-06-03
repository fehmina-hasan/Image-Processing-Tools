/**
Name: Fehmina Hasan
CSC 412 
Prof. Herve
4th March 2020
File name: crop.h 
*/

#ifndef	CROP_H
#define	CROP_H

#include "RasterImage.h"


void crop(RasterImage Original, RasterImage* copy , unsigned short ULx, unsigned short ULy, unsigned short LRx, unsigned short LRy);

#endif	//	CROP_H