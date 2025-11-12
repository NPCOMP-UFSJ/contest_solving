// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

vector<int> dado(6); 


int main(){
    int n; cin >> n;

    while(n--){
        for(int i = 0; i < 6; ++i) cin >> dado[i];

        vector<int> contador(6, 0);

        bool ans = true;

        for(int i = 0; i < 6; ++i){
            if(dado[i] > 6 or not dado[i] or contador[dado[i]-1]){
                ans = false;
                break;
            }

            contador[dado[i]-1] += 1;
        }

        if(dado[0] + dado[5] != 7) ans = false;
        if(dado[1] + dado[3] != 7) ans = false;
        if(dado[2] + dado[4] != 7) ans = false;

        cout << (ans ? "SIM" : "NAO") << endl;
    }

    

    return 0;
}

