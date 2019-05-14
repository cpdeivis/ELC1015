#include <iostream>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.hpp"
#include "Ciclista.hpp"


Ciclista * bike;

//*-- FUNÇÕES DA CANVAS --*
void keyboard(int key){
    //nothing to do
}
void keyboardUp(int key){
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y){
    // REALIZA-SE AS VERIFICAÇÕES DE COLISÃO DO PONTEIRO DO MOUSE
    // COM OS OBJETOS NECESSÁRIOS
    y = (y - altura) * -1;
    if (button == 0 && state == 0){
    }
}
void render(){
    bike->render();
}
//END FUNÇÕES DA CANVAS

int main(int argc, char const *argv[]){
    bike = new Ciclista();

    initCanvas(500, 400, "Trabalho 2 - Deivis Costa Pereira");
    runCanvas();

    return 0;
}