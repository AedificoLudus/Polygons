
SOURCES=main.cpp MyPolygons.cpp Point.cpp Polygons.cpp

prog: main.o MyPolygons.o Polygons.o Point.o
	g++ -o prog main.o MyPolygons.o Polygon.o Point.o

main.o: main.cpp MyPolygons.h
	g++ -cpp -o main.o main.cpp

MyPolgyons.o: MyPolygons.cpp MyPolygons.hPolygon.h
	g++ -cpp -o MyPolgyons.o MyPolgyons,cpp

Polygon.o: Polygon.cpp Point.h
	g++ -cpp -o Poygon.o Polygon.cpp

Point.o: Point.cpp Point.h
	g++ -cpp -o Point.o Point.cpp
