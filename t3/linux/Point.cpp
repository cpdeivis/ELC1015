/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

#include "Point.hpp"
#include <cmath>

Point::Point(){
    x = y = z = 0;
}

Point::Point(const Point & p){
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
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
    double temp = y;
    y = y*cos(ang) - z*sin(ang);
    z = temp*sin(ang) + z*cos(ang);
}

void Point::RotateY(double ang){
    double temp = x;
    x = x*cos(ang) + z*sin(ang);
    z = -temp*sin(ang) + z*cos(ang);
}

void Point::RotateZ(double ang){
    double temp = x;
    x = x*cos(ang) - y*sin(ang);
    y = temp*sin(ang) + y*cos(ang);
}

void Point::Translate(double x, double y, double z){
    this->x += x;
    this->y += y;
    this->z += z;
}

void Point::Projection(double d){
    this->x = (x*d) / z;
    this->y = (y*d) / z;
    this->z = 0;
}

bool Point::Colision(double x, double y, double s){
    return (x > this->x-s && x < this->x+s) && (y > this->y-s && y < this->y+s);
}