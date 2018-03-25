#include "Point.h"

#include "Polygon.h"

#include <sstream>

#include<cmath>

//Declare Node
struct pnode
{
  Point *data;
  struct pnode *next;
  struct pnode *prev;
};
typedef pnode pnode;

*current;
int counter = 0;

//Declare Linked list
class
{
  private:

  public:
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
    Polygon()
    {
      current = NULL;
    }
};

//dynaically allocate memory for Nodes
pnode* create_pnode(Point* data)
{
  counter++;
  pnode *temp;
  temp = new(struct pnode);
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

//search for a null node (the sentinel node)
void reset()
{
  while (current->data != NULL)
  {
    current = current->next;
  }
}

//insert a Node at the beginning
void Polygon::prepend(Point* data)
{
  struct pnode *temp;
  temp = create_pnode(data);
  reset();
  if (current->next == current)
  {
    temp->next = current;
    temp->prev = current;
    current->next = temp;
    current->prev = temp;
  }
  else
  {
    temp->next = current->next;
    temp->prev = current;
    current->next->prev = temp;
    current->next = temp;
  }
}

//insert a node at the end
void Polygon::insert_last(Point* data)
{
  struct pnode *temp;
  reset();
  temp = create_pnode(data);
  if (current->next == current)
  {
    current->next = temp;
    current->prev = temp;
    temp->next = current;
    temp->prev = current;
  }
  else
  {
    current->prev->next = temp;
    temp->prev = current->prev;
    current->prev = temp;
    temp->next = current;
  }
}

//insert a node at a given position
void Polygon::insert_pos(Point* data, int pos)
{
  struct pnode *temp, *s, *ptr;
  temp = create_pnode(data);
  reset();
  if (counter < pos)
  {
    std::cout << "Position out of range" << std::endl;
    counter--;
    return;
    }
  s = current;
  for (int i = 1; i <= counter; i++)
  {
    ptr = s;
    s = s->next;
    if (i == pos - 1)
    {
      ptr->next = temp;
      temp->prev = ptr;
      s->prev = temp;
      break;
    }
  }
}

//delete node at a given position
void delete_pos(int pos)
{
  pnode *s;
  reset();
  if (current->next == current)
  {
    std::cout << "Empty List" << std::endl;
    return;
  }
  s = current;
  for (int i = 0; i < pos - 1; i++)
  {
    s = s->next;
  }
  s->prev->next = s->next;
  s->next->prev = s->prev;
  counter--;
  free(s);
}

void add_first()
{
  insert_last(NULL);
}

Point* head()
{
  reset();
  current = current->next;
  return current->data;
}

double calc_area()
{
  double area = 0.00;
  reset();
  for (int i=0,i < counter-2;i++)
  {
    double newX = (current->next.get_value(true) + current.get_value(true));
    double newY = (current->next.get_value(false) + current.get_value(false));
    area += newX*newY;
    current = current->next;
  }
  area = abs(area);
  area = area/2;
  return area;
}

std::string to_string()
{
  std:;string ss = "[";
  for (int i=0;i<counter;i++)
  {
    ss << i->data.to_string() << ","
  }
  ss.erase(ss.size()-1);
  ss << "]:" << std::to_strig(calc_area());
  return ss.str();
}

double distance()
{
  reset();
  double min = current->data.distance();
  for (int i = 1; i < counter; i++)
  {
    current = current->next;
    if (min > current->data.distance())
    {
      min = current->data.distance();
    }
  }
  return min;
}
