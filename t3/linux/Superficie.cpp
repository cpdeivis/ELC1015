/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

#include "Superficie.hpp"
#include "gl_canvas2d.hpp"
#include <iostream>

Superficie::Superficie(int p, int f){
    npontos = p;
    nfaces = f;
    animation = 0.005; 
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
            //Operações sobre o Ponto
            data[j]->Translate(-10,-10,0);
            data[j]->RotateY(ang);
            data[j]->RotateZ(zang);
            data[j]->RotateX(xang);
            data[j]->Translate(400,10,0);
        }

        malha.push_back(data);
    }
}

void Superficie::moves(bool eixo, bool op, std::vector<Point *> pontos){
    if(!malha.empty()){
        double step = op ? 0.005 : -0.005;//verifica se soma ou diminui
        if(eixo){//True -> X
            xang += step;
        } else{//False -> Z
            zang += step;
        }
        aplica(pontos);//reconstroi a malha
    }
}

void Superficie::render(){
    if(!malha.empty()){
        //Animação =/
        for(auto vet : malha){
            for(auto p : vet){
                //Operações para a animação
                p->Translate(-440,-350,0);
                p->RotateY(animation);
                p->Translate(440,350,0);
            }
        } 
        color(0,0,0);
        //Desenha as arestas da malha
        for(int i = 0; i < nfaces; i++){
            for(int j = 0; j < npontos; j++){
                if(i == nfaces-1){
                    line(malha[i][j]->x, malha[i][j]->y, malha[0][j]->x, malha[0][j]->y);
                    if(j != npontos -1){
                        line(malha[i][j]->x, malha[i][j]->y, malha[i][j+1]->x, malha[i][j+1]->y);
                    }
                }else{
                    line(malha[i][j]->x, malha[i][j]->y, malha[i+1][j]->x, malha[i+1][j]->y);
                    if(j != npontos -1){
                        line(malha[i][j]->x, malha[i][j]->y, malha[i][j+1]->x, malha[i][j+1]->y);
                    }
                }
            }
        }
        color(1,0,0);
        glPointSize(3);
        //Desenha os vertices da malha
        for(auto vet : malha){
            for(auto p : vet){
                point(p->x, p->y);
            }
        }
        glPointSize(1);
    }
}

void Superficie::clear(){
    for(auto vet : malha)
        vet.clear();
    malha.clear();

    zang = xang = 0.0;
}