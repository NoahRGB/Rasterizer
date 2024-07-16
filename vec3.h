#ifndef VEC3_H
#define VEC3_H

class Vec3 {
  public:
    double vals[3];

    Vec3() : vals{0, 0, 0} {}
    Vec3(double x, double y, double z) : vals{x, y, z} {}

    double x() const { return vals[0]; }
    double y() const { return vals[1]; }
    double z() const { return vals[2]; }

    double operator[](int i) const { return vals[i]; }
    double& operator[](int i) { return vals[i]; }



};

#endif