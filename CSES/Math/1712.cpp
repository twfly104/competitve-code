#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define timeflew
#ifdef timeflew
#define dbg(LINE...) cerr << "[" << #LINE << "] : ", dout(LINE)
void dout() {cerr << '\n';}
template<typename T, typename...U>
void dout(T t, U...u) {cerr << t << (sizeof... (u) ? ", ":""), dout(u...);}
#else
#define dbg(...) 7122
#endif
 
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define sz(x) (int)(x.size())
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define FOR1(i, a, b) for (int i = (a); i <= (b); i++)
 
#define int long long
const int mod = 1e9 + 7;
 
int f(int a, int b, int c) {
	if (b == 0) return 1;
	int x = f(a, b / 2, c);
	if (b & 1)	return a * x % c * x % c;
	else return x * x % c;
}
 
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		int x = f(b, c, mod - 1);
		cout << f(a, x, mod) << "\n";
	}
	return 0;
}
