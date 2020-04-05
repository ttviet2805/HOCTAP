#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair <int, int>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)
#define fast_machine ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int inf = 5e8;
const int MOD = 1e9;
int n;

void in() {
	cin >> n;
}

int get(int x) {
	cout << "QUERY " << x << ' ' << (x + inf - 1) % MOD << endl;
	int t; cin >> t;

	if(t == n / 2) {
		cout << "YES " << x << '\n';
		exit(0);
	}

	return t;
}

void process() {
	int low = 0, high = inf;

	int val = get(0);

	FOR(i, 1, 30) {
	 	int mid = (low + high) / 2;

	 	int t = get(mid);

	 	if((t > n / 2 && val < n / 2) || (t < n / 2 && val > n / 2)) high = mid; 
	 	else low = mid;
	}

	cout << "YES " << (low + high) / 2 << '\n';
	exit(0);
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