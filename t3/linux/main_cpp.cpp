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
Point * m;

//*-- FUNÇÕES DA CANVAS --*
void keyboard(int key){
    std::cout << key << std::endl;
    if(key == 99){//Tecle'C': Limpar a Curva
        b->pcontrole.clear();
        b->pcurva.clear();
    }
}
void keyboardUp(int key){
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y){
    y = (y - altura) * -1;

    if (button == 0 && state == 0){
        if(b->Colision((double)x, (double)y, m) && b->pcontrole.size() > 1){
            b->aplica();
            s->aplica(b->pcurva);
        }
    }
}
void render(){
    b->render();
    s->render();
}
//END FUNÇÕES DA CANVAS

int main(int argc, char const *argv[]){
    m = NULL;
    Point * p1 = new Point(5,5);
    Point * p2 = new Point(175, 695); 
    b = new Bezier(100, p1, p2);
    s = new Superficie(100, 11);

    initCanvas(DIM, DIM, "Trabalho 3 - Deivis Costa Pereira");
    runCanvas();

    return 0;
}