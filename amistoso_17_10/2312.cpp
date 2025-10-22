/* Feito por voamorim */
#include <bits/stdc++.h>

#define t tuple<int, int, int, string>

using namespace std;

int main(){
    int n; cin >> n;

    vector<t> v;

    while(n --){
        string s; cin >> s;
        int o, p, b; cin >> o >> p >> b;

        v.push_back(make_tuple(-o, -p, -b, s));
    }

    sort(v.begin(), v.end());

    for(auto &[o, p, b, s] : v){
        cout << s << ' ' << -o  << ' ' << -p << ' ' << -b << endl;
    }

    return 0;
}
