/*Feito por Murilo*/
#include <bits/stdc++.h>

#define tiii tuple<int, int, int>
#define _ cin.tie(nullptr); ios_base::sync_with_stdio(false);

using namespace std;

int main() {_

	int t; cin >> t;

	while(t--){
		int b; cin >> b;
		array<int, 3> pokemonA, pokemonB;

		for(auto &i : pokemonA) cin >> i;
		for(auto &i : pokemonB) cin >> i;

		double ataqueA = (pokemonA[0] + pokemonA[1])/2 + (pokemonA[2] % 2 == 0 ?b : 0);
		double ataqueB = (pokemonB[0] + pokemonB[1])/2 + (pokemonB[2] % 2 == 0 ?b : 0);

		cout << (ataqueA > ataqueB ? "Dabriel" :
				ataqueB > ataqueA ? "Guarte" : "Empate") << endl;
	}

	return 0;
}
