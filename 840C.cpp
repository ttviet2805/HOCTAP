#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair <int, int>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)
#define fast_machine ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
const int N = 305;
const int MOD = 1e9 + 7;
int n, a[N], f[N][N], gt[N], cnt[N], total[N], num = 0, trau[N];
bool vs[N];
 
bool check(int a, int b) {
	int t = sqrt(a * b);
 
	return t * t == a * b;
}
 
int Pow(int a, int b) {
	if(b == 0) return 1;
 
	int t = Pow(a, b / 2);
 
	if(b % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
 
int C(int a , int b) {
	if(a > b) return 0;
	return gt[b] * trau[a] % MOD * trau[b - a] % MOD;
}
 
void in() {
	cin >> n;
 
	FOR(i, 1, n) cin >> a[i];
 
	gt[0] = 1, trau[0] = 1;
	FOR(i, 1, n) {
		gt[i] = gt[i - 1] * i % MOD;
		trau[i] = Pow(gt[i], MOD - 2) % MOD;
	}	
 
	FOR(i, 1, n) {
		if(vs[i]) continue;
 
		cnt[++num] = 1;
 
		FOR(j, i + 1, n) {
			if(check(a[i], a[j])) cnt[num]++, vs[j] = true;
		}
	}
 
	FOR(i, 1, num) total[i] = total[i - 1] + cnt[i];
 
}
 
void add(int &a, int b) {
	a = (a + b) % MOD;
}
 
void process() {
	f[1][cnt[1] - 1] = gt[cnt[1]];
 
	FOR(i, 1, num - 1) FOR(j, 0, n) {
		FOR(K, 1, min(total[i] + 1, cnt[i + 1])) FOR(X, 0, min(j, K)) {
			if(f[i][j]) {
				int S = cnt[i + 1];
 
				int val = f[i][j] * gt[S] % MOD * C(K - 1, S - 1) % MOD * C(X, j) % MOD * C(K - X, total[i] + 1 - j) % MOD;
				add(f[i + 1][j + S - K - X], val);
			}
		}
	}
	
	cout << f[num][0] << '\n';
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