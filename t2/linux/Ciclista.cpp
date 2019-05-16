/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#include "Ciclista.hpp"
#include "gl_canvas2d.hpp"
#include <cmath>

Ciclista::Ciclista(){//Construtor da Classe
    //PARTES DA BIKE
    pCatraca = new Point(225, 100);
    pBanco = new Point(200, 180);
    pedal  = new Pedal(pCatraca);
    pr1 = new Point(100, 100);
    roda1 = new Roda(pr1);
    pr2 = new Point(350, 100);
    roda2 = new Roda(pr2);
    pGarfo = new Point(325,180);
    pGuidon = new Point(300,210);
    //PARTES DO PERSONAGEM
    pJoelho1 = new Point(0,0);
    pJoelho2 = new Point(0,0);
    pCabeca = new Point(275,300);
    pBracos = new Point(230,230);
    focus = false;
}

void Ciclista::render(){
    roda1->render();//renderiza a roda da esquerda
    //retas do quadro
    pCatraca->pLine(*pr1);
    pBanco->pLine(*pr1);
    pCatraca->pLine(*pBanco);
    pGarfo->pLine(*pBanco);
    pGarfo->pLine(*pCatraca);
    pGuidon->pLine(*pGarfo);
    pGuidon->pCircle(4, true);
    roda2->render();//renderiza a roda da direita
    pGarfo->pLine(*pr2);

    //posiciona os Joelhos
    pedal->getP1()->cIntersect(*pBanco, 80, 60, *pJoelho1);
    pedal->getP2()->cIntersect(*pBanco, 80, 60, *pJoelho2);
    if(focus){
        color(0,1,0);
        pBanco->pCircle(60, false);
        pedal->getP1()->pCircle(80, false);
        pedal->getP2()->pCircle(80, false);
        color(1,0,0);
        pJoelho1->pCircle(4, true);
        pJoelho2->pCircle(4, true);
        color(0,0,0);
    }

    //retas banco/joelho + joelho/pedal
    pBanco->pLine(*pJoelho1);
    pedal->getP1()->pLine(*pJoelho1);

    pedal->render();//renderiza os pedais + catraca

    //retas banco/joelho + joelho/pedal
    pBanco->pLine(*pJoelho2);
    pedal->getP2()->pLine(*pJoelho2);

    //cabeça + tronco + braços
    pCabeca->pCircle(40, true);
    pCabeca->pLine(*pBanco);
    pBracos->pLine(*pGuidon);
}

Ciclista::~Ciclista(){
    delete pCatraca;
    delete pBanco;
    delete pedal;
    delete pr1;
    delete roda1;
    delete pr2;
    delete roda2;
    delete pGarfo;
    delete pGuidon;
    delete pJoelho1;
    delete pJoelho2;
    delete pCabeca;
    delete pBracos;
}