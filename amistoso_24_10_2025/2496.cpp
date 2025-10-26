// Feito por Vítor Amorim

#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        int m;
        cin >> m;
        string s; cin >> s;

        vector<int> seq(m);
        iota(seq.begin(), seq.end(), 0);

        int trocas = 0; 
        for(int i =0; i < m; ++i){
            trocas += not (s[i] == seq[i] + 'A');
        }
        cout << (trocas == 2 ? "There are the chance." : "There aren't the chance.") << endl;
    }

    return 0;
}
