/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.hpp"
#include "Bezier.hpp"
#include "Superficie.hpp"
#include <string>

#define DIM 700

Bezier * b;
Superficie * s;
Point * m;

//*-- FUNÇÕES DA CANVAS --*
void keyboard(int key){
    // std::cout << key << std::endl;
    if(key == 99){//Tecle'C' -> Limpar a Curva
        b->pcontrole.clear();
        b->pcurva.clear();
        s->clear();
    } else if(key == 201){//Seta Cima -> Incrementa angulo Z
        s->moves(false, true, b->pcurva);
    } else if(key == 203){//Seta Baixo -> Decrementa angulo Z
        s->moves(false, false, b->pcurva);
    } else if(key == 200){//Seta Esquerda -> Decrementa angulo X
        s->moves(true, false, b->pcurva);
    } else if(key == 202){//Seta Direita -> Incrementa angulo X
        s->moves(true, true, b->pcurva);
    } else if(key == 109){//Tecle'M' -> Adicionar Faces
        s->nfaces++;
        s->aplica(b->pcurva);
    } else if(key == 110){//Tecle'N' -> Remover Faces
        s->nfaces = s->nfaces < 2 ? 1 : s->nfaces-1;  
        s->aplica(b->pcurva);
    } else if(key == 112){//Tecle'P" -> Adicionar Pontos
        b->cpontos++;
        s->npontos++;
        b->aplica();
        s->aplica(b->pcurva);
    } else if(key == 111){//Tecle'O' -> Remover Pontos
        b->cpontos = b->cpontos < 2 ? 1 : b->cpontos-1;
        s->npontos = b->cpontos;
        b->aplica();
        s->aplica(b->pcurva);
    } 
}
void keyboardUp(int key){
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y){
    y = (y - altura) * -1;

    if (button == 0 && state == 0){
        m = b->Colision((double)x, (double)y);
        if(m != NULL && b->pcontrole.size() > 1){
            b->aplica();
            s->aplica(b->pcurva);
        }
    }

    if(m != NULL){
        if(state == 1)
            m = NULL;
        else{
            m->x = b->getX((double)x);
            m->y = b->getY((double)y);
            b->aplica();
            s->aplica(b->pcurva);
        }
    }
}
void render(){
    s->render();
    b->render();

    color(1,0,0);
    text(600, 690, ("x:" + std::to_string(s->xang)).c_str());
    text(600, 670, ("z:" + std::to_string(s->zang)).c_str());
    text(600, 650, ("f:" + std::to_string(s->nfaces)).c_str());
    text(600, 630, ("p:" + std::to_string(s->npontos)).c_str());
}
//END FUNÇÕES DA CANVAS

int main(int argc, char const *argv[]){
    m = NULL;
    Point * p1 = new Point(5,5);
    Point * p2 = new Point(175, 695); 
    b = new Bezier(20, p1, p2);
    s = new Superficie(20, 4);

    initCanvas(DIM, DIM, "Trabalho 3 - Deivis Costa Pereira");
    runCanvas();

    return 0;
}