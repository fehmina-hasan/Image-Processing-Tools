#!/bin/bash

#Name: Fehmina Hasan
#Prof. Herve
#Script 03



chmod 755 script01.sh

echo "Prog03 Bash Script 03"

path=$1

path2=$2

INCLUDE=-I$path/include
SRC=$path/src
EXAMPLE=$path/examples
LIBS="-Llib -lImageTGA"    

TARGET=lib/libImageTGA   #Putting the library in a folder called lib

export LD_LIBRARY_PATH!=$path/lib:$LD_LIBRARY_PATH 


var=$(find "$path2" -mindepth 1 -name "*.tga")

var3="images are identical!"

for filename in "$var"; do
	for filename2 in "$var"; do
		gcc -g3 $INCLUDE $EXAMPLE/comp_main.c $TARGET.a -o comp 
		var2=$(./comp $filename $filename2)
		echo "$var2"
		if [ "$var2" = "$var3" ];then
			echo "$filename" 
			echo "$filename2"
		fi
	done
done



