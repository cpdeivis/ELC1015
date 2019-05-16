#include "Pedal.hpp"
#include "gl_canvas2d.hpp"

Pedal::Pedal(Point * pc){
    this->pc = pc;
    p1 = new Point(pc->x, pc->y + 30);
    p2 = new Point(pc->x, pc->y - 30); 
}

void Pedal::render(){
    p1->translate(pc->x, pc->y);
    p1->rotate(0.05);
    p1->translate(-pc->x, -pc->y);
    p1->aplica();

    p2->translate(pc->x, pc->y);
    p2->rotate(0.05);
    p2->translate(-pc->x, -pc->y);
    p2->aplica();

    color(0,0,0);
    pc->pLine(*p1);//Pedal 1
    color(0.8,0.8,0.8);
    pc->pCircle(20, true);//Catraca
    color(0,0,0);
    pc->pLine(*p2);//Pedal 2
    p1->pCircle(4, true);
    p2->pCircle(4, true);  
}

Point * Pedal::getP1(){
    return this->p1;   
}

Point * Pedal::getP2(){
    return this->p2;   
}

Pedal::~Pedal(){
    delete p1;
    delete p2;
}