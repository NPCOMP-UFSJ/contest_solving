#include <stdio.h>
 
int main() {
    int km;
    double litros, kml;
    scanf("%d %lf", &km, &litros);
    kml = km/litros;
    printf("%.3lf km/l\n", kml);
    return 0;
}

