#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair <int, int>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)
#define fast_machine ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)

struct edge {
	int x, y, dis;

	bool operator < (const edge &a) const {
		return a.dis < dis;
	}	
};

const int N = 2005;
int n, k, f[N], c[N][N], sum, d[N][N], par[N], res;
priority_queue <edge> H;
bool vs[N][N];

int root(int u) {
	if(par[u] < 0) return u;

	return par[u] = root(par[u]);
}

void in() {
	cin >> n >> k;

	memset(par, -1, sizeof(par));
	memset(vs, false, sizeof(vs));

	res = 0;
	FOR(i, 1, n) cin >> f[i], res += f[i];

	while(!H.empty()) H.pop();

	FOR(i, 1, n) FOR(j, 1, n) {
		cin >> c[i][j];
		vs[i][j] = vs[j][i] = true;

		if(i < j) {
			d[i][j] = d[j][i] = c[i][j] - max(f[i], f[j]);

			int x = i, y = j;

			if(f[x] > f[y]) swap(x, y);
			H.push({x, y, d[i][j]});
		}
	}
	
	FOR(i, 1, n) vs[i][i] = false;
}

void process() {
	int cnt = 1;

	while(!H.empty()) {
		edge t = H.top();
		H.pop();

		int u = t.x, v = t.y, dis = t.dis;

		if(root(u) != u || root(v) != v) continue;
		if(cnt > n - k && dis >= 0) break;

		// cout << u << ' ' << v << ' ' << dis << endl;
		res += dis, cnt++;

		par[u] += par[v], par[v] = u;

		vs[u][v] = vs[v][u] = false;

		FOR(i, 1, n) {
			if(vs[v][i]) {
				if(d[u][i] > c[v][i] - max(f[i], f[u])) {
					c[u][i] = c[i][u] = c[v][i];
					d[i][u] = d[u][i] = c[v][i] - max(f[i], f[u]);

					int x = u, y = i;

					if(f[x] > f[y]) swap(x, y);
					H.push({x, y, d[u][i]});
				}
			}
		}

	}

	cout << res << '\n';
}

#undef int
int main() {
	if(fopen("trash.inp", "r"))
		freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
	fast_machine;

	#define int long long

	int T; cin >> T;

	while(T--) {
		in();
		process();
	}
}