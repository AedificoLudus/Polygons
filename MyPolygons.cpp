#include "MyPolygons.h"

int mmcounter = 0;

//dynaically allocate memory for Nodes
mnode* MyPolygons::create_node(Polygon* data)
{
  mmcounter++;
  mnode *temp;
  temp = new(struct mnode);
  temp->data = data;
  temp->next = nullptr;
  temp->prev = nullptr;
  return temp;
}

//search for a null node (the sentinel node)
void MyPolygons::reset()
{
  while (current->data != nullptr)
  {
    current = current->next;
  }
}

//insert a Node at the beginning
void MyPolygons::prepend(Polygon* data)
{
  mnode *temp;
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
void MyPolygons::append(Polygon* data)
{
  mnode *temp;
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
void MyPolygons::insert_pos(Polygon* data, int pos)
{
  mnode *temp, *s, *ptr;
  temp = create_node(data);
  reset();
  if (mmcounter < pos)
  {
    std::cout << "Position out of range" << std::endl;
    mmcounter--;
    return;
    }
  s = current;
  for (int i = 1; i <= mmcounter; i++)
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
void MyPolygons::delete_pos(int pos)
{
  mnode *s;
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
  mmcounter--;
  free(s);
}

void MyPolygons::add_first()
{
  append(nullptr);
}

Polygon* MyPolygons::head()
{
  if(current->data != nullptr)
  {
    reset();
    current = current->next;
    return current->data;
  }
}

std::string MyPolygons::to_string()
{
  std::string ss = "";
  for (int i=0;i<mcounter;i++)
  {
    std::cout << current->data->to_string() << "\n";
    current = current->next;
  }
}

void MyPolygons::swap()
//swap the current node with the next node in the list
{
  if (current->data != nullptr && current->next->data != nullptr)
  {
    current->next->prev = current->prev;
    current->prev->next = current->next;
    current->prev = current->next;
    current->next->next = current;
    current->next = current->next->next;
  }
}

void MyPolygons::sort()
{
    reset();
    while (current->next->data != nullptr)
    {
      double A = current->data->calc_area(); //this is just to make it more readable
      double B = current->next->data->calc_area();
      if(abs((fmax(A,B)-fmin(A,B))/fmin(A,B) < 0.05)) // divide the two numbers with respect to the lower number
      {
        if(current->data->distance() > current->next->data->distance())
        {
          swap();
        }
      }
      else
      {
        if(A > B)
        {
          swap();
        }
      }
      current = current->next;
    }
}
