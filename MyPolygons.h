#pragma once

#include "Polygon.h"

class MyPolygons {
  struct Node {
    bool isSentinel;
    Node* prev;
    Node* next;
    Polygon polygon;
  } sentinel;
public:

  Node* current;

  MyPolygons();

  void prepend(Polygon polygon);
  void append(Polygon polygon);
  void insert(Polygon polygon);
  void step();
  void reset();
  Polygon take();
  
  void swap();
  void sort();
  std::string to_string();


};
