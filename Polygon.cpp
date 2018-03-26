#include "Polygon.h"

int pcounter = 0;

Polygon::Polygon()
{
  sentinel.isSentinel = true;
  sentinel.prev = &sentinel;
  sentinel.next = &sentinel;
  current = &sentinel;
}

//dynaically allocate memory for Nodes
pnode* Polygon::create_node(Point point)
{
    pcounter++;
    pnode *temp;
    temp = new(struct pnode);
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

//search for a null node (the sentinel node)
void MyPolygons::reset () {
  current = sentinel.next;
}

void Polygon::append (Point point) {
  Node node;
  node.point = point;
  node.isSentinel = false;
  current = &node;

  node.prev = sentinel.prev;
  node.next = &sentinel;

  sentinel.prev->next = &node;
  sentinel.prev = &node;
}

double Polygon::calculateArea() {
  double area = 0.00;
  reset();
  for (int i=0; i < pcounter-2; i++) {
    double newX = (current->next->data->get_value(true) + current->data->get_value(true));
    double newY = (current->next->data->get_value(false) + current->data->get_value(false));
    area += newX*newY;
    current = current->next;
  }
  area = abs(area);
  area = area/2;
  return area;
}

std::string Polygon::to_string() {
  reset();
  std::stringstream ss;
  ss << "[";
  for (int i=0;i<pcounter;i++)
  {
    ss << current->data->to_string() << ", ";
    current = current->next;
  }
  ss.seekp(-1, ss.cur);
  ss << "]:" << calc_area();
  return ss.str();
}

double Polygon::minDistance() {
  reset();
  double min = current->data->distance();
  for (int i = 1; i < pcounter; i++) {
    current = current->next;
    if (min > current->data->distance()) {
      min = current->data->distance();
    }
  }
  return min;
}

void Polygon::add_node(double X, double Y) {
  Point tempPoint = new Point;
  tempPoint->set_values(X, Y);
  append(tempPoint);
}

void Polygon::populate(std::vector<double>, int length) {
  for(int i = 2; i < length*2; i += 2) {
      Point point;
      point.set_values(i, i+1);
      append(point);
  }
}
