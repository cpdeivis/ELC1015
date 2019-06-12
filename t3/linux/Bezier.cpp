/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

#include "Bezier.hpp"
#include "gl_canvas2d.hpp"
#include <cmath>

Bezier::Bezier(int n, Point * p1, Point * p2){
    cpontos = n;
    this->p1 = p1;
    this->p2 = p2;
}

double fatorial(int n){
    double x = 1.0;
    for (int i = 1; i <= n; i++)
      x *= (double)i;
    return x;
}

double Ni(int n, int i){
    double a1 = fatorial(n);
    double a2 = fatorial(i);
    double a3 = fatorial(n - i);
    return a1/ (a2 * a3);//Ni
}

double Bernstein(int n, int i, double t){
    double ti = (t == 0.0 && i == 0) ? 1.0 : pow(t, i); /* t^i */
    double tni = (n == i && t == 1.0) ? 1.0 : pow((1 - t), (n - i)); /* (1 - t)^i */ 
    return Ni(n, i) * ti * tni; //Bases Bernstein
}

void Bezier::aplica(){
    int npts = pcontrole.size();
    double step = (double)1.0 / (cpontos- 1);;
    double t = 0.0;

    pcurva.clear();

    for (int k = 0; k != cpontos; k++, t += step){ 
        if ((1.0 - t) < 5e-6) 
            t = 1.0;

        Point * p = new Point (0.0, 0.0);
        for (int i = 0; i != npts; i++){
            double b = Bernstein(npts-1, i, t);
            p->x += b * pcontrole[i]->x;
            p->y += b * pcontrole[i]->y;
        }

        pcurva.push_back(p);
    }
}

void Bezier::render(){
    color(1,1,1);
    rectFill(p1->x, p1->y, p2->x, p2->y);
    color(0,0,0);
    rect(p1->x, p1->y, p2->x, p2->y);
    glPointSize(2);
    color(1,0,0);
    for(Point * p : this->pcurva){
        point(p->x, p->y);
    }
    glPointSize(4);
    color(0,0,0);
    for(Point * p : this->pcontrole){
        point(p->x, p->y);
    }
    glPointSize(1);
}

double Bezier::getX(double x){
    return (x > p1->x + 5 ? (x < p2->x -5 ? x : p2->x -5) : p1->x + 5);
}

double Bezier::getY(double y){
    return (y > p1->y + 5 ? (y < p2->y -5 ? y : p2->y -5) : p1->y + 5);
}

Point * Bezier::Colision(double x, double y){
    if(x > p1->x + 5 && x < p2->x -5) /* Verifica se o Cursor está nos Limites da Area */
        if(y > p1->y + 5 && y < p2->y -5){ /* Coloca uma margem de segurança = 5px */
            for(auto p : pcontrole){
                if(p->Colision(x,y,5)){
                    // std::cout << "\n" << p->x << "|" << p->y;
                    return p;
                }
            }
            
            Point * p = new Point((double)x, (double)y);
            pcontrole.push_back(p);
            return p;
        }
    
    return NULL;
}