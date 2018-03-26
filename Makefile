PA1:	main.o MyPolygons.o Polygon.o Point.o
	g++ -g -o PA1 main.o MyPolygons.o Polygon.o Point.o -fsanitize=address

main.o: main.cpp MyPolygons.h
	g++ -c main.cpp -o main.o -fsanitize=address

MyPolgyons.o: MyPolygons.cpp MyPolygons.h Polygon.h
	g++ -c MyPolygons.cpp -o MyPolygons.o -fsanitize=address

Polygon.o: Polygon.cpp Point.h
	g++ -c Polygon.cpp -o Polygon.o -fsanitize=address

Point.o: Point.cpp Point.h
	g++ -c Point.cpp -o Point.o -fsanitize=address
