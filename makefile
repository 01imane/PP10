# Makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = gaussian_dist

SRCS = Aufgabe1.c
HEADERS = gaussian_distribution.hpp

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
        $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
        rm -f $(TARGET) *.o

.PHONY: all clean
