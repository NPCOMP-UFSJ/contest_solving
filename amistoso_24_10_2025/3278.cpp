// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, n; cin >> c >> n;
    bool ans = true;

    vector<int> entraram, sairam, ficaram;

    int dentro = 0;
    int max_dentro = c;

    for(int i = 0; i < n; ++i){
        int e, s, f; cin >> s >> e >> f;

        dentro = dentro + e - s;
        max_dentro = max(max_dentro, dentro);
        if(max_dentro > c) ans = false;

        entraram.push_back(e);
        sairam.push_back(s);
        ficaram.push_back(f);
    }

    if(sairam[0] or entraram[entraram.size() - 1]) ans = false;

    dentro = 0;
    for(int i = 0; i < n; ++i){
        dentro = entraram[i] - sairam[i] + dentro; 

        if(ficaram[i] and dentro + 1 <= max_dentro){
            ans = false; 
            break;
        }
    }

    if(dentro) ans = false;

    cout << (ans ? "possible" : "impossible") << endl;
    return 0;
}
