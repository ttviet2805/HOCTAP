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
int n, m, k, dis[N], vol[N], S, T;
vector <II> a[N];
priority_queue <II, vector <II>, greater <II> > H;

void in() {
	cin >> n >> m >> k;

	FOR(i, 1, k) {
		int x; cin >> x;
		vol[x] = true;
	}

	FOR(i, 1, m) {
		int u, v; cin >> u >> v;

		a[u].push_back({v, 1}), a[v].push_back({u, 1});
	}

	cin >> S >> T;
}

bool check(int mid) {
	while(!H.empty()) H.pop();
	FOR(i, 1, n) dis[i] = 1e18;

	H.push({0, S});
	dis[S] = 0;

	while(!H.empty()) {
		II t = H.top();
		H.pop();

		int x = t.se, len = t.fi;

		if(dis[x] != len) continue;

		// cout << x << ' ' << len << endl;

		for(auto i : a[x]) {
			int y = i.fi, dai = i.se + len;

			if(vol[y]) dai = 0;

			if(dis[y] > dai) {
				dis[y] = dai;
				if(dai + 1 <= mid) H.push({dis[y], y});
			}
		}
	}

	return dis[T] <= mid;
}

void process() {
	
	int low = 1, high = n, res = -1;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(check(mid)) high = mid - 1, res = mid;
		else low = mid + 1;
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
	process();
}