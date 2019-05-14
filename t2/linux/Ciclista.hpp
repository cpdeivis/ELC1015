#ifndef CICLISTA_H
#define CICLISTA_H

#include "Point.hpp"
#include "Roda.hpp"
#include "Pedal.hpp"

#pragma once

class Ciclista{
    private:
        Point * pr1;//origem da roda 1
        Point * pr2;//origem da roda 2
        Roda * roda1;//roda 1
        Roda * roda2;//roda 2
        
        Point * pCatraca;//origem da catraca da bike
        Pedal * pedal;//pedal/catraca

        Point * pJoelho1;//Ponto Joelho 1
        Point * pJoelho2;//Ponto Joelho 2
        Point * pCabeca;//Ponto Cabeça
        Point * pBanco;//Ponto Banco
    public:
        Ciclista();
        void render();
        ~Ciclista();
};
#endif