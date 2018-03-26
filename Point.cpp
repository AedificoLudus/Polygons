#include "Point.h"

void Point::set_values (double X, double Y) {
  xCoord = X;
  yCoord = Y;
}

double Point::get_value(bool coord)
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

std::string Point::to_string () {
  std::stringstream ss;
  ss << "(" << xCoord << ", " << yCoord << ")";
  return ss.str();
}
