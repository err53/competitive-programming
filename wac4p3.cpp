#include <bits/stdc++.h>
using namespace std;

int N, S, x[15], y[15], vx[15], vy[15];
double dp[1 << 15][15], ans = 1.0e20;

double fun(double mx, double my, double t0, int i) {
    double dx = x[i] + vx[i] * t0 - mx, dy = y[i] + vy[i]*t0 - my;
    double A = S*S-vx[i] * vx[i]-vy[i] * vy[i], B = -2*(dx*vx[i] + dy*vy[i]);
    double C = -dx*dx - dy * dy;
    return (-B + sqrt(B*B - 4*A*C))/(2*A);
}

int main()
{
    cin >> N >> S;
    fill_n(dp[0], 15*(1<<15), 1.0e20);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> vx[i] >> vy[i];
        dp[1<<i][i] = fun(0, 0, 0, i);
    }
    for (int mask = 1; mask < (1<<N); mask++) {
	    for(int i = 0; i < N; i++) {
		    if (!(mask & (1<<i))) continue;
		    for(int j = 0; j < N; j++) {
			    if(mask & (1<<j)) continue;
			    int nmask = mask | (1<<j);
			    double mx = dp[mask][i]*vx[i] + x[i], my = dp[mask][i]*vy[i] + y[i];
			    dp[nmask | (1<<j)][j] = min(dp[nmask| (1<<j)][j], dp[mask][i] + fun(mx, my, dp[mask][i], j));
		    }
	    }
    }
    int mask = (1 << N) - 1;
    for(int i = 0; i < N; i++) ans = min(ans, dp[mask][i]);
    printf("%.9f\n", ans);
}
