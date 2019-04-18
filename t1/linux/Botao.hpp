/* Classe Botão:
 *   - inclui os atributos de dimensão(w ,h)
 *   - inclui o atributo para a função de callback (void *) */

#ifndef BOTAO_H
#define BOTAO_H

#pragma once

#include "General.hpp"
#include <functional>

class Botao : public General{
    private:
        int w, h; //width and height

    public:
        //Recebe uma função void sem parâmetros
        std::function<void(void)> callback;
        Botao(int x, int y);
        Botao(int x, int y, int w, int h);
        void render();
        bool colision(int x, int y);

        // Utilizadas para pegar o ponto superior do retângulo
        int getX2();
        int getY2();
        ~Botao();
};

#endif