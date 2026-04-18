#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int main() {
    int n,k; cin >> n >> k;
    vector<int> v(n+1, 0);
    for(int i=1; i<=n;i++) {
        int a;
        cin >> a;
        v[i] = a + v[i-1]; 
    }
    int ans = INF;
    int idx = 0;
    for(int i=1; i+k-1<=n;i++) {
        if(ans >= v[i+k-1] - v[i-1]) {
            ans = v[i+k-1] - v[i-1];
            idx = i;
        }
    }
    cout << idx << endl;
    return 0;
}