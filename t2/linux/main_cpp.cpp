#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.hpp"
#include "Ciclista.hpp"

Ciclista * bike;

//*-- FUNÇÕES DA CANVAS --*
void keyboard(int key){
    //std::cout << key << std::endl;
    if(key == 100)//Tecle'D': How Stuff Works 
        bike->focus = !bike->focus ;
}
void keyboardUp(int key){
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y){
    //nothing to do
}
void render(){
    color(0.117647059,0.631372549,0.949019608);
    rectFill(0, 100,largura,altura);
    color(1,0,0);
    circleFill(largura, altura, 80, 30);
    color(.6,.6,.6);
    rectFill(0,0,largura,80);
    bike->render();
}
//END FUNÇÕES DA CANVAS

int main(int argc, char const *argv[]){
    bike = new Ciclista();

    initCanvas(500, 400, "Trabalho 2 - Deivis Costa Pereira");
    runCanvas();

    delete bike;
    return 0;
}