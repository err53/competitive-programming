#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 2;
unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
mt19937_64 gen(seed1);
uniform_int_distribution<ll> dis(1, 1e12);
int N, M;
ll w[MM], sum, ans, psa;
unordered_map<ll, int> mp;
int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    w[i] = dis(gen);
    sum += w[i];
  }
  mp[0] = 1;
  for (int i = 1, x; i <= N; i++) {
    cin >> x;
    psa = (psa + w[x]) % sum;
    ans += mp[psa];
    mp[psa]++;
  }
  cout << ans << endl;
}