#include <bits/stdc++.h>

using namespace std;

const long long MK = 1000000;
const long long MM = 1e7+3;

int M, N, K;
unordered_map<int, unordered_map<int, bool>> grid;
bool rows[MM], cols[MM];
int goldCount = 0;
// rows x cols

void flipRow(int m) {
    for(int i = 0; i < N; i++) {
        if (grid[m][i]) {
            grid[m][i] = false;
            goldCount--;
        } else {
            grid[m][i] = true;
            goldCount++;
        }
    }
}

void flipCol(int n) {
    for(int i = 0; i < M; i++) {
        if (grid[i][n]) {
            grid[i][n] = false;
            goldCount--;
        } else {
            grid[i][n] = true;
            goldCount++;
        }
    }
}

int main() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        string type;
        int num;
        cin >> type >> num;
        if (type == "R") {
            rows[num-1] = !rows[num-1];
        } else {
            cols[num-1] = !cols[num-1];
        }
    }

    for (int i = 0; i < M; i++) {
        if (rows[i]) {
            flipRow(i);
        }
    }

    for (int i = 0; i < N; i++) {
        if (cols[i]) {
            flipCol(i);
        }
    }
    cout << goldCount << endl;
}
