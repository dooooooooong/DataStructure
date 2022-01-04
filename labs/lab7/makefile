qsort: quick.o comparator.o printlist.o
	g++ printlist.o comparator.o quick.o -o qsort

quick.o: quick.cpp 
	g++ -c quick.cpp -I../../include

comparator.o: comparator.cpp
	g++ -c comparator.cpp

printlist.o: printlist.cpp
	g++ -c printlist.cpp
	
clean:
	rm -f *.o qsort.exe qsort