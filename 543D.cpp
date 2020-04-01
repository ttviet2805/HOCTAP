#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair <int, int>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)
#define fast_machine ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int n, f[N], d[N], s[N], rev[N];
vector <int> a[N];
bool vs[N];

void dfs_down(int x) {
	vs[x] = true;
	f[x] = 1;

	for(auto i : a[x]) {
		if(vs[i]) continue;

		dfs_down(i);
		f[x] = (f[x] * (f[i] + 1)) % MOD;
	}
}

void dfs_up(int x) {
	vs[x] = true;
	vector <II> tmp;

	tmp.clear();
	tmp.push_back({0, 0});
	for(auto i : a[x]) {
		if(vs[i]) continue;

		tmp.push_back({i, f[i]});
	}

	s[0] = 1, rev[tmp.size()] = 1;

	// for(auto i : tmp) cout << i.fi << ' ' << i.se << endl;

	for(int i = 1; i < tmp.size(); i++) {
		s[i] = s[i - 1] * (tmp[i].se + 1) % MOD;
	} 

	for(int i = tmp.size() - 1; i >= 1; i--) {
		rev[i] = rev[i + 1] * (tmp[i].se + 1) % MOD;
	}

	for(int i = 1; i < tmp.size(); i++) {
		d[tmp[i].fi] = (s[i - 1] * rev[i + 1] % MOD * d[x] + 1) % MOD;

		// cout << tmp[i].fi << ' ' << d[tmp[i].fi] << endl;
	}

	// exit(0);
	for(auto i : a[x]) {
		if(vs[i]) continue;
		dfs_up(i);
	}
}

void in() {
	cin >> n;

	FOR(i, 2, n) {
		int x; cin >> x;
		a[i].push_back(x), a[x].push_back(i);
	}	

	d[1] = 1;
	dfs_down(1);

	memset(vs, false, sizeof(vs));
	dfs_up(1);
}

void process() {
	FOR(i, 1, n) {
		int res = f[i] * d[i] % MOD;

		cout << res << ' ';
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