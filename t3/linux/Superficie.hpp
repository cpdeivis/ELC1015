/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include "Point.hpp"
#include <vector>

class Superficie{
    private:
        Point ** malha;
        int npontos;
        int nfaces;
    
    public:
        Superficie(int p, int f);
        void aplica(std::vector<Point *> pontos);
        void render();

        ~Superficie();
};

#endif