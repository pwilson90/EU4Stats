make: EU4Stats

EU4Stats: main.o
	g++ main.o -o EU4Stats

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

clean:
	rm -r -f *.o countries/*.txt EU4Stats;
