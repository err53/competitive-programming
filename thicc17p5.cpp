#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ull N, K, i1 = 0, notDiverse = 0;
array<ull, 1000001> arr, freq;

int main() {
	scanf("%lld%lld", &N, &K);
	int size = 0;

	for (int i = 0; i < N; ++i) {
		scanf("%lld", &arr[i]);
		if (freq[arr[i]] == 0) ++size;
		freq[arr[i]]++;
		while (size >= K) {
			freq[arr[i1]]--;
			if (freq[arr[i1]]==0) --size;
			i1++;
		}
		notDiverse += (i -i1+1);
	}
	printf("%lld\n", (N*N+N)/2-notDiverse);

	return 0;
}
