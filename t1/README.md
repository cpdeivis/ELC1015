# Trabalho 1 - Transformada Discreta de Cosseno

Desenvolva um programa que aplique a Transformada Discreta de Cosseno (DCT) e sua inversa (IDCT) em um sinal amostrado unidimensional. O programa deve ler as amostras de sinal de um arquivo binário “*input.dct*”, onde o cabeçalho é um dado do tipo Unsigned Int ( 4 bytes ) representando a quantidade de amostras a serem lidas, e as amostras são armazenadas sequencialmente, cada uma ocupando 1 byte ( cada amostra deverá ter valor entre -127 e 128 ). O número de amostras deve variar entre **8 e 64**. O número de funções base deve ser igual ao número de amostras do arquivo.

Unsigned Int 4 Bytes | 1 Byte | 1 Byte | 1 Byte | 1 Byte
------------ | ------------- | ------------- | ------------- | -------------
Numéro de Amostras | Amostra 1 | Amostra 2 | **...** | Amostra N

O programa deve aplicar a DCT sobre essa entrada, aplicar a IDCT para reconstruir os dados originais, e calcular a diferença entre a entrada original e as amostras reconstruídas. Quatro diferentes arrays de amostras devem ser armazenados separadamente, e plotados na tela em forma de gráficos. Observe que o gráfico da idct pode ter valores grandes, que devem ser escalados.

![Gráfico](/t1/img/grafico.png)

O tamanho da janela pode variar entre 480x360 e 1600x900. O resultado reconstruído deve ser salvo em um arquivo chamado "*output.dct*".

O programa **deve estar estruturado em classes**. Ex: deve ter uma classe parametrizável para desenhar gráficos. Deve ter uma instância para cada tipo de gráfico (input, idct, dct, diff, etc).
