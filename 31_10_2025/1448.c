// Feito por Vítor Amorim

#include <stdio.h>
#include <string.h>

int main(){
    int casos;
    scanf("%d\n", &casos);
    char frase_original[102], frase_time1[102], frase_time2[102];
    int tam_frase = 0;

    int acertos_time1 = 0, acertos_time2 = 0;
    int instancia = 1;

    int um_acertou_outro_nao = 0;

    int vencedor = 0;

    for(int caso = 0; caso < casos; caso++){
        acertos_time1 = 0; 
        acertos_time2 = 0;
        um_acertou_outro_nao = 0; 
        vencedor = 0;
        
        frase_original[0] = '\0';
        frase_time1[0] = '\0';
        frase_time2[0] = '\0';

        fgets(frase_original, 102, stdin);
        fgets(frase_time1, 102, stdin);
        fgets(frase_time2, 102, stdin);
        tam_frase = strlen(frase_original);

        for(int i = 0; i < tam_frase; i++){
            if(frase_original[i] == frase_time1[i]){
                acertos_time1 += 1;
            }
            if(frase_original[i] == frase_time2[i]){
                acertos_time2 += 1;
            }
            if((frase_original[i] == frase_time1[i] && frase_original[i] != frase_time2[i]) && um_acertou_outro_nao == 0){
                um_acertou_outro_nao = 1;
            } 
            if((frase_original[i] != frase_time1[i] && frase_original[i] == frase_time2[i]) && um_acertou_outro_nao == 0){
                um_acertou_outro_nao = 2;
            }
        }

        if(acertos_time1 == acertos_time2){
            if(um_acertou_outro_nao == 1){
                vencedor = 1;
            } else if (um_acertou_outro_nao == 2) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
        } else if (acertos_time1 > acertos_time2){
            vencedor = 1;
        } else {
            vencedor = 2;
        }

        printf("Instancia %d\n", instancia);
        if (vencedor == 0){
            printf("empate\n");
        } else {
            printf("time %d\n", vencedor);
        }

        printf("\n");
        
        instancia += 1;
    }
    return 0;
}
