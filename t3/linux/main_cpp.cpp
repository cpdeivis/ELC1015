/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.hpp"
#include "Bezier.hpp"
#include "Superficie.hpp"

#define DIM 700

Bezier * b;
Superficie * s;

//*-- FUNÇÕES DA CANVAS --*
void keyboard(int key){
    // std::cout << key << std::endl;
    if(key == 99){//Tecle'D': Limpar a Curva
        b->pcontrole.clear();
        b->pcurva.clear();
    }
}
void keyboardUp(int key){
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y){
    y = (y - altura) * -1; // precisei chamar a 'altura' da canvas
    if (button == 0 && state == 0){
        Point * p = new Point((double)x, (double)y);
        b->pcontrole.push_back(p);
        b->aplica();
        s->aplica(b->pcurva);
    }
}
void render(){
    b->render();
    s->render();
}
//END FUNÇÕES DA CANVAS

int main(int argc, char const *argv[]){
    b = new Bezier(4);
    s = new Superficie(4, 6);

    initCanvas(DIM, DIM, "Trabalho 3 - Deivis Costa Pereira");
    runCanvas();

    return 0;
}