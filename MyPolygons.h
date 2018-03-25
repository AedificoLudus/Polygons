#pragma once

#include "Polygon.h"


class MyPolygons
{
public:
    node *current;

    int counter = 0;

    node* create_node(Polygon* data);
    void reset();
    void prepend(Polygon*);
    void insert_last(Polygon*);
    void insert_pos(Polygon*, int pos);
    void delete_pos(Polygon*, int pos);
    void add_first();
    void swap(node);
    Polygon* head();
    std::string to_string();
};
