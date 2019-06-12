/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */
#ifndef BEZIER_H
#define BEZIER_H

#include <vector>
#include "Point.hpp"

class Bezier{
    private:
        Point *p1;/* Area de desenho da curva eh */
        Point *p2;/*        definida por p1 e p2 */

    public:
        std::vector<Point *> pcontrole;//vetor de pontos de controle
        std::vector<Point *> pcurva;//vetor de pontos da curva
        int cpontos;//quantidade de pontos na curva

        Bezier(int n, Point * p1, Point* p2);
        void aplica();
        void render();

        double getX(double x);
        double getY(double y);

        Point * Colision(double x, double y);
};

#endif