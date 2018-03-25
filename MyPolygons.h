#ifndef MyPolygons_h
#define MyPolygons_h

#include "Polygon.h"

class MyPolygons {
private:
public:

  //Declare Node
  struct mnode
  {
    Point *data;
    struct mnode *next;
    struct mnode *prev;
  };
  mnode *current;


  int counter = 0;

  mnode* create_mnode(Polygon* data);
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
