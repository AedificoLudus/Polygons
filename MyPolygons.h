#ifndef Point_h
#define Point_h
#include "Point.h"
#endif

#ifndef Polygon_h
#define Polygon_h
#include "Polygon.h"
#endif

#ifndef MyPolygons_h
#define MyPolygons_h

class MyPolygons {
private:
public:

  //Declare Node
  struct mnode
  {
    Point *data;
    struct mnode *next;
    struct mnode *prev;
  } *current;
typedef mnode mnode;


  int counter = 0;

  mnode *create_mnode(Polygon* data);
  void reset();
  void prepend(Polygon* data);
  void insert_last(Polygon* data);
  void insert_pos(Polygon* data, int pos);
  void delete_pos(Polygon* data, int pos);
  void add_first();
  void swap(mnode);
  Polygon* head();
  std::string to_string();
};

#endif
