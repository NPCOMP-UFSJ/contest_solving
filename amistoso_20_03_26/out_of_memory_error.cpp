#include <bits/stdc++.h>
#define _ cin.tie(nullptr); \
ios_base::sync_with_stdio(false)

#define endl '\n'

using namespace std;

int main(void) { _;
	int t; cin >> t;
	while(t--) {
		int n, m;
		long long h;
		cin >> n >> m >> h;

		vector<long long> inicial(n);
		for(int i = 0; i < n; i++) cin >> inicial[i];

		vector<long long> atual = inicial;
		vector<int> versao_elemento(n, 0);
		int versao_global = 0;

		for(int i = 0; i < m; i++) {
			int b;
			long long c;
			cin >> b >> c;

			b--; // Corrige do 1-indexed (problema) para 0-indexed (C++)

			// Se a etiqueta do elemento é velha, significa que um crash aconteceu
			// e ninguém avisou ele ainda. Vamos resetá-lo.
			if(versao_elemento[b] < versao_global) {
				atual[b] = inicial[b];
				versao_elemento[b] = versao_global;
			}

			// Aplica a operação
			atual[b] += c;

			// Checa se o PC da Bessie explodiu
			if(atual[b] > h) {
				versao_global++; // Um simples ++ invalida todo o array instantaneamente em O(1)!
			}
		}

		// Antes de imprimir, precisamos garantir que todos os elementos
		// sobreviventes estejam na versão correta
		for(int i = 0; i < n; i++) {
			if(versao_elemento[i] < versao_global) {
				atual[i] = inicial[i];
			}
			cout << atual[i] << (i == n - 1 ? "" : " ");
		}
		cout << endl;
	}
	return 0;
}
