/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl

void verifica(string s, int &ans){
    string a = "<body>";
    int k = 0;
    string b = "</body>";

    for(int i = 0; i < s.size(); ++i){
        if(ans == 0){
            if(s[i] == a[k]) k++;
            else k = 0;

            if(k == a.size()) ans = 1;
        } else if (ans == 1) {
            if(s[i] == b[k]) k++;
            else k = 0;

            if(k == b.size()) ans = 2;
        }
    }

}

int main(){
    string b;

    string r;

    bool f = true;
    int ans = 0;
    while(getline(cin, b)){
        verifica(b, ans);

        if(ans == 2) break;

        if(ans == 1 and not f){
            cout << b << endl;
        } else if(ans == 1) {
            f = false;
        }
    }

    return 0;
}
