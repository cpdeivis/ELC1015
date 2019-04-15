#ifndef GRAFICO_H
#define GRAFICO_H

#include "General.hpp"
#include "Amostra.hpp"
#include <vector>

class Grafico : public General{
    private:
        int w, h; //width and height
        Panel Title;
        Panel Drawable;
        Panel Escala; 
        void generatePanels(int size, int margem);
    
    public:
        std::vector<Amostra*> amostras;
        Grafico(int x, int y, int w, int h);
        void render();
        bool colision(int x, int y);
        ~Grafico();
};

#endif