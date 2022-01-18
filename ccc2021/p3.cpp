#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Person {
    ll pos, dist, weight;
};

int N;
ll minPos = LONG_LONG_MAX;
ll maxPos = 0;
ll minTime = LONG_LONG_MAX;
int slowestIdx = 0;

array<Person, 200000+3> friends;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        ll p, d, w;
        cin >> p >> w >> d;
        friends[i].pos = p;
        friends[i].weight = w;
        friends[i].dist = d;
        minPos = min(minPos, p);
        maxPos = max(maxPos, p);
        if (friends[i].weight > friends[slowestIdx].weight) {
            slowestIdx = i;
        }
    }
    int i = friends[slowestIdx].pos, above = friends[slowestIdx].pos, below = friends[slowestIdx].pos;
    while (above <= maxPos || below >= minPos) {
        if (above < maxPos) {
            ll time = 0;
            for (int j = 0; j < N; j++) {
                if (friends[j].pos < above) {
                    // friend pos is to the left
                    time += max(ll(0), (above - friends[j].pos - friends[j].dist) * friends[j].weight);
                } else if (friends[j].pos > above) {
                    // to the right
                    time += max(ll(0), (friends[j].pos - friends[j].dist - above) * friends[j].weight);
                }
            }
            minTime = min(minTime, time);
        }
        if (below >= minPos) {
            ll time = 0;
            for (int j = 0; j < N; j++) {
                if (friends[j].pos < below) {
                    // friend pos is to the left
                    time += max(ll(0), (below - friends[j].pos - friends[j].dist) * friends[j].weight);
                } else if (friends[j].pos > below) {
                    // to the right
                    time += max(ll(0), (friends[j].pos - friends[j].dist - below) * friends[j].weight);
                }
            }
            minTime = min(minTime, time);
        }
        above++;
        below--;
    }
    cout << minTime << endl;
}
