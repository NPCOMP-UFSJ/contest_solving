// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std; 

int d, e, f;

void compra(char j, int val){
    switch(j){
        case 'D': {
            d -= val;  
            break;
        }
        case 'E': {
            e -= val;
            break;
        }
        case 'F': {
            f -= val;
            break;
        }
    }
}

void venda(char j, int val){
    compra(j, -val);
}

void aluguel(char j1, char j2, int val){ 
    venda(j1, val);
    compra(j2, val);
}

int main(){
    int i, n; cin >> i >> n;

    d = e = f = i;

    while(n--){
        char op; cin >> op;        

        switch(op){
            case 'C': {
                char j; cin >> j;
                int val; cin >> val;
                compra(j, val);                
                break;
            }
            
            case 'V': {
                char j; cin >> j;
                int val; cin >> val;
                venda(j, val);
                break;
            }
            
            case 'A': {
                char j1, j2; cin >> j1 >> j2;
                int val; cin >> val;
                aluguel(j1, j2, val);
                break;
            }
        }
    }

    cout << d << ' ' << e << ' ' << f << endl;
    return 0;
}
