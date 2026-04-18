#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int v[n];
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        int par=0, impar=0;
        for(int i=0; i<n; i++) {
            if(v[i] %2 == 0) par++;
            else impar++;
        }
        if(par > 0 and impar > 0) {
            cout << "YES" << endl;
            continue;
        }
        if(par == 0 and n % 2 != 0)  {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;

    }
    return 0; 
}