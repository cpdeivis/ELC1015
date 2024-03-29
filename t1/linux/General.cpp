#include "General.hpp"

/* Implementação das funções Gerais:
   Getters e Setters. */

General::General(int x, int y){
    this->x = x;
    this->y = y;
    this->focus = false;
    this->c = {0.0, 0.0, 0.0};
}

General::General(int x, int y, Cor c){
    this->x = x;
    this->y = y;
    this->c = c;
    this->focus = false;
}

General::General(int x, int y, std::string label){
    this->x = x;
    this->y = y;
    this->label = label;
    this->focus = false;
}

int General::getX(){
    return this->x;
}

int General::getY(){
    return this->y;
}

Cor General::getColor(){
    return this->c;
}

std::string General::getLabel(){
    return this->label;
}

void General::setX(int x){
    this->x = x;
}

void General::setY(int y){
    this->y = y;
}

void General::setColor(double r, double g, double b){
    c.r = r;
    c.g = g;
    c.b = b;
}

void General::setLabel(std::string label){
    this->label = label;
}

General::~General(){    
    //destructor
}

bool General::colision(int x, int y){
    return false;
}

void General::render(){
}

// Funções das Panels
int Panel::distX(){
    return x2 - x1;
}

int Panel::distY(){
    return y2 - y1;
}

int Panel::midleX(){
    return (int)(distX() / 2);
}

int Panel::midleY(){
    return (int)(distY() / 2);
}