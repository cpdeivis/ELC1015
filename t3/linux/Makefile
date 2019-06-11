CXX = clang++
CXXFLAGS = -g -std=c++11 -Wall 
LDFLAGS = -lGL -lGLU -lglut

all: main_cpp

main_cpp.o: main_cpp.cpp gl_canvas2d.hpp
gl_canvas2d.o: gl_canvas2d.cpp gl_canvas2d.hpp
Superficie.o: Superficie.cpp Superficie.hpp
Bezier.o: Bezier.cpp Bezier.hpp
Point.o: Point.cpp Point.hpp


main_cpp: main_cpp.o gl_canvas2d.o Superficie.o Bezier.o Point.o
	$(CXX) $(CXXFLAGS) -o $@  $^ $(LDFLAGS)

clean:
	rm -f main_cpp *.o