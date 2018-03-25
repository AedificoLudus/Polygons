#include "includes"
#include "MyPolygons.h"

std::ifstream infile();

int main()
{
  //open file
  //make MyPolygons
  MyPolygons firstSet = new MyPolygons
  firstSet.add_first()
  //read file
  //create Polygons in MyPolygons
  //copy MyPolygons
  MyPolygons secondSet = firstSet
  //sort new copy
  secondSet.sort();
  //print both
  firstSet.to_string();
  secondSet.to_string();
}
