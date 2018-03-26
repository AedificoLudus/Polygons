#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "Point.h"

class Polygon {
  struct Node {
    Node* prev;
    Node* next;
    Point point;
    bool isSentinel;
  } sentinel;
public:

  Node* current;

  int count;

  Polygon();

  void populate(std::vector<double>, int length);
  void reset();
  void append(Point point);
  double calculateArea();
  double minDistance();
  std::string to_string();
};
