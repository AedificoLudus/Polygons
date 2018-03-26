#pragma once

#include <sstream>
#include <cmath>
#include <string>

class Point {
  double x, y;
public:
  Point();
  Point(double x, double y);
  void set(double x, double y);
  double get_x();
  double get_y();
  double magnitude();
  std::string to_string();
};
