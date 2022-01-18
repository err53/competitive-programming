#include <bits/stdc++.h>
#define fori(a, b) for (int i = a; i < b; i++)
#define forj(a, b) for (int j = a; j < b; j++)
#define fork(a, b) for (int k = a; k < b; k++)
#define ford(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

vector<int> pos[100010];
int n, m, x[100010], num;
string in[100010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  for (int i = 25; i >= 0; i--) {
    m = INT_MAX;
    for (int j = 0; j < n; j++) {
      pos[j].clear();
      for (int k = x[j]; k < in[j].size(); k++)
        if (in[j][k] - 'a' == i)
          pos[j].push_back(k);
    }
    for (int j = 0; j < n; j++)
      m = min(m, (int)pos[j].size());
    if (m == 0)
      continue;
    for (int j = 0; j < n; j++)
      x[j] = max(x[j], pos[j][m - 1]);
    for (int j = 0; j < n; j++)
      cout << (char)('a' + i);
    num += m;
  }
  if (num == 0)
    cout << -1;
  cout << endl;
  return 0;
}