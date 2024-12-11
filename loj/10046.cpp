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

const int mxN = 1e6;
int p[mxN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
	string s; cin >> s;
	for (int i = 1, j = 0; i < n; i++) {
		while (j && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
	ll ans = 0;
	FOR (i, n) {
		if (p[p[i] - 1]) p[i] = p[p[i] - 1];
	}
	FOR (i, n) {
		if (p[i]) ans += i - p[i] + 1;
	}
	cout << ans;
    return 0;
}
