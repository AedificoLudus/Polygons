#ifndef Point_h
#define Point_h

#include<string>

class Point {
  private:
    double xCoord, yCoord;
  public:
    void set_values(double, double);
    double get_value(bool);
    double distance();
    std::string to_string();
};

#endif
