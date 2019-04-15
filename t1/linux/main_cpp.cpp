#include <iostream>
#include <list>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.hpp"

#include "Grafico.hpp"
#include "Amostra.hpp"
#include "Botao.hpp"

namespace Utils
{
Grafico *Entrada;
Grafico *DCT;
Grafico *IDCT;
Grafico *Diff;

int border = 5;

std::list<Grafico *> graficos;
std::list<Botao *> botoes;
void initGraficos()
{
    int w = 495;
    int h = 280;

    IDCT = new Grafico(border, border, w, h);
    IDCT->setLabel("I D C T");

    Entrada = new Grafico(border, IDCT->getY2() + border, w, h);
    Entrada->setLabel("I N I C I A L");

    Diff = new Grafico(IDCT->getX2() + border, border, w, h);
    Diff->setLabel("D I F F");

    DCT = new Grafico(Diff->getX(), Entrada->getY(), w, h);
    DCT->setLabel("D C T");

    graficos.push_back(Entrada);
    graficos.push_back(DCT);
    graficos.push_back(IDCT);
    graficos.push_back(Diff);
}
// CALLBACKS DOS BOTÕES
void readFile()
{
    // std::ifstream file("base2.dct", std::ios::binary);
    // if(file.is_open() == false)
    //     throw std::runtime_error{"Nao foi possivel abrir o arquivo!"};

    // std::uint32_t num_amostras;
    // file.read(reinterpret_cast<char*>(&num_amostras), 4);
    // std::list<std::int16_t> lsAmostras;
    // std::int8_t amostra;
    // while(file.eof() == false){
    //     file.read(reinterpret_cast<char*>(&amostra), 1);
    //     lsAmostras.push_back((int)amostra);
    //     std::cout << "Amostra = " << (int)amostra << std::endl;
    // }

    // std::cout << "Num Amostras = " << num_amostras << std::endl;
}
void saveFile()
{
    //TODO
}
void clearAmostras()
{
    for (Grafico *g : graficos)
    {
        //Limpa todas as amostras
        g->amostras.clear();
    }
}
void initBotaos()
{
    botoes.clear();

    Botao *read = new Botao(border, Entrada->getY2() + border);
    read->setLabel("R E A D");
    read->callback = readFile;
    Botao *save = new Botao(border + read->getX2(), read->getY());
    save->setLabel("S A V E");
    save->callback = saveFile;
    Botao *clear = new Botao(border + save->getX2(), read->getY());
    clear->setLabel("C L E A R");
    clear->callback = clearAmostras;

    botoes.push_back(read);
    botoes.push_back(save);
    botoes.push_back(clear);
}
} // namespace Utils

//*--FUNÇÕES DA CANVAS--*
void keyboard(int key)
{
    //nothing to do
}
void keyboardUp(int key)
{
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    //TODO
    y = (y - 563) * -1;
    if (button == 0 && state == 0)
    {
        for (Botao *b : Utils::botoes)
            if (b->colision(x, y))
            {
                b->callback();
                return;
            }
    }
    for (Grafico *g : Utils::graficos)
        for (Amostra *a : g->amostras)
        {
            if (a->colision(x, y))
            {
                a->focus = true;
                return;
            }
            a->focus = false;
        }
}
void render()
{
    for (Botao *b : Utils::botoes)
        b->render();
    for (Grafico *g : Utils::graficos)
        g->render();
}

int main(int argc, char const *argv[])
{
    initCanvas(1010, 605, "Trabalho 1 - Deivis Costa Pereira");
    Utils::initGraficos();
    Utils::initBotaos();
    runCanvas();
    return 0;
}