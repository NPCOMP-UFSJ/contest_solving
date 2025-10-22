/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int main(){
    int n, m; cin >> n >> m;
    vector<pii> v(n, {0, 0});

    for(int i = 0; i < n; ++i){
        v[i].second = i;
        for(int j = 0; j < m; ++j){
            int x;
            cin >> x; v[i].first += x;
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < 3 ; ++i) cout << v[i].second  + 1<< endl;

    return 0;
}
