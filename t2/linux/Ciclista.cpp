#include "Ciclista.hpp"
#include "gl_canvas2d.hpp"
#include <cmath>

Ciclista::Ciclista(){
    pr1 = new Point(100, 100);
    pr2 = new Point(350, 100);
    pCatraca = new Point(225, 100);
    pBanco = new Point(200, 180);
    pJoelho1 = new Point(0,0);
    pJoelho2 = new Point(0,0);
    pCabeca = new Point(275,300);

    pedal  = new Pedal(pCatraca);
    roda1 = new Roda(pr1);
    roda2 = new Roda(pr2);
}

void Ciclista::render(){
    roda1->render();//renderiza a roda da esquerda
    color(1,0,0);
    //retas do quadro
    pCatraca->pLine(*pr1);
    pCatraca->pLine(*pBanco);
    pBanco->pLine(*pr1);
    roda2->render();//renderiza a roda da direita

    //posiciona os Joelhos
    pedal->getP1()->cIntersect(*pBanco, 80, 60, *pJoelho1);
    pedal->getP2()->cIntersect(*pBanco, 80, 60, *pJoelho2);

    // pBanco->pCircle(60);
    // pedal->getP1()->pCircle(80);
    // pedal->getP2()->pCircle(80);

    //retas banco/joelho + joelho/pedal
    pBanco->pLine(*pJoelho1);
    pedal->getP1()->pLine(*pJoelho1);

    pedal->render();//renderiza os pedais + catraca

    //retas banco/joelho + joelho/pedal
    pBanco->pLine(*pJoelho2);
    pedal->getP2()->pLine(*pJoelho2);

    //cabeça + tronco
    pCabeca->pCircle(40, true);
    pCabeca->pLine(*pBanco);
}