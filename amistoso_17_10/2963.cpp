/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int c; cin >> c;

    vector<int> v(n-1);

    for(int i = 0; i < n-1; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<>());

    if(c >= v[0]) cout << "S" << endl;
    else cout << "N" << endl;

    return 0;
}
