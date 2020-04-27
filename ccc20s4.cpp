#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, A[MM], B[MM], C[MM], ans = 1e9;
string S;
void update(int x[], int y[], int i) {
	int nx = x[N], ny = y[N], swaps = nx-(x[i] - x[i-nx]) + ny-(y[i-nx]-y[i-nx-ny]);
	swaps -= min(y[i]-y[i-nx], x[i-nx]-x[i-nx-ny]);
	ans = min(ans, swaps);
}
int main() {
	cin >> S;
	N=S.size();
	for (int i = 1; i <= N; i++) {
		A[i] = A[i-1];
		B[i] = B[i-1];
		C[i] = C[i-1];
		if (S[i-1] == 'A') {
			A[i]++;
		}
		else if (S[i-1] == 'B') {
			B[i]++;
		}
		else {
			C[i]++;
		}
	}
	int na = A[N], nb = B[N], nc = C[N];
	for (int i = 1; i <= N; i++) {
		if (i >= na + nb) {
			update(A, B, i);
			update(B, A, i);
		}
		if (i >= na + nc) {
			update(A, C, i);
			update(C, A, i);
		}
		if (i >= nb + nc) {
			update(B, C, i);
			update(C, B, i);
		}
	}
	cout << ans << endl;
}

