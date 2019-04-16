#include "Grafico.hpp"
#include "gl_canvas2d.hpp"
#include <iostream>

Grafico::Grafico(int x, int y, int w, int h) : General(x, y){
    this->w = w;
    this->h = h;
    this->c = {1.0, 0.0, 0.0}; //Vermelho
    this->max = 0;

    generatePanels(30, 5);
}

void Grafico::generatePanels(int size, int margem){
    //set size como altura do Titulo
    this->Title = {x, y + h - size, x + w, y + h};
    //set size de largura e margem vertical
    this->Escala = {x + size + margem, y + margem, x + size + margem, Title.y1 - margem};
    //margem em todo o retângulo desenhavel
    this->Drawable = {Escala.x1, Escala.y1, Title.x2 - margem, Escala.y2};
}

void Grafico::render(){
    color(c.r, c.g, c.b);
    rect(x, y, x + w, y + h);
    rect(Title.x1, Title.y1, Title.x2, Title.y2);
    text(Title.x1 + 1, Title.y1 + Title.midleY(), label.c_str());
    color(0.0, 0.0, 0.0);
    //TODO: AS ESCALAS, AQUI SÓ TEM A LINHA
    line(Escala.x1, Escala.y1, Escala.x2, Escala.y2);
    text(Escala.x1 - 25, Escala.y2 - 5, std::to_string(max).c_str());
    text(Escala.x1 - 25, Escala.y1, std::to_string(max*-1).c_str());
    line(Escala.x1, Drawable.y1 + Drawable.midleY(), Drawable.x2, Drawable.y1 + Drawable.midleY());
    text(Escala.x1 - 25, Drawable.y1 + Drawable.midleY() - 3, "0");

    //Faz o render das amostras desse gráfico
    for(Amostra * ponto : this->amostras){
        ponto->render();
    }
}

bool Grafico::colision(int x, int y){
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

void Grafico::setMax(std::int16_t max){
    this->max = max;
}

void Grafico::ajustAmostras(){
    int passo_x = this->Drawable.distX()/this->amostras.size();
    double rel_y = (double)(this->Drawable.distY())/(double)(max*2);
    int aux = this->Drawable.x1;
    int auy = 0, mdy = this->Drawable.midleY() + this->Drawable.y1;
    for(Amostra * ponto : this->amostras){
        // Resolve X
        ponto->setX(aux);
        aux += passo_x;
        //Resolve Y
        auy = (int)((double)(ponto->val)*rel_y);
        ponto->setY(mdy + auy);
    } 
}