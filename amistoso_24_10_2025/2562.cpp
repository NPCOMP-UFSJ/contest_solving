// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl

void solve(int n, int m){
    vector<vector<int>> g(n);
    int a, b;

    for(int i = 0; i < m; ++i){
        cin >> a >> b; 
        a -= 1, b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int e;  
    cin >> e;
    e -= 1;

    vector<bool> vis(n, false);

    int ans = 0;

    queue<int> q;
    q.push(e);
    while(!q.empty()){
        auto x = q.front(); q.pop();

        if(vis[x]) continue;
        vis[x] = true;
        ans += 1;

        for(auto & v : g[x]){
            q.push(v);
        }
    }

    cout << ans << endl;
}

int main(){
    int n, m; 

    while(cin >> n >> m){
        solve(n, m);
    }
    return 0;
}
