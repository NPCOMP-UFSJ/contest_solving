// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    map<int, int> mp;

    int ans = 0;
    int qnt = 0;

    for(int i = 0; i < n; ++i){
        int x; cin >> x;

        mp[x] += 1;

        if(mp[x] > qnt){
            ans = x;
            qnt = mp[x];
        } else if (mp[x] == qnt and x > ans){
            ans = x; 
        }
    }

    cout << ans << endl;
    return 0;
}
