#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "Point.h"

class Polygon {
  struct Node {
    bool isSentinel;
    Node* prev;
    Node* next;
    Point point;
  };
public:

  Node* sentinel;
  Node* current;

  int count;

  Polygon();

  void populate(std::vector<double>, int length);
  void reset();
  void step();
  void append(double X, double Y);
  double calculateArea();
  double minDistance();
  std::string to_string();
};
