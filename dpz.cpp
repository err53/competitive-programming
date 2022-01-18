#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N, q[MM], f = 0, r = 0; ll C, dp[MM], h[MM];
double slope(int j, int k) {
	return (double)(dp[k] + h[k] * h[k] - dp[j] - h[j] * h[j])/(2.0*(h[k]-h[j]));
}
int main() {
	cin >> N >> C;
	for (int i = 1; i <= N; i++) cin >> h[i];
	memset(dp, 0x3f, sizeof dp);
	dp[1] = 0; q[r++] = 1;
	for(int i = 2; i <= N; i++) {
		while(f+1 < r && slope(q[f], q[f+1]) <= h[i]) f++;
		dp[i] = dp[q[f]] + (h[i] - h[q[f]])*(h[i] - h[q[f]]) + C;
		while(f+1 < r && slope(q[r-1], q[r-1]) >= slope(q[r-1], i)) r--;
		q[r++] = i;
	}
	cout << dp[N] << endl;
}
