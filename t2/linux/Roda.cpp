/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#include "Roda.hpp"
#include "gl_canvas2d.hpp"

Roda::Roda(Point * origem){
    this->org = origem;
    double ang = 0.0;
    for(int i = 0; i < 10; i++, ang+=0.628318531){
        Point * p = new Point(0, 50);//50 é o valor do raio
        p->translate(org->x, org->y);
        p->rotate(ang);
        p->aplica();
        this->raios.push_back(p);
    }
}

void Roda::render(){
    //render da roda em si
    color(0,0,0);
    org->pCircle(52, true);
    color(1,1,1);
    org->pCircle(50, true);
    //render dos raios
    color(0,0,0);
    org->pCircle(4, true);
    for(Point * p : raios){
        p->translate(org->x,org->y);
        p->rotate(0.05);
        p->translate(-org->x,-org->y);
        p->aplica();
        
        org->pLine(*p);
    }
}

Roda::~Roda(){
    for (auto p : raios){
        delete p;
    } 
    raios.clear();
}