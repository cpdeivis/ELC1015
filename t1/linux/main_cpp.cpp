#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>
#include "gl_canvas2d.hpp"

#include "Botao.hpp"
// #include <fstream>
// #include <list>

Botao * teste;
void printP(void){
    std::cout << "funcionou" << std::endl;
}

void keyboard(int key){
    //nothing to do
}
void keyboardUp(int key){
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y){
    //TODO
    y = (y-563)* -1;
    if(button == 0 && state == 0){
        std::cout << x << "  " << y << std::endl;
        if(teste->colision(x, y)){
            teste->focus = true;
            teste->callback();
        }

        teste->focus = false;
        return;
    }
}
void render(){
    // color(0,0,0);
    // rect(0,0,200,200);
    // line(0,180,200,180);
    teste->render();
}
int main(int argc, char const *argv[])
{
    // std::ifstream file("base2.dct", std::ios::binary);
    // if(file.is_open() == false)
    //     throw std::runtime_error{"Nao foi possivel abrir o arquivo!"};

    // std::uint32_t num_amostras;
    // file.read(reinterpret_cast<char*>(&num_amostras), 4);
    // std::list<std::int16_t> lsAmostras;
    // std::int8_t amostra;
    // while(file.eof() == false){
    //     file.read(reinterpret_cast<char*>(&amostra), 1);
    //     lsAmostras.push_back((int)amostra);
    //     std::cout << "Amostra = " << (int)amostra << std::endl;
    // }

    // std::cout << "Num Amostras = " << num_amostras << std::endl;
    initCanvas(1000, 563, "Trabalho 1 - Deivis Costa Pereira");
    teste = new Botao(5,5, 200, 30);
    teste->setLabel("O R I G I N A L");
    teste->callback = printP;
    runCanvas();
    return 0;
}