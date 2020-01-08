CC=g++
CFLAGS=-Wall -Wextra -Wpedantic -c -std=c++17

ifeq ($(CC), nvcc)
CFLAGS=-x cu -dc
endif

all: tracer

vec3.o: src/vec3.cpp src/include/vec3.hpp
	$(CC) $(CFLAGS) src/vec3.cpp

hitable_list.o: src/hitable_list.cpp src/include/hitable_list.hpp
	$(CC) $(CFLAGS) src/hitable_list.cpp

sphere.o: src/sphere.cpp src/include/sphere.hpp
	$(CC) $(CFLAGS) src/sphere.cpp

tracer.o: src/tracer.cpp
	$(CC) $(CFLAGS) src/tracer.cpp

tracer: tracer.o vec3.o hitable_list.o sphere.o
	$(CC) -o tracer tracer.o vec3.o hitable_list.o sphere.o

clean:
	@if test -n "$(wildcard *.o)"; then \
		rm *.o; \
		echo 'removed .o files'; \
	fi
	@if test -n "$(wildcard tracer)"; then \
		rm tracer; \
		echo 'removed tracer'; \
	fi
	@if test -n "$(wildcard *.ppm)"; then \
		rm *.ppm; \
		echo 'removed image'; \
	fi
