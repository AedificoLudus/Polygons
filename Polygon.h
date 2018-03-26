#pragma once

#include <string>
#include <sstream>

#include "Point.h"

class Polygon {
  struct Node {
    Node* prev;
    Node* next;
    Point point;
    bool isSentinel;
  } sentinel;
public:

  Polygon();

  void populate(std::vector<double>, int length);
  double calculateArea();
  double minDistance();
  std::string to_string();
};
