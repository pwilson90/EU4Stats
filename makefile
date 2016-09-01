make: EU4Stats

EU4Stats: main.o
	g++ main.o -o EU4Stats

main.o: main.cpp
	g++ -c -g main.cpp

clean:
	rm -f *.o dummyFile.txt EU4Stats;
