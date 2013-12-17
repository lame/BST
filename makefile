#MakeFile by Ryan Kuhl
#YOLO
#BrObama
CC = g++
CFLAGS = -c -g
LFLAGS = -g -o proj4.x

main: proj4_driver.o
	$(CC) $(LFLAGS) proj4_driver.o
	rm -f *.*.gch
	rm -f *.o
proj4_driver.o: bst.hpp bst.h proj4_driver.cpp
	$(CC) $(CFLAGS) bst.h
	$(CC) $(CFLAGS) proj4_driver.cpp

