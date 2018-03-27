#include "MyPolygons.h"

#include <string>
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
  ss << "./" << file << ".txt";
  std::string openFile = ss.str();
  inputFile.open (openFile);

  MyPolygons firstSet, secondSet;
  std::cout << "MyPolygons created\n";

  if (!inputFile.good()) {
      std::cout << "something is wrong with the input file";
  } else {
    std::cout << "Input file is good\n";
    for (std::string line; std::getline(inputFile, line);) {
      std::cout << "new line\n";
      //cout to show the loop has entered
      std::vector<double> points;
      //initialise the vector "points"
      int length = line[2];
      //the third character of the line is an int telling me how many points are descroned there.
      //This assumes there's less than 10 points, I should fix that later
      line.erase(0,4);
      //remove the first few characters, now the line only contains doubles
      std::stringstream oss;
      //new stringstream, different name from previous one
      oss << line;
      //insert line into stringstream.
      double tempDouble;
      //tempDouble will store the doubles as I take them out of the stringstream
      for (int i = 0; i < length*2; i++) {
        //each point has two doubles, so twice length
        oss >> tempDouble;
        //this inserts the next double into tempDouble from oss.
        points.push_back(tempDouble);
        //push_back that double to vector points
      }
      Polygon tempPolygon;
      //polygon to store points
      std::cout << "Points: " << points << "\n";
      //trying to test if the points were added to the vector
      tempPolygon.populate(points);
      //add the points to the polygon
      std::cout << "tempPolygon populated\n" << tempPolygon.to_string() << "\n";
      //trying to test if the polygon was populated
      firstSet.append(tempPolygon);
      //add a node to firstSet that has this a copy of this Polygon
      std::cout << "firstSet appended\n";
      secondSet.append(tempPolygon);
      //same as above, but for the secondSet
      std::cout << "secondSet appended\n";
    }

    //print both
    std::cout << "Input Order\n";
    std::cout << (firstSet.to_string()) <<"\n";
    std::cout << "Sorted by size\n";
    secondSet.sort();
    std::cout << (secondSet.to_string()) << "\n";
  }
  inputFile.close();
}
