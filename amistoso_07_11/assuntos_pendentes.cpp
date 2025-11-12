#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string in; cin >> in;

	int ans = accumulate(in.begin(), in.end(), 0, [](int acc, char c) {
		if(c == '(') return acc + 1;
		if(c == ')' && acc > 0) return acc - 1;
		return acc;
	});


	if(ans) {
		cout << "Ainda temos " << ans << " assunto(s) pendente(s)!" << endl;
	} else cout << "Partiu RU!" << endl;
}
