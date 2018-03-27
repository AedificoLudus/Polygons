#include "Polygon.h"


Polygon::Polygon() {
  sentinel = new Node;
  sentinel->isSentinel = true;
  sentinel->prev = sentinel;
  sentinel->next = sentinel;
  current = sentinel;
  count = 1;
}

void Polygon::reset () {
  current = sentinel->next;
}

void Polygon::step () {
  current = current->next;
}

void Polygon::append (double X, double Y) {
  Point* tempPoint = new Point;
  tempPoint->set(X, Y);
  Node* node = new Node;
  node->point = *tempPoint;
  node->isSentinel = false;
  current = node;

  node->prev = sentinel->prev;
  node->next = sentinel;

  sentinel->prev->next = node;
  sentinel->prev = node;

  count++;
}

double Polygon::calculateArea() {
  double area = 0.00;
  reset();
  for (int i=0; i < count-2; i++) {
    if(current->next != sentinel) {
      double newX = (current->next->point.get_x() + current->point.get_x());
      double newY = (current->next->point.get_y() + current->point.get_y());
      area += newX*newY;
      step();
    }
  }
  area = abs(area);
  area = area/2;
  return area;
}

std::string Polygon::to_string() {
  reset();
  std::stringstream ss;
  ss << "[";
  do {
    if (current->next != sentinel) {
      ss << current->point.to_string() << ", ";
    } else {
      ss << current->point.to_string();
    }
    step();
  } while (current != sentinel);
  ss << "]:" << calculateArea() << "\n";
  return ss.str();
}

double Polygon::minDistance() {
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
      append(points[i], points[i+1]);
  }
}
