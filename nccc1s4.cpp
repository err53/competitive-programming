#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct event
{
    int u, v, w, f;
};
const int MM = 10e5+3;
int N, M, K, S, T, lst, ans;
vector<event> vec;
unordered_set<int> adj[MM];
bool vis[1002];
bool cmp(event a, event b)
{
    return a.w < b.w || (a.w == b.w && a.f < b.f);
}
void updateEdge(int i)
{
    if (vec[i].f > 0)
    {
        adj[vec[i].u].insert(vec[i].v);
    }
    else
    {
        adj[vec[i].u].erase(vec[i].v);
    }
}
bool bfs(int s, int t)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return vis[t];
}
int main()
{
    cin >> N >> M >> K >> S >> T;
    for (int i = 1, a, b, c, d; i <= M; i++)
    {
        cin >> a >> b >> c >> d;
        vec.push_back({a, b, c, 1});
        vec.push_back({a, b, d + 1, -1});
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < vec.size(); i++)
    {
        int cur = vec[i].w;
        bool flag = vis[T];
        updateEdge(i);
        for (; i + 1 < vec.size() && vec[i + 1].w == cur; i++)
        {
            updateEdge(i + 1);
        }
        if (bfs(S, T))
        {
            ans += (flag ? cur - lst : 1);
        }
        else if (flag)
        {
            ans += cur - lst - 1;
        }
        lst = cur;
    }
    cout << ans << endl;
}