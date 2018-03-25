#ifndef Polygon_h
#define Polygon_h

#include "Point.h"

class Polygon
{
  private:
  public:

    struct pnode
    {
      Point *data;
      struct pnode *next;
      struct pnode *prev;
    } *current;

    pnode *create_pnode(Point* data);
    void reset();
    void prepend(Point* data);
    void insert_last(Point* data);
    void insert_pos(Point* data, int pos);
    void delete_pos(Point* data, int pos);
    void add_first();
    Point* head();
    double calc_area():
    std::string to_string();
    double distance();
};

#endif
