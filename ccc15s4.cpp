// ============================================================================
// Author      : jhthenerd
// Description : a competitive programming solution
// ============================================================================

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 10010;

struct Route;

struct Island {
    vector<Route> out;
    int shortestPath, hull;

    Island()
    {
        shortestPath = INT_MAX;
        hull = -1;
    }
};

struct Route {
    Island* destination;
    ll distance, damage;

    Route(Island* dest, ll d, ll dmg)
    {
        destination = dest;
        distance = d;
        damage = dmg;
    }
};

Island islands[MAX];

int a, b, c, d, convexHull, start, finish;

int totalWeight, damage;

void Dijkstra()
{
    queue<Island*> toCheck;
    queue<int> distance;
    queue<int> maxHull;

    islands[a].shortestPath = 0;

    distance.push(0);
    toCheck.push(&islands[start]);
    maxHull.push(convexHull);

    while (!toCheck.empty()) {
        Island* front = toCheck.front();
        int dist = distance.front();
        int height = maxHull.front();

        toCheck.pop();
        maxHull.pop();
        distance.pop();

        for (auto route: front->out) {
            int newHeight = height-route.damage;
            int newDist = dist+route.distance;
            Island* destination = route.destination;
            if ((newDist<destination->shortestPath || newHeight>destination->hull) && newHeight>0) {
                destination->shortestPath = min(newDist, destination->shortestPath);
                destination->hull = max(destination->hull, newHeight);
                toCheck.push(destination);
                maxHull.push(newHeight);
                distance.push(newDist);
            }
        }
    }
}

int N, M;

int main()
{
    scanf("%d%d%d", &convexHull, &N, &M);
    for (int i = 0; i<M; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        islands[a].out.emplace_back(Route(&islands[b], c, d));
        islands[b].out.emplace_back(Route(&islands[a], c, d));
    }
    scanf("%d%d", &start, &finish);
    Dijkstra();
    if (islands[finish].shortestPath != INT_MAX) {
        printf("%d", islands[finish].shortestPath);
    }
    else {
        printf("-1");
    }
}

