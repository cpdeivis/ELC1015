/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#ifndef PEDAL_H
#define PEDAL_H

#include "Point.hpp"

#pragma once

class Pedal{
    private:
        Point * pc;//Ponto Central Catraca
        Point * p1;//Pedal 1
        Point * p2;//Pedal 2

    public:
        Pedal(Point * pc);
        void render();
        Point * getP1();
        Point * getP2();
        ~Pedal();
};

#endif