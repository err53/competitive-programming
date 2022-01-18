#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
typedef pair<int, int> pi;
typedef long long ll;
int N, sz[MM], val[2][2*MM], path[2*MM]; vector<pi> adj[MM]; bool done[MM]; ll ans;
void getsz(int u, int pa){
    sz[u] = 1;
    for(pi e: adj[u]){
        if(e.first != pa && !done[e.first]) { getsz(e.first, u); sz[u]+=sz[e.first]; }
    }
}
int getcent(int u, int pa, int tot){
    for(pi e: adj[u]){
        if(e.first != pa && !done[e.first] && sz[e.first]*2>tot)
            return getcent(e.first, u, tot);
    }
    return u;
}
void dfs1(int u, int sum, int pa){
    path[sum+N]++; ans+= val[1][-sum+N] + (path[sum+N]>1)*val[0][-sum+N];
    for(pi e: adj[u])
        if(e.first != pa && !done[e.first]) dfs1(e.first, sum+e.second, u);
    path[sum+N]--;
}
void dfs2(int u, int sum, int pa){
    path[sum+N]++;
    if(path[sum+N] > 1) val[1][sum+N]++;
    else val[0][sum+N]++;
    for(pi e: adj[u])
        if(e.first != pa && !done[e.first]) dfs2(e.first, sum+e.second, u);
    path[sum+N]--;
}
void solve(int rt){
    getsz(rt, 0); rt = getcent(rt, 0, sz[rt]); done[rt]=1;
    for(int i=-sz[rt]+N; i<=sz[rt]+N; i++)
        path[i] = val[0][i] = val[1][i] = 0;
    val[0][N] = 1; //root has no stop city with path sum = 0
    for(pi e: adj[rt]){
        int v = e.first, w = e.second;
        if(!done[v]){
            path[N]=0; dfs1(v, w, rt);
            path[N]=1; dfs2(v, w, rt);
        }
    }
    for(pi e: adj[rt])
        if(!done[e.first]) solve(e.first);
}
int main(){
    scanf("%d", &N);
    for(int i=1, u, v, w; i<N; i++){
        scanf("%d %d %d", &u, &v, &w); w = (w==1? 1:-1);
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    solve(1); cout << ans << endl;
}
