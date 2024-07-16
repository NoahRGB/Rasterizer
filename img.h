#ifndef IMG_H
#define IMG_H

#include <string>
#include <iostream>
#include <fstream>

#include "colour.h"

// a class to represent an image of PPM format https://netpbm.sourceforge.net/doc/ppm.html
// has the capability to set a pixel to a specified colour and write the image to disk
// under a specified filename

class Img {
public:
  Img(int width, int height);

  void set(int x, int y, RGB col);
  bool write(const std::string filename);
  void clear();

private:

  unsigned char *pixels;
  int width;
  int height;

};

#endif