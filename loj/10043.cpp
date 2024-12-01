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

const int mxN = 1e3;
int p[mxN];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    while (1) {
        string s, s1; cin >> s;
        if (s == "#") break;
        cin >> s1;
        for (int i = 1, j = 0; i < sz(s1); i++) {
            while (j && s1[i] != s1[j]) j = p[j - 1];
            if (s1[i] == s[j]) j++;
            p[i] = j;
        }
        int ans = 0;
        for (int i = 0, j = 0; i < sz(s); i++) {
            while (j && s[i] != s1[j]) j = p[j - 1];
            if (s[i] == s1[j]) j++;
            if (j == sz(s1)) {
                ans++;
                j = 0;
            }
        }
        cout << ans << "\n";
    }
	return 0;
}
