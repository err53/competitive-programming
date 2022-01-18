#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef pair<int, int> pi;
int N, M, C, ind[MM], val[MM];
vector<pi> adj[MM];
int main() {
	cin >> N >> M >> C;
	for (int i = 1, x; i <= N; i++) {
		cin >> x;
		adj[0].push_back({i, x});
		ind[i]++;
	}
	for(int i = 1, u, v, w; i<=C; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		ind[v]++;
	}
	queue<int> q; q.push(0); val[0] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto e : adj[u]) {
			int v = e.first, w = e.second;
			val[v] = max(val[v], val[u]+w);
			if(--ind[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << val[i] << "\n";
	}
}
