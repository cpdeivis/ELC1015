#include "Amostra.hpp"
#include "gl_canvas2d.hpp"

Amostra::Amostra(int x, int y, int raio, std::int16_t val):General(x, y){
    this->raio = raio;
    this->val = val;
}

Amostra::Amostra(int x, int y, int raio, std::int16_t val, Cor cor):General(x,y,cor){
    this->raio = raio;
    this->val = val;
}

void Amostra::render(){
    color(c.r, c.g, c.b);
    if(focus){
        circle(x, y, raio, 20);
        text(x-5, y+10, label.c_str());
    } else 
        circleFill(x, y, raio, 20);
}

bool Amostra::colision(int x, int y){
    return (x > getX() - raio && x < getX() + raio) && (y > getY() - raio && y < getY() + raio);
}

Amostra::~Amostra(){
    //destructor
}