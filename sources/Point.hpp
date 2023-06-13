

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#pragma once
using namespace std;

namespace ariel {
class Point {
private:
  double x;
  double y;

public:
  Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
  Point();

  double distance(const Point &other) const;

  string print() const {
    return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
  }

  static Point moveTowards(Point source,Point destination,
                           double distance) ;
  double getX() const;

  double getY() const;
};
} // namespace ariel
