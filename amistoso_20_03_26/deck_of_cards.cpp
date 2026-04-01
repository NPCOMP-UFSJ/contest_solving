#include <bits/stdc++.h>
#define _ cin.tie(nullptr); \
	ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

int main(void) { _;
	int t; cin >> t;
	while(t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;

		/* independente da ordem, precisamos saber quantas cartas sao retiradas
		* do topo, quantas do fundo, e quantas serao opcionalmente retiradas */
		int cnt0 = count(s.begin(), s.end(), '0');
		int cnt1 = count(s.begin(), s.end(), '1');
		int cnt2 = count(s.begin(), s.end(), '2');

		// consideramos todas as cartas como presentes inicialmente
		string ans(n, '+');

		// numero de remocoes for igual ao numero de cartas, tudo eh removido
		if(n == k)
			ans = string(n, '-');
		else
			for(int i = 0; i < n; i++)
				// esta no range das remocoes definitivas (topo ou fundo)
				if(i < cnt0 || i >= n - cnt1)
					ans[i] = '-';
				// range de remocoes opcionais
				else if(i < cnt0 + cnt2 || i >= n - cnt1 - cnt2)
					ans[i] = '?';

		cout << ans << endl;
	}
}
