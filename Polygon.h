#pragma once

#include "Point.h"

struct pnode
{
  Point* data;
  pnode* next;
  pnode* prev;
};

class Polygon
{
public:

    pnode *current;

    int pcounter = 0;

    pnode *create_node(Point* data);
    void reset();
    void prepend(Point* data);
    void append(Point* data);
    void insert_pos(Point* data, int pos);
    void delete_pos(int pos);
    void add_first();
    Point* head();
    double calc_area();
    std::string to_string();
    double distance();
    void add_node(double, double);
    void populate(std::list<double>);
};
