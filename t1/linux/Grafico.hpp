/* Classe Grafico:
 *   - inclui os atributos de dimensão(w ,h)
 *   - inclui a lista de amostras pertencentes ao gráfico 
 *   - inclui as Panels do gráfico:
 *       - Title: área destinada ao titulo;
 *       - Drawable: área destinada ao render das amostras;
 *       - Escala: legendas e eixos do gráfico;
 *   - atributo max, destinado a cálculo da escala/proporção;*/

#ifndef GRAFICO_H
#define GRAFICO_H

#pragma once

#include "General.hpp"
#include "Amostra.hpp"
#include <list>

class Grafico : public General{
    private:
        int w, h; //width and height
        Panel Title;
        Panel Drawable;
        Panel Escala; 
        std::int16_t max;
        void generatePanels(int size, int margem);
    
    public:
        std::list<Amostra*> amostras;
        Grafico();
        Grafico(int x, int y, int w, int h);
        void render();
        bool colision(int x, int y);
        int getX2();
        int getY2();
        void setDimension(int x, int y, int w, int h);
        void setMax(std::int16_t max);
        void ajustAmostras();
        ~Grafico();
};

#endif