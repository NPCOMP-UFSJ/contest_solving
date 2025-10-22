/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[40];
ll r[40];

void solve(int x){
    if(dp[x] or x == 0){
        return;
    }

    solve(x - 1);
    solve(x - 2);

    dp[x] += dp[x - 1] + dp[x - 2];
    r[x] += r[x - 1] + r[x - 2] + 2;
}

int main(){
    dp[0] = 0;
    dp[1] = 1;

    int n;
    cin >> n;

    solve(39);

    while(n--){
        int x; cin >> x;

        cout << "fib(" << x << ") = " << r[x] << " calls = " << dp[x] << endl;
    }

    return 0;
}
