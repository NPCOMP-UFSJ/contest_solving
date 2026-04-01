#include <bits/stdc++.h>

#define _ cin.tie(nullptr); \
	cout.tie(nullptr); \
	ios_base::sync_with_stdio(false)

#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define endl "\n"
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main(void) { _;
	int t; cin >> t;
	while(t--) {
		string p, s; cin >> p >> s;
		int i = 0, j = 0;
		bool ans = true;
		while(i < p.size() && j < s.size()) {
			if(p[i] != s[j]) {
				ans = false;
				break;
			}

			char c = p[i];
			int cnt_p = 0;
			while(i < p.size() && p[i] == c) {
				i++;
				cnt_p++;
			}

			int cnt_s = 0;
			while(j < s.size() && s[j] == c) {
				j++;
				cnt_s++;
			}

			if(cnt_s < cnt_p || cnt_s > 2 * cnt_p) {
				ans = false;
				break;

			}
		}

		if(i != p.size() || j != s.size()) ans = false;
		cout << (ans ? "YES" : "NO") << endl;
	}
}
