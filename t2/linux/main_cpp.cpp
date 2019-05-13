#include <iostream>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.hpp"
#include "Point.hpp"
#include "Roda.hpp"


Roda * rd;
Roda * ro;

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
    y = (y - altura) * -1; // precisei chamar a 'altura' da canvas
    if (button == 0 && state == 0){
    }
}
void render(){
    // loops que renderizam os objetos em Tela
    rd->render();
    ro->render();
}
//END FUNÇÕES DA CANVAS

int main(int argc, char const *argv[]){
    Point * pp = new Point(100,100);
    Point * pb = new Point(200,100);
    rd = new Roda(pp);
    ro = new Roda(pb);
    
    initCanvas(1005, 610, "Trabalho 2 - Deivis Costa Pereira");
    runCanvas();

    return 0;
}