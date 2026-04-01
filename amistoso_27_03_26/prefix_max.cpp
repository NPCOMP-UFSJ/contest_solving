#include <bits/stdc++.h>

#define _ cin.tie(nullptr); \
	cout.tie(nullptr); \
	ios_base::sync_with_stdio(false);

#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define endl "\n"
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main(void) { _
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> vec(n);
		for(auto &x : vec) cin >> x;
		int idx = 0, val_idx = INT_MIN;
		for(int i = 0; i < n; i++) {
			if(vec[i] >= val_idx) {
				val_idx = vec[i];
				idx = i;
			}
		}

		int temp = vec[idx];
		vec[idx] = vec[0];
		vec[0] = temp;

		int sum = 0, mx = 0;
		for(int i = 0; i < n; i++) {
			mx = max(mx, vec[i]);
			sum += mx;
		}

		cout << sum << endl;
	}
}

