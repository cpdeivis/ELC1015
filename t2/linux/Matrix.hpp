/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

#ifndef MATRIX_H
#define MATRIX_H

#pragma once
/* Classe da Matriz de Transformações
*  Transformações: Rotação, Translação, Escala */
class Matrix{
    private:
        double m[3][3]; //em coordenadas homogêneas
    public:
        Matrix();
        void loadIdentity();  //carrega matriz identidade
        void byPoint(double &x, double &y); //multiplica por um ponto
        Matrix operator*(Matrix &);
        double& operator()(const unsigned &, const unsigned &);
        //Vector operator*(Vector v);  //multiplica um ponto v pela matriz
        ~Matrix();
};

#endif