#pragma once

#include "Point.h"

struct node
{

};

class Polygon
{
public:

    node *current;

    node *create_node(Point* data);
    void reset();
    void prepend(Point* data);
    void insert_last(Point* data);
    void insert_pos(Point* data, int pos);
    void delete_pos(Point* data, int pos);
    void add_first();
    Point* head();
    double calc_area();
    std::string to_string();
    double distance();
};
