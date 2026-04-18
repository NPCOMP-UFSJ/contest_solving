#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int v[n];
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	int s=0,d=0;
	for(int i=0,j=n-1; i<=j;) {
		if(v[i] > v[j]) {
			s += v[i];
			i++;
		} else {
			s += v[j];
			j--;
		}
		if(i > j) break;
		if(v[i] > v[j] ) {
				d+=v[i];
				i++;
			} else {
				d += v[j];
				j--;
			}
	}
	cout << s << " " << d << "\n";
	return 0;
}
