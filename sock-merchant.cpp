#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
vector<int> ar;
int main() {
	cin >> n;
	for (int i = 0, t; i < n; i++) {
		cin >> t;
		ar.emplace_back(t);
	}
	sort(ar.begin(), ar.end());
	for (int i = 0; i < ar.size(); i++) {
		if (ar[i] == ar[i+1]) {
			i++;
			ans++;
		}
	}
	cout << ans << endl;
}
