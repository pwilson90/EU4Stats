make: EU4Stats

EU4Stats: main.o Country.o
	g++ main.o Country.o -o EU4Stats

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

Country.o: Country.cpp
	g++ -c -g -std=c++11 Country.cpp

clean:
	rm -r -f *.o countries/*.txt EU4Stats;
