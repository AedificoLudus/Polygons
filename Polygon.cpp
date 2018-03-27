#include "Polygon.h"


Polygon::Polygon() {
  sentinel = new Node;
  sentinel->isSentinel = true;
  sentinel->prev = sentinel;
  sentinel->next = sentinel;
  current = sentinel;
  count = 1;
}

Polygon::~Polygon() {
  delete sentinel->prev;
  delete sentinel->next;
  delete sentinel;
}

void Polygon::reset () {
  current = sentinel->next;
  //reset current to the first actual point in the list.
  //this is done for readability
}

void Polygon::step () {
  current = current->next;
  //move current by done
  //this is done for readability
}

void Polygon::append (double X, double Y) {
  Point* tempPoint = new Point;
  //make tempPoint here to avoid doing so multiple times throughout the class
  tempPoint->set(X, Y);
  Node* node = new Node;
  node->point = *tempPoint;
  node->isSentinel = false;
  current = node;

  //insert the new node into the list
  node->prev = sentinel->prev;
  node->next = sentinel;

  sentinel->prev->next = node;
  sentinel->prev = node;

  count++;
}

double Polygon::calculateArea() {
  //calculate the followng formula:
  //1/2 * | SUM[N-2, i=0] ((X(i) + X(i+1)) (Y(i) + Y(i+1))) |
  double area = 0.00;
  reset();
  for (int i=0; i < count-2; i++) {
    if(current->next != sentinel) {
      double newX = (current->next->point.get_x() + current->point.get_x());
      // (X of i + X of i+1)
      double newY = (current->next->point.get_y() + current->point.get_y());
      // Y of i + Y of i+1
      area += newX*newY;
      //add the value of all (X*Y)s together
      step();
    }
  }
  area = abs(area);
  //take the absolute value of area
  area = area/2;
  return area;
}

std::string Polygon::to_string() {
  reset();
  std::stringstream ss;
  ss << "[";
  do {
    if (current->next != sentinel) {
      //add the return of the individual points to_string functions to the stringstream
      //with formatting
      ss << current->point.to_string() << ", ";
      //add to the stringstream in the format ''(X, Y),''
    } else {
      ss << current->point.to_string();
      //if it's the last point in the polygon, don't add a comma
    }
    step();
  } while (current != sentinel);
  ss << "]:" << calculateArea() << "\n";
  //finish the stream so it goes "[(X, Y), ... , (X, Y)]:area"
  return ss.str();
}

double Polygon::minDistance() {
  //find the point with the lowest distance from the origin
  reset();
  double min = current->point.magnitude();
  for (int i = 1; i < count; i++) {
    step();
    if (min > current->point.magnitude()) {
      min = current->point.magnitude();
    }
  } return min;
}

void Polygon::populate(std::vector<double> points) {
  for(int i = 0; i < points.size(); i += 2) {
    //go through the vector and add points to the polygon from it
      append(points[i], points[i+1]);
  }
}
