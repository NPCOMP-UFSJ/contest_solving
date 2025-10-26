// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    string palavra;
    string line;
    while(cin >> palavra){
         
        if(palavra == "<br>"){
            cout << line << endl;
            line.clear();
            continue;
        }

        if(palavra == "<hr>"){
            if(line.size() != 0){
                cout << line << endl;
                line.clear();
            }
            for(int i = 0; i < 80; ++i) cout << '-';
            cout << endl;
            continue;
        }

        if(line.size() + palavra.size() + 1 > 80){
            cout << line << endl;
            line = palavra;
        } else {
            if(line.size() == 0){ 
                line = line + palavra;
            } else {
                line = line + " " + palavra;
            }
        }
    }
    cout << line << endl;
    
    return 0;
}
