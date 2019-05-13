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
    circleFill(org->x, org->y, 54, 20);
    color(1,1,1);
    circleFill(org->x, org->y, 50, 20);
    color(0,0,0);
    for(Point * p : raios){
        p->translate(-org->x,-org->y);
        p->aplica();
        p->rotate(0.05);
        p->aplica();
        p->translate(org->x,org->y);
        p->aplica();
        line(org->x,org->y, p->x, p->y);
    }
}