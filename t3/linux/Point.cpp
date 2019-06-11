/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

#include "Point.hpp"
#include <cmath>

Point::Point(){
    x = y = z = 0;
}

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
    this->z = 0;
}

Point::Point(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point::RotateX(double ang){
    y = y*cos(ang) - z*sin(ang);
    z = y*sin(ang) + z*cos(ang);
}

void Point::RotateY(double ang){
    x = x*cos(ang) + z*sin(ang);
    z = -x*sin(ang) + z*cos(ang);
}

void Point::RotateZ(double ang){
    x = x*cos(ang) - y*sin(ang);
    y = x*sin(ang) + y*cos(ang);
}

void Point::Translate(double x, double y, double z){
    this->x += x;
    this->y += y;
    this->z += z;
}