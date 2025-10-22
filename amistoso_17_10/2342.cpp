/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int x, k; char c; cin >> x >> c >> k;

    if(c == '*') {
        cout << (x * k > n ? "OVERFLOW" : "OK") << endl;
    } else {
        cout << (x + k > n ? "OVERFLOW" : "OK") << endl;
    }

    return 0;
}
