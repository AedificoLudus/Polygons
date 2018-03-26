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
  std::getline(inputFile, currentLine);
  do {
    int length = currentLine.at(2);
    std::vector<std::string> tokens;
    std::vector<double> points;
     //[(length*2)+2];
    for (int i = 0; i < 1; i++)
    {
      using namespace std;
      istringstream iss(currentLine);
      copy(istream_iterator<string>(iss),
          istream_iterator<string>(),
          back_inserter(tokens));
      tokens.erase(tokens.begin(), tokens.begin()+1);
      for (int i = 0; i < tokens.size(); i++)
      {
        points.push_back(std::stod(tokens[i]));
      }
    }
    Polygon temp;
    temp.populate(points, length);
    firstSet.append(&temp);
    std::getline(inputFile, currentLine);
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
