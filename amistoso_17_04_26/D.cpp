#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int ans = 1, atual = 1;
    int last = v[0];
    for(int i=1; i<n; i++) {
        if(v[i] > last) {
            atual++;
        } else {
            ans =  max(ans, atual);    
            atual = 1;
        }
        last = v[i];
    }
    ans =  max(ans, atual);    
    cout << ans << endl;
    return 0;
}