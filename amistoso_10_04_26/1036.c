#include <stdio.h>
#include <math.h>
 
int main() {
    double A, B, C, R1,R2, delta;
    scanf("%lf%lf%lf",&A,&B,&C);
    
    delta = B * B - 4 *A * C;
    
    if (A == 0){
        printf("Impossivel calcular\n");
    } else{
        if (delta > 0){
            R1 = (-B + sqrt(delta))/(2*A);
            R2 = (-B - sqrt(delta))/(2*A);
            printf("R1 = %.5lf\n", R1);
            printf("R2 = %.5lf\n", R2);
        } else {
            printf("Impossivel calcular\n");
        }
    }
    return 0;
}

