#include "Roda.hpp"
#include "gl_canvas2d.hpp"

Roda::Roda(Point * origem){
    this->org = origem;
    double ang = 0.0;
    for(int i = 0; i < 10; i++, ang+=0.628318531){
        Point * p = new Point(0, 50);
        p->rotate(ang);
        p->aplica();
        p->translate(org->x, org->y);
        p->aplica();
        this->raios.push_back(p);
    }
}

void Roda::render(){
    color(0,0,0);
    org->pCircle(52, true);
    color(1,1,1);
    org->pCircle(50, true);
    color(0,0,0);
    org->pCircle(4, true);
    for(Point * p : raios){
        p->translate(-org->x,-org->y);
        p->aplica();
        p->rotate(0.05);
        p->aplica();
        p->translate(org->x,org->y);
        p->aplica();
        
        org->pLine(*p);
    }
}