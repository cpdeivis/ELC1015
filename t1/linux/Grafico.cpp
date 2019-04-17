#include "Grafico.hpp"
#include "gl_canvas2d.hpp"
#include <iostream>

Grafico::Grafico() : General(0, 0){
    this->w = 0;
    this->h = 0;
    this->c = {1.0, 0.0, 0.0}; //Vermelho
    this->max = 0;
}

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
    this->Escala = {x + size + margem*3, y + margem, x + size + margem*3, Title.y1 - margem};
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
    text(Escala.x1 - 35, Escala.y2 - 5, std::to_string(max).c_str());
    text(Escala.x1 - 35, Escala.y1, std::to_string(max*-1).c_str());
    line(Escala.x1, Drawable.y1 + Drawable.midleY(), Drawable.x2, Drawable.y1 + Drawable.midleY());
    text(Escala.x1 - 35, Drawable.y1 + Drawable.midleY() - 3, "0");

    //Faz o render das amostras desse gráfico
    if(!this->amostras.empty()){
        auto it1 = this->amostras.begin();
        auto it2 = it1;
        it2++;
        (*it1)->render();
        while(it2 != this->amostras.end()){
            (*it2)->render();
            line((*it1)->getX(), (*it1)->getY(), (*it2)->getX(), (*it2)->getY());
            it1++;
            it2++;
        }
    }
    // for(Amostra * ponto : this->amostras){
    //     ponto->render();
    // }
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

void Grafico::setDimension(int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    generatePanels(30, 5);
    ajustAmostras();
}

void Grafico::setMax(std::int16_t max){
    this->max = max;
}

void Grafico::ajustAmostras(){
    if(max != 0 && !amostras.empty()){
        int passo_x = Drawable.distX()/(amostras.size() == 1 ? 2 : amostras.size() - 1);
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
}