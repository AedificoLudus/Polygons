#include "Polygon.h"


Polygon::Polygon() {
  sentinel = new Node;
  sentinel->isSentinel = true;
  sentinel->prev = sentinel;
  sentinel->next = sentinel;
  current = sentinel;
  count++;
}

//search for a null node (the sentinel node)
void Polygon::reset () {
  current = sentinel->next;
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
      current = current->next;
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
  for (int i=0;i<count;i++) {
    ss << current->point.to_string() << ", ";
    current = current->next;
  }
  ss.seekp(-1, ss.cur);
  ss << "]:" << calculateArea();
  return ss.str();
}

double Polygon::minDistance() {
  reset();
  double min = current->point.magnitude();
  for (int i = 1; i < count; i++) {
    current = current->next;
    if (min > current->point.magnitude()) {
      min = current->point.magnitude();
    }
  } return min;
}

void Polygon::populate(std::vector<double> points, int length) {
  for(int i = 2; i < length*2; i += 2) {
      append(i, i+1);
  }
}
