#ifndef AMOSTRA_H
#define AMOSTRA_H

#pragma once

#include "General.hpp"

class Amostra : public General{
    private:
        int raio;
    
    public:
        std::int16_t val;

        Amostra(int x, int y, int raio, std::int16_t val);
        Amostra(int x, int y, int raio, std::int16_t val, Cor cor);
        void setLabel();
        void render();
        bool colision(int x, int y);
        ~Amostra();
};

#endif