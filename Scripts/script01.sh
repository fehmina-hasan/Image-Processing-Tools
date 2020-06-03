#!/bin/bash

#Name: Fehmina Hasan
#Prof. Herve
#Script 01

# This script was completed with the help of Chris at his office hours so you might encounter similar scripts

chmod 755 script01.sh

echo "Prog03 Bash Script 01"

path=$1

INCLUDE=-I$path/include
SRC=$path/src
EXAMPLE=$path/examples
LIBS="-Llib -lImageTGA"    

TARGET=lib/libImageTGA   #Putting the library in a folder called lib

export LD_LIBRARY_PATH!=$path/lib:$LD_LIBRARY_PATH 

########################################################
#Creating the lib directory if it does not already exist

if [ ! -d lib ]; then
     mkdir lib
fi

#Creating the Output directory if it does not already exist
if [ ! -d Output ]; then
     mkdir Output
fi

#######################################################################################
#Building the Shared Library

gcc -shared -fPIC -g3 $INCLUDE $SRC/ImageIO_TGA.c $SRC/RasterImage.c $SRC/mirrorV.c $SRC/mirrorH.c $SRC/gray.c $SRC/comp.c $SRC/crop.c  -lm -o $TARGET.so  #call the normal ones here

if [ -f $TARGET.so ]; then
echo "success"
else 
echo "fail"
fi


#########################################################
#Build the Static Library

rm $TARGET.a
gcc -c $INCLUDE $SRC/ImageIO_TGA.c -o ImageIO_TGA.o
gcc -c $INCLUDE $SRC/RasterImage.c -o RasterImage.o 
gcc -c $INCLUDE $SRC/mirrorV.c -o mirrorV.o 
gcc -c $INCLUDE $SRC/mirrorH.c -o mirrorH.o 
gcc -c $INCLUDE $SRC/gray.c -o gray.o 
gcc -c $INCLUDE $SRC/comp.c -o comp.o
gcc -c $INCLUDE $SRC/crop.c -o crop.o

#add for all .c files in source

ar rcs $TARGET.a ImageIO_TGA.o RasterImage.o gray.o mirrorV.o mirrorH.o comp.o crop.o

if [ -f $TARGET.a ]; then 
  echo "$Target.a built successfully"
else 
   echo "Failed to build"
fi 


########################################################
#These are the commands to run all the utility programs

rm ImageIO_TGA.o RasterImage.o

#Build the Compare utility program
rm comp
gcc -g3 $INCLUDE $EXAMPLE/comp_main.c $TARGET.a -o comp   #instead target.a
if [ -f comp ]; then
	echo "comp_main.c built successfully"
else
	echo "comp_main.c was not built successfully"
fi


#Build the Gray utility program 
rm gray 
gcc -g3 $INCLUDE $EXAMPLE/gray_main.c $TARGET.a -o gray     
if [ -f gray ]; then
	echo "gray.c built successfully"
else
	echo "gray.c was not built successfully"
fi

#Build the MirrorV utility program 
rm mirrorV
gcc -g3 $INCLUDE $EXAMPLE/mirrorV_main.c $TARGET.a -o mirrorV
if [ -f mirrorV ]; then
	echo "mirrorV_main.c built successfully"
else
	echo "mirrorV_main.c was not built successfully"
fi

#Build the MirrorH utility program 
rm mirrorH
gcc -g3 $INCLUDE $EXAMPLE/mirrorH_main.c $TARGET.a -o mirrorH
if [ -f mirrorH ]; then
	echo "mirrorH_main.c built successfully"
else
	echo "mirrorH_main.c was not built successfully"
fi

#Build the Crop utility program 
rm crop
gcc -g3 $INCLUDE $EXAMPLE/crop_main.c $TARGET.a -o crop
if [ -f crop ]; then
	echo "crop_main.c built successfully"
else
	echo "crop_main.c was not built successfully"
fi

# gcc -g3 $INCLUDE $EXAMPLE/main.c $TARGET.a -o main
# if [ -f main ]; then
# 	echo "main.c built successfully"
# else
# 	echo "main.c was not built successfully"
# fi









