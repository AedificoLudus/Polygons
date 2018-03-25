#include "Polygon.h"
#include "includes.h"

int pcounter = 0;

//dynaically allocate memory for Nodes
pnode* Polygon::create_node(Point* data)
{
    pcounter++;
    pnode *temp;
    temp = new(struct pnode);
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

//search for a null node (the sentinel node)
void Polygon::reset()
{
    while (current->data != NULL)
    {
        current = current->next;
    }
}

//insert a Node at the beginning
void Polygon::prepend(Point* data)
{
    pnode *temp;
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
void Polygon::append(Point* data)
{
    pnode *temp;
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
void Polygon::insert_pos(Point* data, int pos)
{
    pnode *temp, *s, *ptr;
    temp = create_node(data);
    reset();
    if (pcounter < pos)
    {
        std::cout << "Position out of range" << std::endl;
        pcounter--;
        return;
    }
    s = current;
    for (int i = 1; i <= pcounter; i++)
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
void Polygon::delete_pos(int pos)
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
  pcounter--;
  free(s);
}

void Polygon::add_first()
{
  append(NULL);
}

Point* Polygon::head()
{
  reset();
  current = current->next;
  return current->data;
}

double Polygon::calc_area()
{
  double area = 0.00;
  reset();
  for (int i=0; i < pcounter-2; i++)
  {
    double newX = (current->next->data->get_value(true) + current->data->get_value(true));
    double newY = (current->next->data->get_value(false) + current->data->get_value(false));
    area += newX*newY;
    current = current->next;
  }
  area = abs(area);
  area = area/2;
  return area;
}

std::string Polygon::to_string()
{
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

double Polygon::distance()
{
  reset();
  double min = current->data->distance();
  for (int i = 1; i < pcounter; i++)
  {
    current = current->next;
    if (min > current->data->distance())
    {
      min = current->data->distance();
    }
  }
  return min;
}
