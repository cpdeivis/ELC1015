/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

Requisitos Básicos:
    [X] Modelagem do objeto;
    [0] Animação (rotação)*;
    [0] Visualização (sob vários ângulos) em wireframe:
        [X] Ortografica;
        [0] Perspectiva**;
    [X] Parametrização do número de pontos e faces do objeto gerado.

    * Rotação em torno da "origem" não do "centro" do objeto;
    ** Função implementada mas não incorporada.

Extras:
    [X] Adição de mais de 4 pontos de controle.
    - Makefile para compilar no linux;

Instruções de Uso:
    O retangulo a esquerda da tela é a area de desenho da curva, a mesma pode ter N pontos de controle.
    Para mover um ponto desejado basta clicar sobre o mesmo e arrastar para a posição desejada;

    Teclado:
        Seta Cima -> Incrementa angulo Z;
        Seta Baixo -> Decrementa angulo Z;
        Seta Esquerda -> Decrementa angulo X;
        Seta Direita -> Incrementa angulo X;
        Tecla'C' -> Limpar a Curva + Wireframe;
        Tecla'M' -> Adicionar Faces;
        Tecla'N' -> Remover Faces;
        Tecla'P" -> Adicionar Pontos;
        Tecla'O' -> Remover Pontos.