GXX = g++

PA1:	main.o MyPolygons.o Polygon.o Point.o
	$(GXX) -o PA1 main.o MyPolygons.o Polygon.o Point.o

main.o: main.cpp MyPolygons.h
	$(GXX) -c -o main.o main.cpp

MyPolgyons.o: MyPolygons.cpp MyPolygons.h Polygon.h
	$(GXX) -c -o MyPolygons.o MyPolygons.cpp

Polygon.o: Polygon.cpp Point.h
	$(GXX) -c -o Polygon.o Polygon.cpp

Point.o: Point.cpp Point.h
	$(GXX) -c -o Point.o Point.cpp
