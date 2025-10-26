// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; 

    while(cin >> n >> k and n and k){
        vector<tuple<int, int>> operations(n);
        priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<tuple<int, int, int, bool>>> pq;

        for(int i = 0; i < n; ++i){
            int e, s;
            cin >> e >> s;
            operations[i] = make_tuple(e, s);

            pq.push(make_tuple(e, i, 0, true));
            pq.push(make_tuple(s, i, -e, false));
        }

        bool ans = true;

        stack<int> st;
        while(not pq.empty()){
            auto [t, i, e, op] = pq.top(); pq.pop();

            if(op){
                st.push(i);

                if(st.size() > k){
                    ans = false;
                    break;
                }
            } else {
                if(st.size() == 0 or st.top() != i){
                    ans = false;
                    break;
                }

                st.pop();
            }
        }

        cout << (ans ? "Sim" : "Nao") << endl;
    }
    return 0;
}
