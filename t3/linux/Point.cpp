/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

#include "Point.hpp"

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