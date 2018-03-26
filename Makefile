prog: polygons.exe

polygons.exe:	main.o MyPolygons.o Polygon.o Point.o
	g++ -o prog main.o MyPolygons.o Polygon.o Point.o

main.o: main.cpp MyPolygons.h
	g++ -c -o main.o main.cpp

MyPolgyons.o: MyPolygons.cpp MyPolygons.h Polygon.h
	g++ -c -o MyPolygons.o MyPolygons.cpp

Polygon.o: Polygon.cpp Point.h
	g++ -c -o Polygon.o Polygon.cpp

Point.o: Point.cpp Point.h
	g++ -c -o Point.o Point.cpp
