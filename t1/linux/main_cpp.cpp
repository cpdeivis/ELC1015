#include <iostream>
#include <fstream>
#include <list>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "gl_canvas2d.hpp"

#include "Grafico.hpp"
#include "Amostra.hpp"
#include "Botao.hpp"

namespace Utils{
    Grafico *gEntrada;
    Grafico *gDCT;
    Grafico *gIDCT;
    Grafico *gDiff;

    std::list<Grafico *> graficos;
    std::list<Botao *> botoes;

    //*-- CALLBACKS DOS BOTÕES --*
    void readFile(){
        if(gEntrada->amostras.empty()){
            std::ifstream file("input.dct", std::ios::binary);
            if(file.is_open() == false)
                throw std::runtime_error{"Nao foi possivel abrir o arquivo!"};

            int num_amostras;
            file.read(reinterpret_cast<char*>(&num_amostras), 4);
            std::cout << num_amostras << std::endl;
            std::int8_t amostra;
            Amostra * ponto;
            std::int16_t max = 0;
            for(int i = 0; i < num_amostras && file.eof() == false; i++){
                file.read(reinterpret_cast<char*>(&amostra), 1);

                ponto = new Amostra(0,0, 4, (int)amostra);
                ponto->setLabel();
                gEntrada->amostras.push_back(ponto);

                amostra = abs((int)amostra);
                max = amostra > max ? amostra : max;
            }
            file.close();

            gEntrada->setMax(max);
            gEntrada->ajustAmostras();
        }
        return;
    }
    void saveFile(){
        if(!gIDCT->amostras.empty()){
            std::ofstream ofs("output.dct", std::ios::binary);
            std::int32_t N = gIDCT->amostras.size();
            ofs.write(reinterpret_cast<char*>(&N), sizeof N);
            std::int8_t val = 0;
            for(auto am : gIDCT->amostras){
                val = am->val;
                ofs.write(reinterpret_cast<char*>(&val), sizeof val);
            }
            ofs.close();
        }
    }
    void DIFF(){
        int N = gIDCT->amostras.size();
        if(gDiff->amostras.empty() && !gIDCT->amostras.empty() && gIDCT->amostras.size() == gEntrada->amostras.size()){
            auto it1 = gIDCT->amostras.begin();
            auto it2 = gEntrada->amostras.begin();
            Amostra * am;
            std::int16_t val = 0, maior = 0;
            for (int i = 0; i < N; i++, it1++, it2++){
                val = (*it1)->val - (*it2)->val;
                am = new Amostra(0, 0, 4, val);
                am->setLabel();
                gDiff->amostras.push_back(am);

                val = abs(val);
                maior = val > maior ? val : maior;
            }
            gDiff->setMax(maior);
            gDiff->ajustAmostras();
        }
        return;
    }
    void IDCT(){
        int N = gDCT->amostras.size();
        if(N > 0 && gIDCT->amostras.empty()){
            std::int16_t maior = 0, val = 0;
            Amostra * idct;
            double sum, s;
            for (int i = 0, k = 0; i < N; i++){
                k = 0;
                sum = 0.;
                for(Amostra * dct : gDCT->amostras){
                    s = k > 0 ? 1. : sqrt(.5);
                    sum += s * dct->val * cos(M_PI * (i + .5) * k/N);
                    k++;
                }

                val = (std::int16_t)(sum * sqrt(2.0/N));
                idct = new Amostra(0, 0, 4, val);
                idct->setLabel();
                gIDCT->amostras.push_back(idct);

                val = abs(val);
                maior = val > maior ? val : maior;
            }
            gIDCT->setMax(maior);
            gIDCT->ajustAmostras();
            //CALCULA A DIFF
            DIFF();
        }
        return;
    }
    void DCT(){
        int N = gEntrada->amostras.size();
        if(N > 0 && gDCT->amostras.empty()){
            std::int16_t maior = 0, val = 0;
            Amostra * dct;
            double sum, s;
            for (int i = 0, k = 0; i < N; i++){
                sum = 0.;
                s = i > 0 ? 1. : sqrt(.5);

                k = 0;
                for(Amostra * am : gEntrada->amostras){
                    sum += s * am->val * cos(M_PI * (k + .5) * i/N);
                    k++;
                }
                
                val = (std::int16_t)(sum * sqrt(2.0/N));
                dct = new Amostra(0, 0, 4, val);
                dct->setLabel();
                gDCT->amostras.push_back(dct);

                val = abs(val);
                maior = val > maior ? val : maior;
            }
            
            gDCT->setMax(maior);
            gDCT->ajustAmostras();
            //CALCULA PARA A IDCT
            IDCT();
        }
        return;
    }
    void clearAmostras(){
        for (Grafico *g : graficos)
        {
            //Limpa todas as amostras
            g->amostras.clear();
        }
    }
    // END CALLBACKS
    void initBotaos(){  
        botoes.clear();

        Botao *read = new Botao(0,0);
        read->setLabel("ABRIR");
        read->callback = readFile;
        
        Botao *aplica = new Botao(0,0);
        aplica->setLabel("APLICAR");
        aplica->callback = DCT;

        Botao *quantiza = new Botao(0,0);
        quantiza->setLabel("QUANTIZA");
        quantiza->callback = DCT;

        Botao *clear = new Botao(0,0);
        clear->setLabel("CLEAR");
        clear->setColor(1.0,0.0,0.0);
        clear->callback = clearAmostras;

        Botao *save = new Botao(0,0);
        save->setLabel("SALVAR");
        save->setColor(0.0,0.8,0.0);
        save->callback = saveFile;

        botoes.push_back(read);
        botoes.push_back(aplica);
        botoes.push_back(quantiza);
        botoes.push_back(clear);
        botoes.push_back(save);
    }
    void initGraficos(){
        gIDCT = new Grafico();
        gIDCT->setLabel("I D C T");

        gEntrada = new Grafico();
        gEntrada->setLabel("I N I C I A L");

        gDiff = new Grafico();
        gDiff->setLabel("D I F F");

        gDCT = new Grafico();
        gDCT->setLabel("D C T");

        graficos.push_back(gEntrada);
        graficos.push_back(gDCT);
        graficos.push_back(gIDCT);
        graficos.push_back(gDiff);
    }
} // namespace Utils

//*--FUNÇÕES DA CANVAS--*
void keyboard(int key){
    //nothing to do
}
void keyboardUp(int key){
    //nothing to do
}
void mouse(int button, int state, int wheel, int direction, int x, int y){
    y = (y - altura) * -1;
    if (button == 0 && state == 0){
        for (Botao *b : Utils::botoes)
            if (b->colision(x, y)){
                b->callback();
                return;
            }
    }
    for (Botao *b : Utils::botoes){
        if (b->colision(x, y)){
            b->focus = true;
            return;
        }
        b->focus = false;
    }
        
    for (Grafico *g : Utils::graficos)
        for (Amostra *a : g->amostras){
            if (a->colision(x, y)){
                a->focus = true;
                return;
            }
            a->focus = false;
        }
}
void render(){
    for (Botao *b : Utils::botoes)
        b->render();
    for (Grafico *g : Utils::graficos)
        g->render();
}
void onResize(){
    int w = floor((double)largura * 0.48725);
    int h = floor((double)altura * 0.458);
    int bx = ceil((double)largura * 0.0085);
    int by = ceil((double)altura * 0.0085);

    Utils::gIDCT->setDimension(bx, by, w, h);
    Utils::gEntrada->setDimension(bx, Utils::gIDCT->getY2() + by, w, h);
    Utils::gDiff->setDimension(Utils::gIDCT->getX2() + bx, by, w, h);
    Utils::gDCT->setDimension(Utils::gDiff->getX(), Utils::gEntrada->getY(), w, h);

    auto passo = bx;
    for (Botao *bt : Utils::botoes){
        bt->setX(passo);
        bt->setY(Utils::gEntrada->getY2() + by);
        passo += bx + 100;
    }
}
//END FUNÇÕES DA CANVAS

int main(int argc, char const *argv[]){
    Utils::initGraficos();
    Utils::initBotaos();
    
    initCanvas(1005, 610, "Trabalho 1 - Deivis Costa Pereira");
    runCanvas();

    return 0;
}