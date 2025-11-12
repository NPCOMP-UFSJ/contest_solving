/*
 * Pode ser utilizado com o algoritmo de booth. Executa em O(n) por caso teste
 * A ideia do algoritmo é a seguinte (resumidamente):
 *
 *  - Concatena a string com ela mesma: s + s (facilita as operações sem precisar verificar limite de index)
 *  - Percorre com dois indices i e j e um contador k para comparar os caracteres
 *  - Ao encontrar uma diferença, avança o indice menor de acordo com o resultado da compraração
 *  - No final, i será o indice de inicio da menor rotacao
 *
 *  Pode ser utilizado tanto para a menor quanto para a maior rotação,
 *  alterando-se apenas o criterio de comparação
 */
#include <bits/stdc++.h>

using namespace std;

int booth_min(const string &s) {
	string ss = s + s;
	int n = s.size();
	int i = 0, j = 1, k = 0;

	while(i < n && j < n && k < n) {
		if(ss[i+k] == ss[j+k]) k++;
		else {
			// descartamos o indice de inicio com o caractere maior (nao pode ser o menor lexicograficamente)
			if(ss[i+k] > ss[j+k])
				i = i + k + 1;
			else j = j + k + 1;

			if(i == j) j++;
			k = 0; // reinicia a comparacao
		}
	}

	return min(i, j);
}

int booth_max(const string &s) {
	string ss = s + s;
	int n = s.size();
	int i = 0, j = 1, k = 0;

	while(i < n && j < n && k < n) {
		if(ss[i+k] == ss[j+k]) k++;
		else {
			if(ss[i+k] < ss[j+k])
				i = i + k + 1;
			else j = j + k + 1;

			if(i == j) j++;
			k = 0;
		}
	}

	return min(i, j);
}

int main(void) {
	string s;
	int caso = 1;
	while(cin >> s, s != "*") {
		int min_idx = booth_min(s);
		int max_idx = booth_max(s);

		string ss = s + s;

		string menor = ss.substr(min_idx, s.size());
		string maior = ss.substr(max_idx, s.size());

		cout << "Caso " << caso++ << ": " << menor << " " << maior << endl;
	}
}
