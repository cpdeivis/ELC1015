#ifndef POINT_H
#define POINT_H

#include "Matrix.hpp"

#pragma once

class Point{
    private:
        Matrix mtx; 
    public:
        double x, y;
        
        Point();
        Point(double x, double y);
        void aplica();
        void rotate(double ang);  //rotação
        void translate(double dx, double dy); //translação
        void scale(double sx, double sy);  //escala
};
#endif