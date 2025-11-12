// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl

struct Pacote {
    int tempo, id;
};

int main(){
    int n;
    while(cin >> n){
        vector<Pacote> pacotes(n);

        for(int i = 0; i < n; ++i){
            cin >> pacotes[i].id; 
        }

        for(int i = 0; i < n; ++i){
            cin >> pacotes[i].tempo; 
        }

        long long ans = 0;

        for(int i = 0; i < n - 1; ++i){
            for(int j = 0; j < n - i - 1; ++j){
                if(pacotes[j].id > pacotes[j+1].id){
                    ans += pacotes[j].tempo + pacotes[j + 1].tempo;
                    swap(pacotes[j], pacotes[j+1]);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
