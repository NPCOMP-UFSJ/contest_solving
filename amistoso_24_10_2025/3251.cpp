// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

bool solve(string file, string pattern){
    int n = pattern.size();
    int m = file.size();

    vector<vector<bool>> dp (n + 1, vector<bool> (m + 1, false));

    dp[0][0] = true;

    for(int i = 1; i <= n; ++i){
        if(pattern[i - 1] == '*'){
            dp[i][0] = dp[i-1][0];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char p = pattern[i-1];
            char f = file[j-1];

            if(p == f){
                dp[i][j] = dp[i-1][j-1];
            } else if (p == '*'){
                dp[i][j] = dp[i-1][j] or dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

int main(){
    string pattern; cin >> pattern;

    int n; cin >> n;

    while(n--){
        string file; cin >> file;
        
        if(solve(file, pattern))
            cout << file << endl;
    }

    return 0;
}
