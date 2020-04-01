#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair <int, int>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)
#define fast_machine ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int N = 3e6 + 5;
int n, a[N], m, f[N], c[N], d[N];

void in() {
	cin >> n;

	FOR(i, 1, n) {
		cin >> a[i];
		c[a[i]]++;
	}

	memset(d, 0, sizeof(d));

	FOR(i, 1, N - 5) {
		if(c[i] == 0) continue;

		for(int j = i; j <= N - 5; j += i) {
			if(i * i == j) {
				d[j] += c[i] * (c[i] - 1);
			}
			else
				d[j] += c[i] * c[j / i];
		}
	}
	cin >> m;

	f[1] = n * (n - 1);

	FOR(i, 2, N - 5) f[i] = f[i - 1] - d[i - 1];

}

void process() {
	FOR(i, 1, m) {
		int t; cin >> t;

		cout << f[t] << '\n';
	}
}

#undef int
int main() {
	if(fopen("trash.inp", "r"))
		freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
	fast_machine;

	#define int long long
	in();
	process();
}