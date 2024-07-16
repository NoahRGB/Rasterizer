#include "img.h"
#include "colour.h"
#include "model.h"

// scene_object
// ray
// scene
// camera
// vec3
// matrix
// 

RGB red(255, 0, 0);
RGB blue(0, 0, 255);
RGB green(0, 255, 0);
RGB white(255, 255, 255);
RGB black(0, 0, 0);

// TODO: convert to integer only operations
void line(int x0, int y0, int x1, int y1, Img img, RGB col) {
  bool steep = false;
  double m = (y1 - y0) / (double)(x1 - x0);

  // if the gradient is steep
  if (m <= -1 || m > 1) {
    std::swap(x0, y0);
    std::swap(x1, y1);
    steep = true;
  }

  // if the points are in the wrong order
  if (x0 > x1) {
    std::swap(x0, x1);
    std::swap(y0, y1);
  }

  // holds the midpoint between the 2 candidate pixels
  double mid = (y0 - y1) * (x0+1) + (x1 - x0) * (y0+0.5) + x0*y1 - x1*y0;
  int y = y0;

  for (int x = x0; x <= x1; x++) {

    // ensures the coords are drawn in the correct order after swapping
    if (steep) {
      img.set(y, x, col);
    } else {
      img.set(x, y, col);
    }

    if (m <= 0) {
      // if line goes under the midpoint then draw the bottom pixel
      // otherwise draw the top pixel
      if (mid > 0) {
        y--;
        mid += (x0 + y0) - (x1 + y1);
      } else {
        
        mid += (y0 - y1);
      }

    } else if (m > 0) {
      // if the line goes over the midpoint then draw the top pixel
      // otherwise draw the bottom pixel
      if (mid < 0) {
        y++;
        mid += (x1 - x0) + (y0 - y1);
      } else {
        mid += (y0 - y1);
      }
    }
  }
}

int main() {

  int width = 100;
  int height = 100;

  Img img(width, height);

  line(50, 5, 5, 40, img, red);
  line(60, 40, 95, 5, img, blue);
  line(5, 65, 10, 95, img, green);
  line(30, 95, 35, 65, img, white);
  line(95, 70, 60, 65, img, blue);

  // line(20, 70, 80, 90, img, red);
  // line (0, 0, 24, 56, img, blue);

  img.write("testimage.ppm");

  return 0;
}