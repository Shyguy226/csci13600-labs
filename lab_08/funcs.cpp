/*
  Author: Andrew Giannico

  Description:
    The program reads a PGM image from the file "inImage.pgm",
    and outputs a modified image to "outImage.pgm"
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(string filename, int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

void invert(string filename, int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("invert.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << (255 - image[row][col]) << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

void invert_half (string filename, int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open("inverthalf.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;
  
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      if(col>width/2){
	ostr << (255 - image[row][col]) << ' ';
      }
      else{
	ostr << image[row][col] << ' ';
      }
	ostr << endl;
      }
    }
    ostr.close();
    return;
}

void box (string filename, int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open("box.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;
  
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      if(col>width/4 && col < (3 * width)/4 && row > height/4 && row < (3 * height)/4){
	ostr << 255  << ' ';
      }
      else{
	ostr << image[row][col] << ' ';
      }
	ostr << endl;
      }
    }
    ostr.close();
    return;
}

void frame (string filename, int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open("frame.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;
  
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      if((col == width/4 && row > height/4 && row < 3*height/4) || (col == (3 * width)/4 && row > height/4 && row < 3*height/4) || (row == height/4 && col > width/4 && col < width*3/4) || (row == height*3/4 && col > width/4 && col < width*3/4)){
	ostr << 255 << ' ';
      }
      else{
	ostr << image[row][col] << ' ';
      }
	ostr << endl;
      }
    }
    ostr.close();
    return;
}

void scale (string filename, int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open("scale.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  int counter = 0;
  bool flag = true;
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width*2 << ' ';
  ostr << height*2 << endl;
  ostr << 255 << endl;
  
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      ostr << image[row][col] << ' ';
      ostr << image[row][col] << ' ';
      ostr << endl;
    }
    for (int c = 0; c < width; c++){
      assert(image[row][c] < 256);
      assert(image[row][c] >= 0);
      ostr << image[row][c] << ' ';
      ostr << image[row][c] << ' ';
      ostr << endl;
    }
  }
  ostr.close();
  return;
}

void pixelate (string filename, int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open("pixel.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  int sumhold = 0;
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;
  
  for (int row = 0; row < height; row+=2) {
    for (int col = 0; col < width; col+=2) {
      assert(image[row][col] < 256);
      assert(image[row][col] >= 0);
      sumhold += image[row][col] + image[row][col+1] + image[row+1][col] + image[row+1][col+1];
      ostr << sumhold/4 << ' ';
      ostr << sumhold/4 << ' ';
      sumhold = 0;
      ostr << endl;
    }
    for (int c = 0; c < width; c+=2){
       assert(image[row][c] < 256);
      assert(image[row][c] >= 0);
      sumhold += image[row][c] + image[row][c+1] + image[row+1][c] + image[row+1][c+1];
      ostr << sumhold/4 << ' ';
      ostr << sumhold/4 << ' ';
      sumhold = 0;
      ostr << endl;
    }
  }
  ostr.close();
  return;
}
