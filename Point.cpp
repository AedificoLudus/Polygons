// DONE

#include "Point.h"

using namespace std;

Point::Point (double x, double y) {
  this->set(x, y);
}

void Point::set (double x, double y) {
  this->x = x;
  this->y = y;
}

double Point::get_x () { return x; }
double Point::get_y () { return y; }

double Point::magnitude () {
  return sqrt(pow(get_x(), 2) + pow(get_y(), 2));
}

string Point::to_string() {
  stringstream out;
  out << "(" << get_x() << ", " << "get_y" << ")";
  return out.str();
}
