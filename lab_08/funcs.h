#pragma once

using std::string;

void readImage(int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(string filename, int image[MAX_H][MAX_W], int height, int width);
void invert(string filename, int image[MAX_H][MAX_W], int height, int width);
void invert_half (string filename, int image[MAX_H][MAX_W], int height, int width);
void box (string filename, int image[MAX_H][MAX_W], int height, int width);
void frame (string filename, int image[MAX_H][MAX_W], int height, int width);
void scale (string filename, int image[MAX_H][MAX_W], int height, int width);
void pixelate (string filename, int image[MAX_H][MAX_W], int height, int width);
