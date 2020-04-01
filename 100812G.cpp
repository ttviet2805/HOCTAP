#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair <int, int>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)
#define fast_machine ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int N = 1e5 + 5;
int n, m, dis[N], root[N];
vector <II> a[N];
priority_queue <II, vector <II>, greater <II> > H;

void in() {
	cin >> n >> m;

	FOR(i, 1, n) {
		int x; cin >> x;

		if(x == 1) a[0].push_back({i, 0}), root[i] = i;
	}		

	FOR(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;

		a[u].push_back({v, w}), a[v].push_back({u, w});
	}
}

void process() {
	FOR(i, 1, n) dis[i] = 1e18;
	H.push({0, 0}), dis[0] = 0;

	while(!H.empty()) {
		II t = H.top();
		H.pop();

		int x = t.se, len = t.fi;

		if(dis[x] != len) continue;

		// cout << x << ' ' << len << endl;
		for(auto i : a[x]) {
			int y = i.fi, dai = i.se;

			if(dis[y] > dis[x] + dai) {
				dis[y] = dis[x] + dai;
				H.push({dis[y], y});

				if(x != 0) root[y] = root[x];
			}
		}
	}

	int res = 1e18, A, B;

	FOR(i, 1, n) {
		for(auto j : a[i]) {
			if(root[i] == root[j.fi]) continue;
			if(dis[i] + dis[j.fi] + j.se < res) {

				res = dis[i] + dis[j.fi] + j.se;

				A = root[i], B = root[j.fi];
			}
		}
	}

	if(res == 1e18) {
		cout << "No luck at all" << '\n';
		exit(0);
	}
	cout << res << '\n';
	cout << A << ' ' << B << '\n';
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