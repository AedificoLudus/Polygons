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
  if (!inputFile.good()) {
      std::cout << "something hasn't worked";
  } else {
    for (std::string line; std::getline(inputFile, line);) {
      std::cout << line << std::endl;
    }
  }
  //make MyPolygons
  MyPolygons firstSet, secondSet;
  std::cout << "MyPolygons created\n";
  //read file
  //create Polygons in MyPolygons
  std::string currentLine;
  std::getline(inputFile, currentLine);
  std::cout << currentLine;

  for (std::string line; std::getline(inputFile, line);) {
    int length = currentLine.at(2);
    std::vector<std::string> tokens;
    std::vector<double> points;
    std::istringstream iss(currentLine);
    copy(std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>(),
        back_inserter(tokens));
    tokens.erase(tokens.begin(), tokens.begin()+1);
    for (int i = 0; i < tokens.size(); i++) {
      points.push_back(std::stod(tokens[i]));
    }
    Polygon temp;
    temp.populate(points, length);
    firstSet.append(temp);
    secondSet.append(temp);
    std::getline(inputFile, currentLine);
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
