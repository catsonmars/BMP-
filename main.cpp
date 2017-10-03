#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>

using namespace std;
#pragma warning (disable : 4996)



struct RGBType {
	double r;
	double g;
	double b;
};

int main()
{
	

	unsigned int width = 2, height = 2;
	unsigned int bpp = 24;
	unsigned int rowsize = ((bpp*width + 31) / 32) * 4;
	unsigned int area = width*height;
	unsigned int sizeOfArr = rowsize *height;
	unsigned int fileSize = 54 + sizeOfArr;

	unsigned int resolution = 2835;//see wiki. 72dpi* 39.3701 in/meter

	unsigned char bmpfileheader[14] = { 'B','M',   0,0,0,0 ,   0,0,0,0 ,   54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0,   2,0,0,0 ,   2,0,0,0 ,   0,0,24,0 };

	RGBType *pixel = new RGBType[area];//for the last for bytes in the bmpfileheader. Tells header where the starting address is for the array




	//bmpfileheader[2] = (unsigned char)(fileSize); //this was giving me an F in my file
	//bmpfileheader[3] = (unsigned char)(fileSize >> 8);
	


	
	//bmpinfoheader[4] = (unsigned char)(width);
	//bmpinfoheader[5] = (unsigned char)(width) >> 8;

	//bmpinfoheader[8] = (unsigned char)(height);
	//bmpinfoheader[5] = (unsigned char)(height) >> 8;
	
	bmpinfoheader[25] = (unsigned char)(resolution);      //horizontal resolutions
	bmpinfoheader[26] = (unsigned char)(resolution) >> 16;
	bmpinfoheader[27] = (unsigned char)(resolution) >> 24;


	bmpinfoheader[29] = (unsigned char)(resolution);      //vertical resolutions
	bmpinfoheader[30] = (unsigned char)(resolution) >> 16;
	bmpinfoheader[31] = (unsigned char)(resolution) >> 24;

	FILE *f = fopen("image1.bmp", "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);

	

	unsigned char pix[16] = {0, 0,255, 255,255,255 ,0,0,  255,0,0 ,0,255,0 ,0,0, };


	

	fwrite(pix, 1, 16, f);
	



	system("open Image1.bmp");
	return 0;
}
