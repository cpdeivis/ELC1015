/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#ifndef RODA_H
#define RODA_H

#include "Point.hpp"
#include <vector>

#pragma once

//Classe para a roda da Bicicleta
class Roda{
    private:
        Point * org;
        std::vector<Point *> raios; 
        
    public:
        Roda(Point * origem);
        void render();
        ~Roda();
};

#endif