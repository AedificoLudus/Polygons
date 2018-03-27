#include "MyPolygons.h"

MyPolygons::MyPolygons () {
  sentinel = new Node;
  sentinel->isSentinel = true;
  sentinel->prev = sentinel;
  sentinel->next = sentinel;
  current = sentinel;
  count++;
}

void MyPolygons::step () {
  current = current->next;
}

void MyPolygons::reset () {
  if (sentinel->next != nullptr) {
    current = sentinel->next;
  }
}

void MyPolygons::append (Polygon polygon) {
  Node* node = new Node;
  node->polygon = polygon;
  node->isSentinel = false;
  current = node;

  node->prev = sentinel->prev;
  node->next = sentinel;

  sentinel->prev->next = node;
  sentinel->prev = node;

  count++;
}

void MyPolygons::prepend (Polygon polygon) {
  Node* node = new Node;
  node->polygon = polygon;
  node->isSentinel = false;
  current = node;

  node->prev = sentinel;
  node->next = sentinel->next;

  sentinel->next = node;
  sentinel->next->prev = node;

  count++;
}

void MyPolygons::insert (Polygon polygon) {
  Node* node = new Node;
  node->polygon = polygon;
  node->isSentinel = false;

  node->next = current;
  node->prev = current->prev;

  current->prev->next = node;
  current->prev = node;

  current = node;

  count++;
}

Polygon MyPolygons::take () {
  if (sentinel->next->isSentinel) return sentinel->polygon;
  Polygon out = sentinel->next->polygon;
  if (current == sentinel->next) reset();

  sentinel->next->next->prev = sentinel;
  sentinel->next = sentinel->next->next;

  return out;
}

std::string MyPolygons::to_string () {
  std::stringstream ss;
  reset();
  std::cout << "MyPolygons::to_string() is running\n";
  while (current != sentinel)
  {
    std::cout << "MyPolygons::to_string() loop is running\n";
    ss << current->polygon.to_string() << "  polygon printed\n";
    step();
  } return ss.str();
}

void MyPolygons::swap() {
  if (current != sentinel && current->next != sentinel) {
    current->next->prev = current->prev;
    current->prev->next = current->next;
    current->prev = current->next;
    current->next->next = current;
    current->next = current->next->next;
  }
}

bool MyPolygons::isSorted() {
  reset();
  while (current->next != sentinel) {
    if (current->polygon.calculateArea() > current->next->polygon.calculateArea()) {
      return false;
    }
  } return true;
}

void MyPolygons::sort() {
  std::cout << "sorting now\n";
  reset();
  while (!isSorted()) {
    double A = current->polygon.calculateArea(); //this is just to make it more readable
    double B = current->next->polygon.calculateArea();
    if(A > B) {
      swap();
    } step(); std::cout << "finished sorting\n";
  }
  reset();
  while (current->next != sentinel) {
    double A = current->polygon.calculateArea(); //this is just to make it more readable
    double B = current->next->polygon.calculateArea();
    if(abs((fmax(A,B)-fmin(A,B))/fmin(A,B) < 0.05)) { // divide the two numbers with respect to the lower number
      if(current->polygon.minDistance() > current->next->polygon.minDistance()) {
        swap();
      }
    }
  }
  current = current->next;
}
