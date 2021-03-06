#include "Point.h"

using namespace std;

Point::Point() {
  this->x = 0.00;
  this->y = 0.00;
}

Point::~Point() {
}

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
  std::stringstream out;
  out << "(" << get_x() << ", " << get_y() << ")";
  //insert the point into the stream in the fashion (X, Y)
  return out.str();
}
