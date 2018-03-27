#include "MyPolygons.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <iterator>
#include <limits>

int main()
{
  //open file
  std::string file = "";
  std::cout << "Enter name of text file to read \n";
  std::cout << "Please do not include file extension \n";
  std::cin >> file;
  std::ifstream inputFile;
  std::stringstream ss;
  ss << file << ".txt";
  std::string openFile = ss.str();
  inputFile.open (openFile);

  MyPolygons firstSet, secondSet;
  std::cout << "MyPolygons created\n";

  if (!inputFile.good()) {
      std::cout << "something is wrong with the input file";
  } else {
    for (std::string line; std::getline(inputFile, line);) {
      std::vector<double> points;
      int length = line[2];
      line.erase(0,2);
      std::stringstream ss;
      ss << line;
      double tempDouble;
      for (int i = 0; i < length; i++) {
        ss >> tempDouble;
        points.push_back(tempDouble);
      }
      Polygon tempPolygon;
      tempPolygon.populate(points, length);
      firstSet.append(tempPolygon);
      secondSet.append(tempPolygon);
    }
  }

  //close file
  inputFile.close();
  //sort new copy
  secondSet.sort();
  //print both
  std::cout << "Input Order\n";
  std::cout << (firstSet.to_string()) <<"\n";
  std::cout << "Sorted by size\n";
  std::cout << (secondSet.to_string()) << "\n";
}
