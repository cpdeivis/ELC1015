/* CLASSE CICLISTA:
* É utilizada para montar o ciclista(bike + boneco)
* Uma coleção de pontos, que os renderiza de forma adequada
*/

#ifndef CICLISTA_H
#define CICLISTA_H

#include "Point.hpp"
/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
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
        Point * pBanco;//Ponto Banco
        Point * pGarfo;//origem do garfo
        Point * pGuidon;//origem Guidon

        Point * pJoelho1;//Ponto Joelho 1
        Point * pJoelho2;//Ponto Joelho 2
        Point * pCabeca;//Ponto Cabeça
        Point * pBracos;//Ponto Braços
    public:
        bool focus;//flag para mostrar o movimento
        Ciclista();
        void render();
        ~Ciclista();
};
#endif