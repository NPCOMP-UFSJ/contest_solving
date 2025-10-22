/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    
    vector<int> musicas(n);
    for(auto &m : musicas) cin >> m;

    vector<int> c(3, 0);
    for(int i = 0; i < k; ++i) cin >> c[i];

    vector<vector<vector<vector<int>>>> dp (101,
                                            vector<vector<vector<int>>> (51,
                                            vector<vector<int>> (51,
                                            vector<int> (51, 0))));

    for(int i = 1; i <= n; ++i){
        int m = musicas[i-1];

        for(int c1 = 0; c1 <= c[0]; ++c1){
            for(int c2 = 0; c2 <= c[1]; ++c2){
                for(int c3 = 0; c3 <= c[2]; ++c3){
                    dp[i][c1][c2][c3] = dp[i-1][c1][c2][c3];

                    if(c1 - m >= 0){
                        dp[i][c1][c2][c3] = max(dp[i][c1][c2][c3],
                                                dp[i-1][c1-m][c2][c3] + m);
                    }

                    if(c2 - m >= 0){
                        dp[i][c1][c2][c3] = max(dp[i][c1][c2][c3],
                                                dp[i-1][c1][c2-m][c3] + m);
                    }

                    if(c3 - m >= 0){
                        dp[i][c1][c2][c3] = max(dp[i][c1][c2][c3],
                                                dp[i-1][c1][c2][c3-m] + m);
                    }
                }
            }
        }
    }

    cout << dp[n][c[0]][c[1]][c[2]] << endl;

    return 0;
}

