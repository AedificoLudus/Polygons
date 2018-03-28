PA1:	main.o MyPolygons.o Polygon.o Point.o
	g++ -g -o PA1 main.o MyPolygons.o Polygon.o Point.o -fsanitize=address -g -std=c++11

main.o: main.cpp MyPolygons.h
	g++ -c main.cpp -o main.o -fsanitize=address -g -std=c++11

MyPolygons.o: MyPolygons.cpp MyPolygons.h Polygon.h
	g++ -c MyPolygons.cpp -o MyPolygons.o -fsanitize=address -g -std=c++11

Polygon.o: Polygon.cpp Point.h
	g++ -c Polygon.cpp -o Polygon.o -fsanitize=address -g -std=c++11

Point.o: Point.cpp Point.h
	g++ -c Point.cpp -o Point.o -fsanitize=address -g -std=c++11
