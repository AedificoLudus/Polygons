#include "Point.h"
#include "Polygon.h"
#include<iostream>

//Declare Node
struct node
{
  Point *data;
  struct node *next;
  struct node *prev;
}*current
int counter = 0;

//Declare Linked list
class list
{
  public:
    node *create_node(Point* data);
    void reset();
    void prepend(Point* data);
    void insert_last(Point* data);
    void insert_pos(Point* data, int pos);
    void delete_pos(Point* data, int pos);
    Point* head();
    list()
    {
      current = NULL;
    }
};

//dynaically allocate memory for Nodes
node* node::create_node(Point* data)
{
  counter++
  struct node *temp;
  temp = new(struct node);
  temp->data = data;
  temp->next = NULL;
  temp-?prev = NULL;
  return temp;
}

//search for a null node (the sentinel node)
void reset()
{
  if (current->data == NULL)
  {
    return;
  }
  else
  {
    current = current->next;
  }
}

//insert a Node at the beginning
void list::prepend(Point* data)
{
  struct node *temp;
  temp = create_node(data);
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
void list::insert_last(Point* data)
{
  struct node *temp;
  reset();
  temp = create_node(data);
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
void list::insert_pos(Point* data, int pos)
{
  struct node *temp, *s, *ptr;
  temp = create_node(data);
  reset();
  if (counter < pos)
  {
    cout<<"Position out of range"<<endl;
    counter--;
    return;
    }
  s = current;
  for (i = 1; i <= counter; i++)
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
void list::delete_pos(int pos)
{
  node *s;
  reset();
  if (current->next == current)
  {
    cout<<"Empty List"<<endl;
    return;
  }
  s = current;
  for (i = 0; i < pos - 1; i++)
  {
    s = s->next;
  }
  s->prev->next = s-next
  s->next->prev = ptrs->prev;
  counter--;
  free(s);
}

Point* head()
{
  rest();
  current = current->next;
  return current->data;
}

class Polygon
{
  //circular, doubly linked list
  //to_string()
  //calc_area()
  //distance()
  //add_point()
}