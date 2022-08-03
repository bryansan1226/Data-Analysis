lab3: main.o getResults.o getData.o
	g++ -Wall -g main.o getData.o getResults.o -o lab3
main.o:src/main.cpp src/getData.h src/getResults.h
	g++ -Wall -g -c src/main.cpp
getResults.o:src/getResults.cpp src/getResults.h src/getData.h
	g++ -Wall -g -c src/getResults.cpp
getData.o:src/getData.cpp src/getData.h
	g++ -Wall -g -c src/getData.cpp

