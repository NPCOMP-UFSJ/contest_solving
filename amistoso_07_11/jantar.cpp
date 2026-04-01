#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;

	vector<vector<int>> year(n, vector<int>(n, 2008));
	set<int> years;

	for(int i = 0; i < c; i++) {
		int a, b, y;
		cin >> a >> b >> y;
		a--; b--;
		year[a][b] = year[b][a] = y;
		years.insert(y);
	}
	years.insert(2008);

	vector<int> sortedYears;
	for(int y : sortedYears)
		 sortedYears.push_back(y+1);
	sort(sortedYears.begin(), sortedYears.end());

	bool possible = false;
	int ans = -1;

	for(const int &y : sortedYears) {
		vector<vector<int>> adj(n);
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n;	j++) {
				if(year[i][j] < y) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		vector<bool> vis(n, 0);
		vector<int> comps;

		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				int sz = 0;
				queue<int> q;
				q.push(i);
				vis[i] = 1;
				while(!q.empty()) {
					int u = q.front(); q.pop();
					sz++;
					for(int v : adj[u]) {
						if(!vis[v]) {
							vis[v] = 1;
							q.push(v);
						}
					}
				}
				comps.push_back(sz);
			}
		}

		// subset sum usando bitset
		bitset<405> dp;
		dp[0] = 1;
		for(int sz : comps) dp |= (dp << sz);

		int low = (n+2)/3;
		int high = (2*n)/3;

		bool ok = false;
		for(int s = low; s <= high; s++) {
			if(dp[s]) { ok = true; break; }
		}

		if(ok) {
			possible = true;
			ans = y;
			break;
		}
	}

	if(possible) cout << ans << endl;
	else cout << "Impossible" << endl;

	return 0;
}
