# Makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = gaussian_dist
LIBRARY = libstatistics.a
LIB_SRCS = statistics.c
LIB_HEADERS = statistics.h
SRCS = Aufgabe1.c
HEADERS = gaussian_distribution.hpp

all: $(TARGET)

$(TARGET): $(LIBRARY) $(MAIN_SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_SRCS) -L. -lstatistics

$(LIBRARY): $(LIB_SRCS) $(LIB_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(LIB_SRCS)
	ar rcs $(LIBRARY) statistics.o

clean:
	rm -f $(TARGET) $(LIBRARY) *.o

.PHONY: all clean

