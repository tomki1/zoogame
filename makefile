CXXFLAGS = -Wall -g -std=c++0x -pedantic-errors

output: main.o animal.o penguin.o tiger.o turtle.o zoo.o inputValidation.o
	g++ ${CXXFLAGS} main.o animal.o penguin.o tiger.o turtle.o zoo.o inputValidation.o -o project2

main.o: main.cpp
	g++ ${CXXFLAGS} -c main.cpp

animal.o: animal.cpp animal.hpp
	g++ ${CXXFLAGS} -c animal.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ ${CXXFLAGS} -c penguin.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ ${CXXFLAGS} -c tiger.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ ${CXXFLAGS} -c turtle.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ ${CXXFLAGS} -c zoo.cpp


inputValidation.o: inputValidation.cpp inputValidation.hpp
	g++ ${CXXFLAGS} -c inputValidation.cpp
clean:
	rm *.o project2

zip:
	zip -D Project2_Tom_Kimberly.zip animal.cpp penguin.cpp tiger.cpp turtle.cpp zoo.cpp inputValidation.cpp animal.hpp penguin.hpp tiger.hpp turtle.hpp zoo.hpp inputValidation.hpp main.cpp makefile KimberlyTomproject2design.pdf

valgrind:
	valgrind --leak-check=full --tool=memcheck --show-leak-kinds=all  --track-origins=yes project2
