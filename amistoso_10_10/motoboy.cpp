/*Feito por Murilo*/
#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;


/*
* O problema se enquadra em um problema clássico de mochila binária,
* ou knapsack 0/1.
* Para mais, ver: https://www.geeksforgeeks.org/dsa/0-1-knapsack-problem-dp-10
* wt = vetor peso, que no caso do problema é o numero de pizzas
* val = vetor de valores, que no caso é o tempo de entrega
* w = maximo de pizzas que o motoboy pode entregar
*/
int solve(int w, const vector<int> &val, const vector<int> &wt) {
	vector<int> dp(w+1, 0);

	for(int i = 0; i < wt.size(); i++) {
		for(int j = w; j >= wt[i]; j--) {
			dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
		}
	}
	return dp[w];
}

int main(void) {
	int n;
	while(cin >> n && n > 0) {
		int w; cin >> w;
		vector<int> tempos(n), quantidade(n);
		for(int i = 0; i < n; i++) {
			cin >> tempos[i] >> quantidade[i];
		}
		cout << solve(w, tempos, quantidade) << " min.\n";
	}
}
