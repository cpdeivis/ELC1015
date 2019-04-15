#ifndef BOTAO_H
#define BOTAO_H

#include "General.hpp"
#include <functional>

class Botao : public General{
    private:
        int w, h; //width and height

    public:
        std::function<void(void)> callback;
        Botao(int x, int y);
        Botao(int x, int y, int w, int h);
        void render();
        bool colision(int x, int y);
        int getX2();
        int getY2();
        ~Botao();
};

#endif