#include <bits/stdc++.h>
using namespace std;
string input, output[3];
// 1 = ..
// 2 = o.
// 3 = .o
// 4 = oo
string row[3] = {
		"22442442332244244233223442",
		"12133244241213324424124133",
		"11111111112222222222443444"
	};
int main() {
	getline(cin, input);
	for (auto c : input) {
		if (c == ' ') {
			for (int i = 0; i < 3; i++) {
				output[i] += "..";
			}
			continue;
		}
		for (int i = 0; i < 3; i++) {
			switch (row[i][c-'A']) {
				case '1': output[i] += ".."; break;
				case '2': output[i] += "o."; break;
				case '3': output[i] += ".o"; break;
				case '4': output[i] += "oo"; break;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << output[i] << endl;
	}
}
