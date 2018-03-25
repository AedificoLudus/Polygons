#include "Polygon.h"

class MyPolygons {
private:
public:
  node *create_node(Polygon* data);
  void reset();
  void prepend(Polygon* data);
  void insert_last(Polygon* data);
  void insert_pos(Polygon* data, int pos);
  void delete_pos(Polygon* data, int pos);
  Polygon* head();
};
