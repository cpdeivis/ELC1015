/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include "Point.hpp"
#include <vector>

class Superficie{
    private:
        std::vector<std::vector<Point *>> malha;
        double animation;

    public:
        double zang;
        double xang;
        int npontos;
        int nfaces;
        
        Superficie(int p, int f);
        void aplica(std::vector<Point *> pontos);
        void render();
        void moves(bool eixo, bool op, std::vector<Point *> pontos);

        void clear();

        ~Superficie();
};

#endif