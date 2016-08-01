#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long f[20];
	f[0] = 1;
	for (int i = 1; i < 20; i++) {
		f[i] = i * f[i - 1];
	}
	int n, l, c;
	string s = "";
	long long o = 0;

	cin >> n;
	while (n--) {
		cin >> s >> o;
		l = s.length();
		sort(s.begin(), s.end());

		while (1) {
			l = s.length() - 1;
			c = o / f[l];
			o %= f[l];
			cout << s[c];
			s.erase(s.begin() + c);
			if (!o) {
				cout << s << "\n";
				break;
			}
		}
	}
	return 0;
}
