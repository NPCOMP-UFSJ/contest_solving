/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " == " << x << endl

set<char> alf;
vector<vector<char>> matriz(5, vector<char> (5));

pair<char, char> isSameLine(char a, char b){
    for(int i = 0; i < 5; ++i){
        pair<int, int> ans = {-1, -1};
        for(int j = 0; j < 5; ++j){
            if(matriz[i][j] == a){
                ans.first = j;
            }
            if(matriz[i][j] == b){
                ans.second = j;
            }
        }
        if(ans.first >= 0 and ans.second >= 0) {
            return {matriz[i][(ans.first + 1) % 5], matriz[i][(ans.second + 1) % 5]};
        }
        ans = {-1, -1};
    }
    return {EOF, EOF};
}

pair<char, char> isSameCol(char a, char b){
    for(int j = 0; j < 5; ++j){
        pair<int, int> ans = {-1, -1};
        for(int i = 0; i < 5; ++i){
            if(matriz[i][j] == a){
                ans.first = i;
            }
            if(matriz[i][j] == b){
                ans.second = i;
            }
        }
        if(ans.first >= 0 and ans.second >= 0) {
            return {matriz[(ans.first + 1) % 5][j], matriz[(ans.second + 1) % 5][j]};
        }
        ans = {-1, -1};
    }
    return {EOF, EOF};
}

pair<int, int> findPos(char c){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(matriz[i][j] == c){
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int main(){
    for(int i = (int) 'a'; i <= (int) 'z'; ++i){
        if(i == 'q') continue;
        alf.insert((char) i);
    }

    string key;
    getline(cin, key);

    int i = 0, j = 0;

    set<char> done;

    for(auto &c : key){
        if(c < 'a' or c > 'z') continue;

        c = tolower(c);

        if(done.find(c) != done.end()){
            continue;
        }

        matriz[j][i] = c;
        done.insert(c);

        i++;
        if(i == 5) {
            j++;
            i = 0;
        }

        alf.erase(c);
    }

    char c = 'a';
    while(j < 5){
        while(alf.find(c) == alf.end() and c <= 'z'){
            c += 1;
        }
        if(c > 'z') return 0;
        matriz[j][i] = c;

        i++;


        alf.erase(c);
        c++;
        if(i == 5) {
            j++;
            i = 0;
        }
    }


    string text;
    getline(cin, text);

    vector<pair<char, char>> pares;

    for(int i = 0; i < text.size(); i += 2){
        pair<char, char> np;

        text[i] = tolower(text[i]);
        while(text[i] == ' '){
            i ++;
            text[i] = tolower(text[i]);
        }

        if(i + 1 == text.size()){
            np = {text[i], 'x'};
            pares.push_back(np);
            continue;
        } else {
            int j = i;
            text[i+1] = tolower(text[i+1]);
            while(text[i+1] == ' '){
                i ++;
                text[i+1] = tolower(text[i+1]);
            }

            if(text[i+1] == text[j]){
                np = {text[j], 'x'};
                pares.push_back(np);
                i -= 1;
                continue;
            }

            np = {text[j], text[i + 1]};
        }
        pares.push_back(np);
    }

    string output;

    for(auto &[a, b] : pares){
        auto [c, d] = isSameLine(a, b);

        if(c != EOF and d != EOF){
            output.push_back(c);
            output.push_back(d);
            continue;
        }

        auto [e,f] = isSameCol(a, b);

        if(e != EOF and f != EOF){
            output.push_back(e);
            output.push_back(f);
            continue;
        }

        auto [i, j] = findPos(a);
        auto [k, l] = findPos(b);

        output.push_back(matriz[i][l]);
        output.push_back(matriz[k][j]);
    }

    for(char &c : output){
        cout << (char)toupper(c);
    }
    cout << endl;

    return 0;
}
