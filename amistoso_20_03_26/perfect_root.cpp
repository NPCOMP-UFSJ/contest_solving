#include <bits/stdc++.h>
#define _ cin.tie(nullptr); \
	ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;
int main(void) { _;
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		for(int i = 1; i <= n; i++) {
			if(i == 1) cout << i;
			else cout << " " << i;
		}

		cout << endl;
	}
}
