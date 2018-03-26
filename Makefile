Cxx = g++

prog: main.o MyPolygons.o Polygon.o Point.o
	Cxx -o prog main.o MyPolygons.o Polygon.o Point.o

main.o: main.cpp MyPolygons.h
	Cxx -c -o main.o main.cpp

MyPolgyons.o: MyPolygons.cpp MyPolygons.h Polygon.h
	Cxx -c -o MyPolygons.o MyPolygons.cpp

Polygon.o: Polygon.cpp Point.h
	Cxx -c -o Polygon.o Polygon.cpp

Point.o: Point.cpp Point.h
	Cxx -c -o Point.o Point.cpp
