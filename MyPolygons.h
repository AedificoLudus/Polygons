#include "Polygon.h"

struct mnode
{
  Point *data;
  mnode *next;
  mnode *prev;
}

class MyPolygons
{
public:
    mnode *current;
  
    int counter = 0;

    mnode* create_mnode(Polygon* data);
    void reset();
    void prepend(Polygon*);
    void insert_last(Polygon*);
    void insert_pos(Polygon*, int pos);
    void delete_pos(Polygon*, int pos);
    void add_first();
    void swap(mnode);
    Polygon* head();
    std::string to_string();
};
