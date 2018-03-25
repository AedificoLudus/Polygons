prog: main.o MyPolygons.o Point.o
	g++ -o prog main.o MyPolygons.o Point.o

main.o: main.cpp MyPolygons.h
	g++ -c -o main.o main.cpp

MyPolgyons.o: MyPolygons.cpp MyPolygons.hPolygon.h
	g++ -c -o MyPolgyons.o MyPolgyons.cpp

Polygon.o: Polygon.cpp Point.h
	g++ -c -o Poygon.o Polygon.cpp

Point.o: Point.cpp Point.h
	g++ -c -o Point.o Point.cpp
