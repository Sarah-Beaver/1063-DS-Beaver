/**
* @ProgramName: Program-2
* @Author: Sarah Beaver 
* @Description: 
*     This program reads in images stored as rgb values and uses them as an object
*     from a class.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date:  14 02 2017
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;
    int g;
    int b;
};

class ImageManip{
private:
    rgb** image;
    int width;
    int height;
    ifstream infile;
    ofstream ofile;
    string ifile_name;
    string ofile_name;
/**
* @FunctionName: readFile
* @Description: 
*     gets the values from the picture
* @Params:
*    none
* @Returns:
*    void
*/
    void readFile(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            infile>>image[i][j].r>>image[i][j].g>>image[i][j].b;            
        }
     }
    }
/**
* @FunctionName: writeFile
* @Description: 
*     prints out the rbgs from the pointer arrys
* @Params:
*    none
* @Returns:
*    void
*/
    void writeFile(){
       //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<image[i][j].r<<" "<<image[i][j].g<<" "<<image[i][j].b<<" ";
        }
        ofile<<endl;
    }
    }

public:
    ImageManip(){
      infile.open("test.txt");
      ofile.open("output.txt");
      infile>>height>>width;
      image = new rgb*[height];
    for(int i=0;i<height;i++)
    {
        image[i] = new rgb[width]; 
    }
    
    readFile();
    }
/**
* @FunctionName: flipVert
* @Description: 
*     Loops through a 2D array and switches each column across the vertical
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
    void flipVert(){

        int temp;
    for(int i=0;i<height/2;i++)
    {
      for(int j=0;j<width;j++)
      {
        temp=image[i][j].r;
        image[i][j].r=image[height-1-i][j].r;
        image[height-1-i][j].r=temp;
        temp=image[i][j].g;
        image[i][j].g=image[height-1-i][j].g;
        image[height-1-i][j].g=temp;
        temp=image[i][j].b;
        image[i][j].b=image[height-1-i][j].b;
        image[height-1-i][j].b=temp;
      }
    }
    writeFile();
    }
/**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and switches each row across the horizontal
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
    void flipHorz(){
         rgb temp;
    for(int i=0;i<height;i++)
    {
      for(int j=0;j<width/2;j++)
      {
        temp.r=image[i][j].r;
        temp.g=image[i][j].g;
        temp.b=image[i][j].b;
        image[i][j].r=image[i][width-j-1].r;
        image[i][j].g=image[i][width-j-1].g;
        image[i][j].b=image[i][width-j-1].b;
        image[i][width-j-1].r=temp.r;
        image[i][width-j-1].g=temp.g;
        image[i][width-j-1].b=temp.b;
      }
    }
    writeFile();
    }
/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
    void grayScale(){
        int temp;
    for(int i=0;i<height;i++)
    {
      for(int j=0;j<width;j++)
      {
        temp=(image[i][j].r+image[i][j].g+image[i][j].b)/3;
        image[i][j].r=temp;
        image[i][j].g=temp;
        image[i][j].b=temp;
      }
    } 
    writeFile();
    }
    ~ImageManip(){
      delete image;
    }
};

int main(){
    ImageManip picture;
    picture.grayScale();
    picture.flipVert();
    picture.flipHorz();
  return 0;
}
