/*Feito por Murilo*/
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main(void) {
	int p, j1, j2, r, a;
	cin >> p >> j1 >> j2 >> r >> a;

	if (r == 1 && a == 1) {
		// Jogador 1 roubou e foi acusado
		cout << "Jogador 2 ganha!" << endl;
	} else if (r == 1 && a == 0) {
		// Jogador 1 roubou, mas não foi acusado
		cout << "Jogador 1 ganha!" << endl;
	} else if (r == 0 && a == 1) {
		// Jogador 1 não roubou, mas foi acusado
		cout << "Jogador 1 ganha!" << endl;
	} else {
		// Jogo segue normalmente (sem roubo e sem acusação)
		int soma = j1 + j2;
		bool somaPar = (soma % 2 == 0);

		if ((somaPar && p == 1) || (!somaPar && p == 0)) {
			cout << "Jogador 1 ganha!" << endl;
		} else {
			cout << "Jogador 2 ganha!" << endl;
		}
	}

	return 0;
}
