#include "img.h"

Img::Img(int width, int height) : width(width), height(height) {
  pixels = new unsigned char[width * height * 3];
  clear();
}

void Img::clear() {
  for (int i = 0; i < width * height * 3; i++) {
    pixels[i] = 0;
  }
}

void Img::set(int x, int y, RGB col) {
  // y = 2 means you are '2 widths' (rows) down the image
  // therefore width*2*3 (3 values per pixel) refers to how many full rows 
  // down this pixel is. the x*3 refers to how many columns into this row the pixel is
  pixels[width * y * 3 + x * 3 + 0] = col.r();
  pixels[width * y * 3 + x * 3 + 1] = col.g();
  pixels[width * y * 3 + x * 3 + 2] = col.b();
}

bool Img::write(const std::string filename) {

  std::ofstream file(filename);
  if (file.is_open()) {

    // type of ppm
    // width and height of image
    // maximum colour value
    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << "255" << std::endl;

    //write the rgb on a newline for each pixel
    for (int i = 0; i < width * height * 3; i+=3) {
      file << int(pixels[i]) << " " << int(pixels[i+1]) << " " << int(pixels[i+2]) << std::endl;
    }

    file.close();

    return true;
  }

  return false;
}