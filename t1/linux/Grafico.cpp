#include "Grafico.hpp"
#include "gl_canvas2d.hpp"
#include <iostream>

Grafico::Grafico(int x, int y, int w, int h) : General(x, y){
    this->w = w;
    this->h = h;
    this->c = {1.0, 0.0, 0.0}; //Vermelho

    generatePanels(20, 5);
}

void Grafico::generatePanels(int size, int margem){
    //set size como altura do Titulo
    this->Title = {x, y + h - size, x + w, y + h};
    //set size de largura e margem vertical
    this->Escala = {x + size, y + margem, x + size, Title.y1 - margem};
    //margem em todo o retângulo desenhavel
    this->Drawable = {Escala.x1 + margem, Escala.y1, Title.x2 - margem, Escala.y2};
}

void Grafico::render(){
    color(c.r, c.g, c.b);
    rect(x, y, x + w, y + h);
    rect(Title.x1, Title.y1, Title.x2, Title.y2);
    text(Title.x1 + 1, Title.y1 + Title.midleY(), label.c_str());
    color(0.0, 0.0, 0.0);
    //TODO: AS ESCALAS, AQUI SÓ TEM A LINHA
    line(Escala.x1, Escala.y1, Escala.x2, Escala.y2);
    line(Escala.x1, Drawable.y1 + Drawable.midleY(), Drawable.x2, Drawable.y1 + Drawable.midleY());

    //Faz o render das amostras desse gráfico
    for(Amostra * ponto : this->amostras){
        ponto->render();
    }
}

bool Grafico::colision(int x, int y){
    //TODO
    return false;
}

Grafico::~Grafico(){
    //destructor
}

int Grafico::getX2(){
    return x+w;
}

int Grafico::getY2(){
    return y+h;
}
void Grafico::setDimension(int w, int h){
    this->w = w;
    this->h = h;
}