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
int n, T, l, f[N], d[N], L[N], R[N], par[N], len[N];
vector <II> a[N], ed;
bool vs[N], ver[N];

void dfs_down(int x) {
	vs[x] = true;

	for(auto i : a[x]) {
		if(vs[i.fi]) continue;

		dfs_down(i.fi);
		f[x] = max(f[x], f[i.fi] + i.se);
	}
}

void dfs_up(int x) {
	vs[x] = true;

	vector <II> tmp;
	tmp.clear();
	tmp.push_back({0, 0});

	for(auto i : a[x]) {
		if(vs[i.fi]) continue;

		tmp.push_back({i.fi, i.se});
	}

	L[0] = 0, R[tmp.size()] = 0;
	for(int i = 1; i < tmp.size(); i++) 
		L[i] = max(L[i - 1], f[tmp[i].fi] + tmp[i].se);

	for(int i = tmp.size() - 1; i >= 1; i--) 
		R[i] = max(R[i + 1], f[tmp[i].fi] + tmp[i].se);

	for(int i = 1; i < tmp.size(); i++) {
		d[tmp[i].fi] = max({L[i - 1] + tmp[i].se, R[i + 1] + tmp[i].se});
		d[tmp[i].fi] = max(d[tmp[i].fi], d[x] + tmp[i].se);
	}

	for(auto i : a[x]) {
		if(vs[i.fi]) continue;

		dfs_up(i.fi);
	}
}
void in() {
	cin >> n;

	FOR(i, 1, n - 1) {
		int u, v, w; cin >> u >> v >> w;

		a[u].push_back({v, w}), a[v].push_back({u, w});
	} 	

	dfs_down(1);

	memset(vs, false, sizeof(vs));
	dfs_up(1);

	FOR(i, 1, n) {
		len[i] = max(f[i], d[i]);
		ed.push_back({len[i], i});
	}

	sort(ed.rbegin(), ed.rend());
}

int root(int x) {
	if(par[x] < 0) return x;
	return par[x] = root(par[x]);
}

void Merge(int u, int v) {
	if((u = root(u)) == (v = root(v))) return;

	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v], par[v] = u;
}

void Remove(int x) {
	par[root(x)]++;
}

void process() {
	int res = 0, low = 0;

	memset(par, -1, sizeof(par));
	memset(ver, 0, sizeof(ver));

	for(int i = 0; i < ed.size(); i++) {
		int x = ed[i].se, dai = ed[i].fi;

		while(low < i && ed[low].fi - dai > l) {
			ver[ed[low].se] = false;
			Remove(ed[low].se);
			low++;
		}

		ver[x] = true;

		// cout << low << ' ' << i << endl;
		for(auto j : a[x]) {
			if(ver[j.fi]) Merge(x, j.fi);
		}

		res = max(res, abs(par[root(x)]));
	}

	cout << res << '\n';
}

#undef int
int main() {
	if(fopen("trash.inp", "r"))
		freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
	fast_machine;

	#define int long long
	in();

	cin >> T;

	while(T--) {
		cin >> l;
		process();
	}
}