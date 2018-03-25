#ifndef Point_h
#define Point_h

class Point {
private:
  double xCoord, yCoord;
public:
  void set_values(double, double);
  int distance();
  std::string to_string();
};

#endif
