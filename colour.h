#ifndef COLOUR_H
#define COLOUR_H

#include <cmath>

class RGB {
public:
  double vals[3];

  RGB() : vals{0, 0, 0} {}
  RGB(double r, double g, double b) : vals{r, g ,b} {}

  double r() const { return vals[0]; }
  double g() const { return vals[1]; }
  double b() const { return vals[2]; }

  double operator[](int i) const { return vals[i]; }
  double& operator[](int i) { return vals[i]; }
};

// double gamma_correct(double col) {
//   if (col > 0) {
//     return sqrt(col);
//   }
//   return 0;
// }

#endif