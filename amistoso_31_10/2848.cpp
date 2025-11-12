// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q; cin >> n >> q;

    vector<int> v(n);
    for(auto &x: v) cin >> x;

    while(q--){
        int l, r, k, g, d; cin >> l >> r >> k >> g >> d;
        l--;

        vector<int> range;
        map<int, int> qnt;
        for(int i = l; i < r; ++i){
            range.push_back(v[i]);
            qnt[v[i]] += 1;
        }
        sort(range.begin(), range.end());

        int min_val = range[--k];
        int appearances = qnt[min_val];

        int dist_g = abs(g - appearances);
        int dist_d = abs(d - appearances);

        cout << min_val << ' ' << appearances << ' ';

        if(dist_g == dist_d){
            cout << 'E' << endl;
        } else if (dist_g > dist_d){
            cout << 'D' << endl;
        } else {
            cout << 'G' << endl;
        }
    }

    return 0;
}
