#ifndef AMOSTRA_H
#define AMOSTRA_H

#include "General.hpp"

class Amostra : public General{
    private:
        int raio;
        std::int16_t val;
    
    public:
        Amostra(int x, int y, int raio, std::int16_t val);
        Amostra(int x, int y, int raio, std::int16_t val, Cor cor);
        void render();
        bool colision(int x, int y);
        ~Amostra();
};

#endif