// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> blocos (n); 
        for(auto & b : blocos){
            cin >> b;
        }
      
        vector<int> dp(m + 1, INT_MAX); 
        dp[0] = 0;
        for(int i = 0; i <= m; ++i){
            for(auto & b : blocos){
                if(i - b >= 0){
                    if(dp[i - b] == INT_MAX) continue;
                    dp[i] = min(dp[i], dp[i - b] + 1);
                }
            }
        }
        cout << dp[m] << endl;
    }

    return 0;
}
