/* Deivis Costa Pereira */
/* dcpereira@inf.ufsm.br */

Instruções:
    - O arquivo "input.dct" deve estar na "pasta pai" da do projeto codeblocks, segue estrutura:
        |- *\pasta_pai\
            |- lib\*
            |- t1_dcpereira\* <- "pasta do projeto"
            |- freeglut.dll
            |- glfw3.dll
            |- input.dct <- "arquivo de entrada aqui"
            
    - Para abrir o arquivo("input.dct"), utilizar o botão "ABRIR";
    - Para aplicar as funções(DCT, IDCT, DIFF) na amostra aberta, utilizar o botão "APLICAR";
    - Para utilizar o vetor de quantização com fator 5, usar o botão "QUANT 5";
    - Para limpar os gráficos e vetor de quantização, utilizar o botão "LIMPAR";
    - Para salvar o resultado reconstruído em "output.dct", utilizar o botão "SALVAR";

Requisitos: 
    [x] Leitura das amostras do arquivo de entrada no formato especificado. Os dados lidos serão do tipo byte, mas devem ser armazenado em memória utilizando um array de Int, variando entre -128 e +127;
    [x] Aplicação da DCT sobre as amostras de entrada;
    [x] Aplicação da transformada inversa (IDCT) para reconstrução dos dados originais;
    [x] Calcular a diferença entre a entrada e os dados reconstruídos;
    [x] Plotagem dos gráficos das quatro diferentes amostragens. O tamanho do gráfico deve se adaptar horizontalmente à quantidade de amostras lidas;
    [x] Salvar o resultado reconstruído em um arquivo “output.dct”, no mesmo formato do arquivo original.

Extras:
    - Vetor de quantização 1D;
    - Toda a interface se ajusta conforme a largura e altura da janela;
    - Implementação de uma interface interativa (botões para carregar o input, aplicar DCT, aplicar IDCT, sliders para visualizar melhor as amostras, etc.). Quanto menos cliques melhor;
