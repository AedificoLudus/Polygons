#include "Point.h"

class Point {
    double xCoord, yCoord;
  public:
    void set_values (double, double);
    int distance ();
    std::string to_string ();
}

void Point::set_values (double X, double Y) {
  xCoord = X;
  yCoord = Y;
}

int Point::distance () {
  return abs(sqrt(xCoord^2+yCoord^2);
}

std::string to_string () {
  std::stringstreamss;
  ss << "(" << xCoord << ", " << yCoord << ")";
  return ss.str();
}
