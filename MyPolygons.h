#pragma once

#include "Polygon.h"

struct mnode
{
  Polygon*data;
  mnode* next;
  mnode* prev;
};

class MyPolygons
{
public:
    mnode *current;

    int counter = 0;

    mnode* create_node(Polygon* data);
    void reset();
    void prepend(Polygon*);
    void append(Polygon*);
    void insert_pos(Polygon*, int pos);
    void delete_pos(int pos);
    void add_first();
    void swap(mnode);
    void sort();
    Polygon* head();
    std::string to_string();


};
