CXX = clang++
CXXFLAGS = -g -std=c++11 -Wall 
LDFLAGS = -lGL -lGLU -lglut

all: main_cpp

main_cpp.o: main_cpp.cpp gl_canvas2d.hpp
gl_canvas2d.o: gl_canvas2d.cpp gl_canvas2d.hpp
Ciclista.o: Ciclista.cpp Ciclista.hpp
Pedal.o: Pedal.cpp Pedal.hpp
Roda.o: Roda.cpp Roda.hpp
Point.o: Point.cpp Point.hpp
Matrix.o: Matrix.cpp Matrix.hpp


main_cpp: main_cpp.o gl_canvas2d.o Matrix.o Point.o Roda.o Ciclista.o Pedal.o
	$(CXX) $(CXXFLAGS) -o $@  $^ $(LDFLAGS)

clean:
	rm -f main_cpp *.o