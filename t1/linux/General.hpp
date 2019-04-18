/* Define uma Classe Geral para todos os objetos que serão manipulados em Tela;
 * Explicita as funções inerentes a todos os objetos filhos. */

#ifndef GENERAL_H
#define GENERAL_H

#pragma once

#include <string>

struct Cor{
    double r; //Vermelho
    double g; //Verde
    double b; //Azul
};
// Panel: sub-espaço da Tela
struct Panel{
    int x1, y1, x2, y2;

    int distX();
    int distY();
    int midleX();
    int midleY();
};

class General{
protected:
    int x, y;
    std::string label;
    Cor c;

public:
    bool focus;
    General(int x, int y);
    General(int x, int y, Cor c);
    General(int x, int y, std::string label);
    int getX();
    int getY();
    Cor getColor();
    std::string getLabel();
    void setX(int x);
    void setY(int y);
    void setColor(double r, double g, double b);
    void setLabel(std::string label);
    virtual void render();
    virtual bool colision(int x, int y);
    ~General();
};
#endif