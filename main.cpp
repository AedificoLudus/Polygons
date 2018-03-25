#include "includes"
#include "MyPolygons.h"

int main()
{
  //open file
  std::string file = "";
  std::cout << "Enter name of file to read \n";
  std::cout << "Please include file extension \n";
  std::cin >> file;
  ifstream inputFile;
  inputFile.open (file);
  //make MyPolygons
  MyPolygons firstSet = new MyPolygons
  firstSet.add_first()
  //read file
  inputFile.close();
  //create Polygons in MyPolygons
  //close file

  //copy MyPolygons
  MyPolygons secondSet = firstSet
  //sort new copy
  secondSet.sort();
  //print both
  firstSet.to_string();
  secondSet.to_string();
}
