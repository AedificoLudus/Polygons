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

  //return the polygon directly after isSentinel
  //set the polygon after that one as the head of the list

  return out;
}

std::string MyPolygons::to_string () {
  std::stringstream ss;
  reset();
  while (current != sentinel)
  {
    ss << current->polygon.to_string() << "\n";
    //add the return of the Polygons to_string() functions to the stringstream
    //with formatting
    step();
  } return ss.str();
}

void MyPolygons::swap() {
  //swapping by value, not by links
  //will swap by links after I know the programs works fine otherwise
  //for specification reasons
  if (current != sentinel && current->next != sentinel) {
    Polygon tempPolygon;
    tempPolygon = current->polygon;
    current->polygon = current->next->polygon;
    current->next->polygon = tempPolygon;
  }
}

bool MyPolygons::isSorted() {
  reset();
  while (current->next != sentinel) {
    //step through the list until you reach the sentinel
    if (current->polygon.calculateArea() > current->next->polygon.calculateArea()) {
      //if the current polygon has a larger area than the next polygon
      return false;
    }
  } return true;
}

void MyPolygons::sort() {
  std::cout << "sorting now\n";
  reset();
  std::cout << "does this print?\n";
  while (!isSorted()) {
    std::cout << "first while loop iterate\n";
    double A = current->polygon.calculateArea(); //this is just to make it more readable
    double B = current->next->polygon.calculateArea();
    if(A > B) {
      swap();
      //if A, the first polygon, has a greater area than B, the second, swap them over
    } step();
  }
  std::cout << "first while loop exited\n";
  reset();
  while (current->next != sentinel) {
    std::cout << "second while loop iterate\n";
    double A = current->polygon.calculateArea(); //this is just to make it more readable
    double B = current->next->polygon.calculateArea();
    if(abs((fmax(A,B)-fmin(A,B))/fmin(A,B) < 0.05)) {
      // divide the two numbers with respect to the lower number
      // find if the two areas are within 0.5% of each other
      if(current->polygon.minDistance() > current->next->polygon.minDistance()) {
        //the polygon with the lower minDistance goes first, not the polygon with the lower area
        swap();
      }
    }
  }
  std::cout << "second while loop exited\n";
  current = current->next;
}
