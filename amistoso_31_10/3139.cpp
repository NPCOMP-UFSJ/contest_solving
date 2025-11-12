// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<int> inscritos;

    long long soma = 0;
    for(int i = 0; i < 30; ++i){
        int x; cin >> x;
        inscritos.push_back(x);
        soma += x;
    }

    int i = 0;
    do {
        double media = ceil(soma / 30.0);
        n += media;

        inscritos.push_back(media);
        soma += media;
        soma -= inscritos[i++];
    } while (n < m);

    cout << i << endl;

    return 0;
}
