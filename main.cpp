#include "includes.h"
#include "MyPolygons.h"

int main()
{
  //open file
  std::string file = "";
  std::cout << "Enter name of file to read \n";
  std::cout << "Please include file extension \n";
  std::cin >> file;
  std::ifstream inputFile;
  inputFile.open (file);
  //make MyPolygons
  MyPolygons firstSet;
  firstSet.add_first();
  //read file
  //create Polygons in MyPolygons
  std::string currentLine;
  std::getline(file, currentLine);
  do {
    int length = currentLine.at(2);
    double points [(length*2)+2];
    for (int i = 0; i < 1; i++)
    {
      using namespace std;
      istringstream iss(currentLine);
      copy(istream_iterator<string>(iss),
          istream)iterator<string>(),
          back_inserter(points));
    }
    Polygon temp;
    temp.populate(points);
    firstSet.append(temp*);
    std::getline(file, currentLine);
  } while(!inputFile.eof());
  //close file
  inputFile.close();
  //copy MyPolygons
  MyPolygons secondSet = firstSet;
  //sort new copy
  secondSet.sort();
  //print both
  firstSet.to_string();
  secondSet.to_string();
}
