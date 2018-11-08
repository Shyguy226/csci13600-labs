#include <iostream>
const int MAX_H = 512;
const int MAX_W = 512;
#include "funcs.h"

using std::endl;
using std::cout;
using std::string;



int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = img[row][col];
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage("outImage.pgm", out, h, w);
	invert("invert.pgm", out, h, w);
	invert_half("inverthalf.pgm", out, h, w);
	box("box.pgm", out, h, w);
	frame("frame.pgm", out, h, w);
	scale("scale.pgm", out, h, w);
	pixelate("pixel.pgm", out, h, w);
}
  
