#ifndef GRAFICO_H
#define GRAFICO_H

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
        void setDimension(int w, int h);
        void setMax(std::int16_t max);
        void ajustAmostras();
        ~Grafico();
};

#endif