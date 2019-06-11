/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#ifndef BEZIER_H
#define BEZIER_H

#include <vector>
#include "Point.hpp"

class Bezier{
    public:
        std::vector<Point *> pcontrole;//vetor de pontos de controle
        std::vector<Point *> pcurva;//vetor de pontos da curva
        int cpontos;//quantidade de pontos na curva

        Bezier(int n);
        void aplica();
        void render();
};

#endif