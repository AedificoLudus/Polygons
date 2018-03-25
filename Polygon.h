#include "Point.h"

class Polygon {
private:
public:
  node *create_node(Point* data);
  void reset();
  void prepend(Point* data);
  void insert_last(Point* data);
  void insert_pos(Point* data, int pos);
  void delete_pos(Point* data, int pos);
  Point* head();
};
