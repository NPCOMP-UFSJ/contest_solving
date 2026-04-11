#include <stdio.h>

int main(){
    int N, menor_valor, posicao;
    scanf("%d", &N);
    int X[N];
    scanf("%d", &X[0]);
    menor_valor = X[0];
    posicao = 0;
    for (int i = 1; i < N; i++){
        scanf("%d", &X[i]);
        if (X[i] < menor_valor){
            menor_valor = X[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor_valor, posicao);
    return 0;
}

