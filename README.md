# Image-Processing-Tools

In this project I used C to implement the basic utility functions of the Image Processing Tools. Given a TGA extension image file and depending on the users choice the image can be converted into a grayscale image, a horizontal or vertical mirrored image, a cropped image or just be compared to a different image to see if its similar or not.


## Implementation

In order to test out the code and use these basic tools to edit your Image follow the steps below:
• Open Terminal and navigate into the scripts folder directory
• Type "bash script01.sh ../ImageLibrary"
• Now that the ImageLibrary is all loaded and compiled, use any of the command lines below to execute the utilities:
{./utility}  {Image directory}  {Output directory} 
./gray ../../Images/Renoir.tga ../Output/
./mirrorH ../../Images/Renoir.tga ../Output/
./mirrorV ../../Images/Renoir.tga ../Output/
./comp ../../Images/Renoir.tga ../../Images/bottles.tga
./crop ../../Images/Renoir.tga ../Output/ 145 20 97 150
        
 
## File Details

### Include Folder

• ImageIO_tga.h is respectively the header file of functions to read and write color and gray-level images in the uncompressed TGA format.

• RasterImage.h is a header file that define some new data types and functions.

• ImageIO.h contains the declaration of two functions that are implemented in RasterImage.c.

• gray.h is the header file for the gray utility

• comp.h is the header file for the compare utility

• crop.h is the header file for the crop utility

• mirrorH is the header file for the horizontal mirror utility

• mirrorV is the header file for the vertical mirror utility

### Src Folder

• RasterImage.c implements all the data and functions listed in it's header file.

• ImageIO_tga.c is the source file that implements all the functions to read and write color and gray-level images in the uncompressed TGA format

• gray.c is the source file that implements the gray utility

• comp.c is the source file that implements the compare utility

• crop.c is the source file that implements the crop utility

• mirrorH.c is the source file that implements the horizontal mirror utility

• mirrorV.c is the source file that implements the vertical mirror utility

### Examples Folder

• contains the main.c file for all the utilities respectively in order to call on which utility is to be used

