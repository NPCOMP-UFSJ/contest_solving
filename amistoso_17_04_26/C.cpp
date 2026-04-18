#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define ll long long

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n],b[n];
        int min_a = INF,min_b = INF;
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp;
            a[i] = tmp;
            if(min_a > tmp) min_a = tmp;
        }
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp;
            b[i] = tmp;
            if(min_b > tmp) min_b = tmp;
        }
        ll ans=0;
        for(int i=0; i<n; i++) {
            if(a[i] > min_a and b[i] > min_b) {
                int absolut = min(a[i]-min_a,b[i]-min_b);
                ans += absolut;
                a[i] -= absolut;
                b[i] -= absolut;
            }
            if(a[i] > min_a) ans += a[i] - min_a;
            if(b[i] > min_b) ans += b[i] - min_b;
        }
        cout << ans << endl;
    }
    return 0;   
}