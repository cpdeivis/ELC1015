/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

#include "Superficie.hpp"
#include "gl_canvas2d.hpp"
#include <iostream>

Superficie::Superficie(int p, int f){
    npontos = p;
    nfaces = f;
}

void Superficie::aplica(std::vector<Point *> pontos){
    //LIMPA o que já existia na malha
    for(auto vet : malha)
        vet.clear();
    malha.clear();

    double ang = 0.0;
    double step = PI_2 / nfaces;
    //Reconstroi a malha
    std::vector<Point *> data;//auxiliar
    for(int i = 0; i < nfaces; i++, ang+=step){
        data.clear();
        for(int j = 0; j < npontos; j++){
            data.push_back(new Point(*pontos[j]));
            data[j]->Translate(-90,-350,0);
            data[j]->RotateY(ang);
            data[j]->Translate(440,350,0);
        }

        malha.push_back(data);
    }
}

void Superficie::render(){
    if(!malha.empty()){
        color(0,0,0);
        glPointSize(2);
        for(auto vet : malha){
            for(auto p : vet){
                point(p->x, p->y);
            }
        }
        glPointSize(1);
        for(int i = 0; i < nfaces-1; i++){
            for(int j = 0; j < npontos-1; j++){
                line(malha[i][j]->x, malha[i][j]->y, malha[i+1][j]->x, malha[i+1][j]->y );
                line(malha[i][j]->x, malha[i][j]->y, malha[i][j+1]->x, malha[i][j+1]->y );
            }
        }
    }
}
