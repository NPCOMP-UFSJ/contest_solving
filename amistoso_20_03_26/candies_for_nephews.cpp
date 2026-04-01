#include <bits/stdc++.h>
#define _ cin.tie(nullptr); \
	ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

int main(void) { _;
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		if(n % 3 == 0) {
			cout << 0 << endl;
			continue;
		}

		cout << (3 - (n%3) % 3) << endl;
	}
}
