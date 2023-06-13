#include "Point.hpp"
#include <stdexcept>
using namespace std;
namespace ariel {

Point::Point() {
  this->x = 0;
  this->y = 0;
}
double Point::getX() const { return x; }

double Point::getY() const { return y; }

double Point::distance(const Point &other) const {
  double dx = x - other.getX();
  double dy = y - other.getY();
  return sqrt(dx * dx + dy * dy);
}
Point Point::moveTowards(Point source, Point destination, double distance) {
  if(distance<0){
    throw std::invalid_argument("cannot be nagative");
  }
  double dx = destination.x - source.x;
  double dy = destination.y - source.y;
  double totalDistance = std::sqrt(dx * dx + dy * dy);

  if (totalDistance <= distance) {
    return destination;
  }

  double ratio = distance / totalDistance;
  double newX = source.x + dx * ratio;
  double newY = source.y + dy * ratio;
  return Point(newX, newY);
}

} // namespace ariel
