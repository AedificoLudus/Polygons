#include "Point.h"
#include<stringstream>

class Point {
  private:
    double xCoord, yCoord;
  public:
    void set_values(double, double);
    double get_value(bool);
    double distance();
    std::string to_string();
}

void Point::set_values (double X, double Y) {
  xCoord = X;
  yCoord = Y;
}

double get_value(bool coord)
{
  if (bool coord = true)
  {
    return xCoord;
  }
  else
  {
    return yCoord;
  }
}

double Point::distance () {
  return abs(sqrt(pow(xCoord, 2) + pow(yCoord, 2)));
}

std::string to_string () {
  std::stringstream ss;
  ss << "(" << xCoord << ", " << yCoord << ")";
  return ss.str();
}
