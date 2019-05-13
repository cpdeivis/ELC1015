#include "Matrix.hpp"
#include <cmath>

/* Implementação da Matriz de Transformações */

Matrix::Matrix(){
    this->loadIdentity();
}

Matrix Matrix::operator*(Matrix & B){
    Matrix result;

    for (int i = 0; i < 3; i++)  
    for (int j = 0; j < 3; j++){ 
        result(i,j) = 0; 
        for (int k = 0; k < 3; k++)   
            result(i,j) += m[i][k] * B(k,j);
    }

    return result;
}

void Matrix::byPoint(double &x, double &y){
    double B[] {x, y, 1};
    double result[] {0,0,0};
    for (int i = 0; i < 3; i++)  
    for (int k = 0; k < 3; k++)   
        result[i] += this->m[i][k] * B[k];
    
    x = result[0];
    y = result[1];
}

void Matrix::loadIdentity(){
    for(auto i = 0; i < 3; i++)
    for(auto j = 0; j < 3; j++)
        m[i][j] = i == j ? 1 : 0;
}

double& Matrix::operator()(const unsigned &lin, const unsigned &col){
    return this->m[lin][col];
}

Matrix::~Matrix(){
    //todo
}