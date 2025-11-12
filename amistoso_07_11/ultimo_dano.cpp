#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int t; cin >> t;
	while(t--) {
		int at, ad, bt, bd, h;
		cin >> at >> ad >> bt >> bd >> h;

		int proxA = 0, proxB = 0;
		string ultimo = "";
		while(h > 0) {
			if(proxA <= proxB) {
				h -= at;
				proxA += ad;
				ultimo = "Andre";
			} else {
				h -= bt;
				proxB += bd;
				ultimo = "Beto";
			}
		}

		cout << ultimo << endl;
	}


	return 0;
}
