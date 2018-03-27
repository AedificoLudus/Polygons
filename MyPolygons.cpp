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

//insert a Node at the beginning
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

//insert a node at the end
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
  std:;cout << "MyPolygons::to_string() is running"
  while (current != sentinel)
  {
    ss << current->polygon.to_string() << "\n";
    step();
    std::cout << "MyPolygons Loop Runs\n";
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

void MyPolygons::sort() {
    reset();
    while (current->next != sentinel) {
      double A = current->polygon.calculateArea(); //this is just to make it more readable
      double B = current->next->polygon.calculateArea();
      if(abs((fmax(A,B)-fmin(A,B))/fmin(A,B) < 0.05)) { // divide the two numbers with respect to the lower number
        if(current->polygon.minDistance() > current->next->polygon.minDistance()) {
          swap();
        }
      } else {
        if(A > B) {
          swap();
        }
      }
      current = current->next;
    }
}
