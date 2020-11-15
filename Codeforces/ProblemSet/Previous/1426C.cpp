#include <bits/stdc++.h>

using namespace std;

int c(int x, int k){
	return (k - 1 + ((x - k) + k - 1) / k);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int p = 1e9;
		int a = 1e9;
		for (int k = 1; k <= n; ++k) {
			int i = c(n, k);
			if(p < i){
				a = p;
				break;
			} else {
				p = i;
			}
		}
		
		if(a == 1e9){
			a = p;
		}

		cout << a << endl;
	}

	return 0;
}
