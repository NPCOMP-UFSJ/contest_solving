// Feito por Vítor Amorim

#include <bits/stdc++.h>

using namespace std;

int main(){
    int m; 

    while(scanf("%d\n", &m) and m){
        string s; 
        getline(cin, s);

        map<char, int> mp;

        int i = 0;
        int distinct = 0;

        int ans = 0;

        for(; i < s.size(); ++i){
            char c = s[i];
                
            if(mp[c] == 0){
                distinct++;
            }

            mp[c] += 1;

            ans = max(ans, i + 1);

            if(distinct == m) break;
        }



        i += 1;

        for(int j = 0; i < s.size(); ++i){
            char c = s[i];

            if(mp[c] == 0){
                distinct += 1;
            }

            mp[c] += 1;

            while(distinct > m){
                mp[s[j]] -= 1;
                
                if(mp[s[j]] == 0){
                    distinct -= 1;
                }
                j ++;
            }


            ans = max(ans, i - j + 1); 
        }
       
        cout << ans << endl;

    }

    return 0;
}
