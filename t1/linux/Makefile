CXX = clang++
CXXFLAGS = -g -std=c++11 -Wall 
LDFLAGS = -lGL -lGLU -lglut

all: main_cpp

main_cpp.o: main_cpp.cpp gl_canvas2d.hpp
gl_canvas2d.o: gl_canvas2d.cpp gl_canvas2d.hpp
Grafico.o: Grafico.cpp Grafico.hpp Amostra.hpp General.hpp
Botao.o: Botao.cpp Botao.hpp General.hpp
Amostra.o: Amostra.cpp Amostra.hpp General.hpp
General.o: General.cpp General.hpp

main_cpp: main_cpp.o gl_canvas2d.o General.o Botao.o Amostra.o Grafico.o
	$(CXX) $(CXXFLAGS) -o $@  $^ $(LDFLAGS)

clean:
	rm -f main_cpp *.o