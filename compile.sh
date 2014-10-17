#! /bin/csh
g++ -std=c++11 -c function.cpp 
g++ -std=c++11 -c main.cpp
g++ main.o function.o -o prog
