#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FAST cin.sync_with_stdio(0); cin.tie(0);
const int MAX = 1e5 + 5;
ll dp[MAX];

int main() {
    FAST

    int N, W;
    cin >> N >> W;

    for (int i = 1; i <= N; ++i) {
        int w, v;
        cin >> w >> v;
        for (int j = W; j >= w; --j) {
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    cout << dp[W] << endl;

    return 0;
}

