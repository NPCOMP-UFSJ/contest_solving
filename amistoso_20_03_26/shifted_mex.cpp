#include <bits/stdc++.h>
#define _ cin.tie(nullptr); \
	ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

int main(void) { _;
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> vec(n);
		for(int &x : vec) cin >> x;
		sort(vec.begin(), vec.end());

		/* a ideia da solucao eh ordenar a sequencia de numeros
		 * e encontrar a maior sequencia de numeros consecutivos.
		 * o tamanho dessa sequencia basicamente eh o MEX, pois, tendo
		 * essa sequencia, podemos "shiftar" ela ate que o menor elemento da mesma
		 * seja o 0. sendo assim, encontramos o maior MEX possivel */

		// removemos duplicatas
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		int ans = 1, current_streak = 1;

		for(int i = 1; i < vec.size(); i++) {
			if(vec[i] == vec[i-1] + 1) current_streak++;
			else {
				ans = max(ans, current_streak);
				current_streak = 1;
			}
		}

		ans = max(ans, current_streak);
		cout << ans << endl;
	}
}
