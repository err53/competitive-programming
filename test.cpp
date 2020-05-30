#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 6003, LOG = 13;
int N, Q, anc[LOG][MM], dep[MM];
ll dis[MM];
vector<pi> adj[MM];

// LCA Practice

void dfs(int u, int pa) {
  for (pi e : adj[u]) {
    int v = e.first, w = e.second;
    if (v == pa)
      continue;
    dep[v] = dep[u] + 1;
    dis[v] = dis[u] + w;
    dfs(v, u);
    anc[0][v] = u;
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v])
    swap(u, v);
  for (int i = LOG - 1; i >= 0; i--)
    if (anc[i][u] != -1 && dep[anc[i][u]] >= dep[v])
      u = anc[i][u];
  if (u == v)
    return u;
  for (int i = LOG - 1; i >= 0; i--)
    if (anc[i][u] != anc[i][v])
      u = anc[i][u], v = anc[i][v];
  return anc[0][u];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  memset(anc, -1, sizeof(anc));
  for (int i = 1, u, v, w; i < N; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs(0, -1);
  cin >> Q;
  for (int i = 1; i < LOG; i++)
    for (int j = 0; j < N; j++)
      if (anc[i - 1][j] != -1)
        anc[i][j] = anc[i - 1][anc[i - 1][j]];

  for (int i = 1, u, v; i <= Q; i++) {
    cin >> u >> v;
    printf("%lld\n", dis[u] + dis[v] - 2 * dis[lca(u, v)]);
  }
}