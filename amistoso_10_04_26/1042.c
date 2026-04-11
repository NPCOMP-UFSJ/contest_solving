#include <stdio.h>
 
int main() {
    int A,B,C;
    scanf("%d %d %d", &A,&B,&C);
    
    if (A <= B && A <= C){
        printf("%d\n", A);
        if (B <= C) {
            printf("%d\n", B);
            printf("%d\n", C);
        } else {
            printf("%d\n", C);
            printf("%d\n", B);
        }
        
    } else if (B <= A && B <= C) {
        printf("%d\n", B);
        if (A <= C){
            printf("%d\n", A);
            printf("%d\n", C);
        } else {
            printf("%d\n", C);
            printf("%d\n", A);
        }
        
    } else if (C <= A && C <= B){
        printf("%d\n", C);
        if (A <= B){
            printf("%d\n", A);
            printf("%d\n", B);
        } else {
            printf("%d\n", B);
            printf("%d\n", A);
        }
    }
    
    printf ("\n%d\n%d\n%d\n", A,B,C);
    
    return 0;
}

