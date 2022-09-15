COMPILER = g++
FLAGS = -c -Wall -Werror -Wextra

all: directory_check main
directory_check:
	@if [ ! -d "$(PWD)/bin" ]; then \
		mkdir -p bin; \
	fi
	@if [ ! -d "$(PWD)/lib" ]; then \
		mkdir -p lib; \
	fi
	@if [ ! -d "$(PWD)/build" ]; then \
		mkdir -p build; \
	fi
tetrahedron.o: src/tetrahedron.cpp
	$(COMPILER) $(FLAGS) src/tetrahedron.cpp -o bin/tetrahedron.o
plane.o: src/plane.cpp
	$(COMPILER) $(FLAGS) src/plane.cpp -o bin/plane.o
main.o: src/main.cpp
	$(COMPILER) $(FLAGS) src/main.cpp -o bin/main.o
libtetrahedron.a: tetrahedron.o plane.o
	ar rc lib/libtetrahedron.a bin/plane.o bin/tetrahedron.o
main: main.o libtetrahedron.a
	$(COMPILER) bin/main.o -o build/main -Llib -ltetrahedron
clean:
	rm bin/*.o lib/*.a build/main 