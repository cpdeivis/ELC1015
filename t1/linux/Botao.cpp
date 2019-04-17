#include "Botao.hpp"
#include "gl_canvas2d.hpp"

Botao::Botao(int x, int y):General(x, y){
    w = 100;
    h = 30;
}

Botao::Botao(int x, int y, int w, int h):General(x, y){
    this->w = w;
    this->h = h;
}

void Botao::render(){
    color(c.r, c.g, c.b);
    if(focus){
        rectFill(x, y, x+w, y+h);
        color(1.0,1.0,1.0);
    }
    else
        rect(x, y, x+w, y+h);
    
    //TODO: ARRUMAR A LABEL NO LUGAR CERTO
    text(x+10, y+10, label.c_str());
    
}

bool Botao::colision(int x, int y){
    return (x > this->x && x < this->x+w) && (y > this->y && y < this->y+h);
}

int Botao::getX2(){
    return x + w;
}

int Botao::getY2(){
    return y + h;
}

Botao::~Botao(){
    //destructor
}