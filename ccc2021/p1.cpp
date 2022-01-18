#include <bits/stdc++.h>

using namespace std;

const long long MM = 100000+3;
int N;
int heights[MM];
long double area = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N+1; i++) {
        cin >> heights[i];
    }
    for (int i = 0; i < N; i++) {
        double width;
        cin >> width;
        area += width*(heights[i] + heights[i+1])/2;
    }
    cout << area << endl;
}
