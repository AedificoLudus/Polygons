#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <stdlib.h>
#include <vector>
class Point
{
private:
  double xCoord, yCoord;
public:
  void set_values(double, double);
  double get_value(bool);
  double distance();
  std::string to_string();
};
