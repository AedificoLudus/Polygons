#ifndef MyPolygons_h
#define MyPolygons_h

class MyPolygons {
private:
public:
  node *create_node(Polygon* data);
  void reset();
  void prepend(Polygon* data);
  void insert_last(Polygon* data);
  void insert_pos(Polygon* data, int pos);
  void delete_pos(Polygon* data, int pos);
  void add_first();
  void swap(node)
  Polygon* head();
  std::string to_string();
};

#endif
