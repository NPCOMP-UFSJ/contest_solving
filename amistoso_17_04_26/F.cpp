#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n; cin >> n;
    char last = s[0];
    vector<int> v(s.size(), 0);
    v[0] = 0;
    for(int i=1; i<s.size(); i++) {
        if(s[i] == last) {
            v[i] = v[i-1] + 1;
        } else {
            v[i] = v[i-1];
            last = s[i];
        }
    }
    for(int i=0 ; i<n;i ++) {
        int l,r; cin >> l >> r;
        l--,r--;
        cout << v[r] - v[l] << endl;
    }

    return 0;
}