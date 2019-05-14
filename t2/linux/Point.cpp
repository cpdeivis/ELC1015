#include "Point.hpp"
#include "gl_canvas2d.hpp"
#include <cmath>

Point::Point() : mtx(){
    x = y = 0;
}
Point::Point(double x, double y) : mtx(){
    this->x = x;
    this->y = y;
}
//Aplica a Matriz aos Pontos
void Point::aplica(){
    mtx.byPoint(x, y);
    mtx.loadIdentity();
}
//Matriz de Rotação
void Point::rotate(double ang){
    Matrix R;
    R(0,0) = cos(ang);
    R(0,1) = sin(ang);
    R(1,0) = -sin(ang);
    R(1,1) =  cos(ang);

    mtx = mtx * R;
}
//Matriz de Translação
void Point::translate(double dx, double dy){
    Matrix T;
    T(0,2) = dx;
    T(1,2) = dy;

    mtx = mtx * T;
}
//Matriz de Escala
void Point::scale(double sx, double sy){
    Matrix S;
    S(0,0) = sx;
    S(1,1) = sy;

    mtx = mtx * S;
}
//Utils de render a partir de um Ponto
void Point::pLine(Point &p2){
    line(x, y, p2.x, p2.y);
}
void Point::pCircle(double r, bool f){
    if(f)
        circleFill(x, y, r, 30);
    else
        circle(x, y, r, 30);
}

//Intersecção de dois Círculos
//http://paulbourke.net/geometry/circlesphere/
void Point::cIntersect(Point &p2, double r0, double r1, Point &res){
    double dx, dy, d, a, h, x2, y2;
    //distância entre o centro dos círculos
    dx = p2.x - x;
    dy = p2.y - y;
    d = hypot(dx,dy);
    if (d > (r0 + r1)){
        //círculos não possuem intersecção
        return;
    }
    if (d < fabs(r0 - r1)){
        //um dentro do outro
        return;
    }
    //distância do ponto 0 para o ponto 2
    a = (pow(r0, 2)-pow(r1,2)+pow(d, 2))/(2*d);
    //distância do ponto 2 para os pontos de intersecção
    h = sqrt(pow(r0,2) - pow(a,2));
    //coordenadas ponto 2
    x2 = x + (dx * a/d);
    y2 = y + (dy * a/d);
    //coordenadas do ponto 3, intersecção
    res.x = x2 + h*(dy)/d;;
    res.y = y2 - h*(dx)/d;
}