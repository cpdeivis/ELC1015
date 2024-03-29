/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#ifndef POINT_H
#define POINT_H

class Point{
    public:
        double x, y, z;
        Point();
        Point(const Point & p);
        Point(double x, double y);
        Point(double x, double y, double z);

        void RotateX(double ang);
        void RotateY(double ang);
        void RotateZ(double ang);
        void Translate(double x, double y, double z);
        void Projection(double d);
        
        bool Colision(double x, double y, double s);
};

#endif