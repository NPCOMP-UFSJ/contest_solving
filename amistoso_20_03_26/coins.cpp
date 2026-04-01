#include <bits/stdc++.h>
#define _ cin.tie(nullptr); \
	ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

int main(void) { _;
	int t; cin >> t;
	while(t--) {
		long long n, k; cin >> n >> k;
		if(n % 2 == 0 || k % 2 == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
