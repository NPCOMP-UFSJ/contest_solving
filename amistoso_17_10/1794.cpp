/* Feito por voamorim */
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int la, lb, sa, sb;
    cin >> la >> lb >> sa >> sb;

    if(n < la or n > lb or n < sa or n > sb){
        cout << "impossivel" << endl;
    } else cout << "possivel" << endl;

    return 0;
}
