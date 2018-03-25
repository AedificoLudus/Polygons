#Open source, standard makefile from MrBook.org


CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp MyPolygons.cpp Point.cpp Polygons.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=PolgonAnalyser

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
    $(CC) $(CFLAGS) $< -o $@
