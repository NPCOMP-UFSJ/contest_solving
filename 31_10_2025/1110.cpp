// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    while(cin >> n && n ){
        list<int> l;

        for(int i = 1; i <= n; ++i) l.push_back(i);

        vector<int> discarded;

        while(l.size() > 1){
            auto x = *l.begin(); 
            l.pop_front();

            discarded.push_back(x);

            auto y = *l.begin();
            l.pop_front();

            l.push_back(y);
        }

        cout << "Discarded cards: ";
        for(int i = 0; i < discarded.size(); i++){
            if( not i) cout << discarded[i];
            else cout << ", " << discarded[i];
        }
        cout << endl;

        cout << "Remaining card: " << *l.begin() << endl;
    }
    return 0;
}

