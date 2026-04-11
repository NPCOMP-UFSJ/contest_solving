#include <stdio.h>

int main(){
    int N, C, M;
    scanf("%d %d %d", &N, &C, &M);
    int carimbadas[C], compradas[M];
    int ca = C;
    for(int i = 0; i < C; i++){
        scanf("%d", &carimbadas[i]);
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &compradas[i]);
    }
    for(int i = 0; i < C; i++){
        for(int j = 0; j < M; j++){
            if(carimbadas[i] == compradas[j]){
                carimbadas[i] = -1;
                ca--;
            }
        }
    }
    if(ca < 0) ca= 0;
    printf("%d\n", ca);
    return 0;
}

