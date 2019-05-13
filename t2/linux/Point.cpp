#include "Point.hpp"
#include <cmath>

Point::Point() : mtx(){
    x = y = 0;
}
Point::Point(double x, double y) : mtx(){
    this->x = x;
    this->y = y;
}

void Point::aplica(){
    mtx.byPoint(x, y);
    mtx.loadIdentity();
}
void Point::rotate(double ang){
    Matrix R;
    R(0,0) = cos(ang);
    R(0,1) = sin(ang);
    R(1,0) = -sin(ang);
    R(1,1) =  cos(ang);

    mtx = mtx * R;
}
void Point::translate(double dx, double dy){
    Matrix T;
    T(0,2) = dx;
    T(1,2) = dy;

    mtx = mtx * T;
}
void Point::scale(double sx, double sy){
    Matrix S;
    S(0,0) = sx;
    S(1,1) = sy;

    mtx = mtx * S;
}
