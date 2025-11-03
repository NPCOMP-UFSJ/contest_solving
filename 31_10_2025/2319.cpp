// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001

vector<vector<int>> g (MAXN, vector<int> (MAXN));

int contaFatores(long long val, int fator){
    int contador = 0;

    while(not (val % fator)){
        contador += 1;
        val /= fator;
    }

    return contador;
}

int main(){
    int n; cin >> n;

    for(int a = 0; a < n; ++a){
        for(int b = 0; b < n; ++b){
            cin >> g[a][b];
        }
    }

    vector<vector<vector<int>>> dp
                (MAXN, vector<vector<int>> (MAXN, vector<int> (2, INT_MAX)));

    dp[0][0][0] = contaFatores(g[0][0], 2);
    dp[0][0][1] = contaFatores(g[0][0], 5);

    for(int i = 1; i < n; ++i){
        if(not g[0][i])
            continue;

        if(dp[0][i-1][0] == INT_MAX or dp[0][i-1][1] == INT_MAX)
            continue;

        dp[0][i][0] = dp[0][i-1][0] + contaFatores(g[0][i], 2);
        dp[0][i][1] = dp[0][i-1][1] + contaFatores(g[0][i], 5);
    }

    for(int i = 1; i < n; ++i){
        if(not g[i][0])
            continue;

        if(dp[i-1][0][0] == INT_MAX or dp[i-1][0][1] == INT_MAX)
            continue;

        dp[i][0][0] = dp[i-1][0][0] + contaFatores(g[i][0], 2);
        dp[i][0][1] = dp[i-1][0][1] + contaFatores(g[i][0], 5);
    }

    for(int i = 1; i < n; ++i){
        for(int j = 1; j < n; ++j){
            if(g[i][j] == 0)
                continue;

            if(dp[i-1][j][0] == INT_MAX and dp[i][j-1][0] == INT_MAX){
                continue;
            }

            if(dp[i-1][j][0] == INT_MAX){
                dp[i][j][0] = dp[i][j-1][0] + contaFatores(g[i][j], 2);
                dp[i][j][1] = dp[i][j-1][1] + contaFatores(g[i][j], 5);
                continue;
            } else if (dp[i][j-1][0] == INT_MAX){
                dp[i][j][0] = dp[i-1][j][0] + contaFatores(g[i][j], 2);
                dp[i][j][1] = dp[i-1][j][1] + contaFatores(g[i][j], 5);
                continue;
            }

            dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) + contaFatores(g[i][j], 2);
            dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][1]) + contaFatores(g[i][j], 5);
        }
    }
    cout << min(dp[n-1][n-1][1], dp[n-1][n-1][0]) << endl;

    return 0;
}
