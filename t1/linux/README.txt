Instruções:
    - Para abrir o arquivo("input.dct"), utilizar o botão "ABRIR";
    - Para aplicar as funções(DCT, IDCT, DIFF) na amostra aberta, utilizar o botão "APLICAR";
    - Para limpar os gráfico, utilizar o botão "LIMPAR";
    - Para salvar o resultado reconstruído em "output.dct", utilizar o botão "SALVAR";

Requisitos: 
    [x] Leitura das amostras do arquivo de entrada no formato especificado. Os dados lidos serão do tipo byte, mas devem ser armazenado em memória utilizando um array de Int, variando entre -127 e +128;
    [x] Aplicação da DCT sobre as amostras de entrada;
    [x] Aplicação da transformada inversa (IDCT) para reconstrução dos dados originais;
    [x] Calcular a diferença entre a entrada e os dados reconstruídos;
    [x] Plotagem dos gráficos das quatro diferentes amostragens. O tamanho do gráfico deve se adaptar horizontalmente à quantidade de amostras lidas;
    [x] Salvar o resultado reconstruído em um arquivo “output.dct”, no mesmo formato do arquivo original.

Extras:
    - Toda a interface se ajusta conforme a largura e altura da janela;
    - Implementação de uma interface interativa ( botões para carregar o input, aplicar DCT, aplicar IDCT, sliders para visualizar melhor as amostras, etc.). Quanto menos cliques melhor;