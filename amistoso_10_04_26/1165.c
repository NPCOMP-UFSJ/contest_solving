#include <stdio.h>

int main(){
    int numero_de_casos = 0;
    int numero = 0;
    int num_div = 0;
    scanf("%d", &numero_de_casos);
    for(int i = 1; i <= numero_de_casos; i++){
        scanf("%d", &numero);
        for(int j = 2; j < numero && num_div == 0; j++){
            if(numero % j == 0){
                num_div += 1;
                printf("%d nao eh primo\n", numero);
            }
        }
        if(num_div == 0 || numero == 2 || numero == 1){
            printf("%d eh primo\n", numero);
        }
        num_div = 0;
    }
    return 0;
}

