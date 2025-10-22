/*Feito por Murilo*/
#include <bits/stdc++.h>

#define _ cin.tie(nullptr); \
					ios_base::sync_with_stdio(false);

using namespace std;

/* Solução em O(n) por teste

 * A ideia central é enxergar a permutação como um conjunto de ciclos.
 *
 * - Mas o que é um ciclo numa permutação?
 * Para isso, imaginamos que cada posição da sequência aponta para onde seu elemento "deveria" estar.
 * Por exemplo, se o elemento na posição i deveria estar na posição permutacao[i],
 * podemos seguir esse "encadeamento" até voltar ao ponto de partida.
 *
 * Esse caminho fechado é chamado de ciclo.
 * Exemplo: se posição 0 aponta para posição 3, posição 3 aponta para posição 1,
 * e posição 1 aponta para posição 0, então (0 -> 3 -> 1 -> 0) é um ciclo de tamanho 3.
 *
 * Para ordenar os elementos desse ciclo, é necessário realizar (tamanho_do_ciclo - 1) trocas.
 * Como a permutação é composta por vários ciclos disjuntos,
 * o total mínimo de trocas para ordenar a permutação é a soma das trocas necessárias em cada ciclo,
 * ou seja:
 *
 * (tamanho_ciclo_1 - 1) + (tamanho_ciclo_2 - 1) + ... + (tamanho_ciclo_k - 1)
 *
 * Somando tudo, isso dá:
 *
 * (tamanho_ciclo_1 + tamanho_ciclo_2 + ... + tamanho_ciclo_k) - número_de_ciclos
 *
 * Como a soma dos tamanhos de todos os ciclos é exatamente N (todos os elementos),
 * o resultado final é:
 *
 * N - número_de_ciclos
 *
 * Portanto, a solução é identificar quantos ciclos existem na permutação e calcular N - ciclos.
 *
 * O algoritmo marca os elementos visitados ao percorrer cada ciclo para não contar nenhum ciclo duas vezes.
 * Como cada elemento é visitado uma única vez, a complexidade é O(N).
 */

int main(void) { _
	int t; cin >> t;  // número de casos de teste
	while(t--) {
		int n; cin >> n;
		vector<int> permutacao(n);
		vector<bool> vis(n, false);  // vetor para marcar elementos visitados

		for(int i = 0; i < n; i++) {
			cin >> permutacao[i];
			permutacao[i]--;  // ajusta índices para zero-based
		}

		int ans = 0;  // contador de ciclos

		// Percorre todos os elementos para identificar ciclos
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {  // se não visitado
				int current = i;

				// percorre o ciclo até voltar ao início
				while(!vis[current]) {
					vis[current] = true;         // marca visitado
					current = permutacao[current]; // vai para próximo índice no ciclo
				}
				ans++;  // conta um ciclo encontrado
			}
		}

		cout << (n - ans) << endl;  // número mínimo de trocas = n - número de ciclos
	}
}
