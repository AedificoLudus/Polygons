#ifndef Point_h
#define Point_h
#include "Point.h"
#endif

#ifndef Polygon_h
#define Polygon_h

class Polygon
{
  private:
  public:

    struct node
    {
      Point *data;
      struct node *next;
      struct node *prev;
    };

    node *create_node(Point* data);
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
