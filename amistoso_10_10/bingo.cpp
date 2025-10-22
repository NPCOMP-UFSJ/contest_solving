/*Feito por Murilo*/
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, b;
	while(cin >> n >> b && n > 0 && b > 0) {
		// bolas que ficaram no globo
		vector<int> globo(b);

		for(auto &i : globo) cin >> i;

		sort(globo.begin(), globo.end());

		// n valores, incluso zero
		vector<bool> shownup(n+1, false);
		// verificar se eh possivel sortear todas as bolas de 0 a N com o que restou
		// faremos brute-force ja que b <= 91 no maximo
		for(int i = 0; i < b; i++) {
			for(int j = 0; j <= i; j++) {
				int diff = abs(globo[i] - globo[j]);
				if(diff <= n) shownup[diff] = true;
			}
		}

		if(all_of(shownup.begin(), shownup.end(), [](bool x) { return x; })) cout << "Y" << endl;
		else cout << "N" << endl;
	}
}
