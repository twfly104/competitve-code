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

const int mxN = 1e5;
int ch[mxN + 1][10], total;
bool b[mxN + 1], flag;

struct trie {
    void init() {
        memset(ch, -1, sizeof(ch));
        memset(b, false, sizeof(b));
        flag = 0;
        total = 0;
    }
    void insert(string s) {
        int node = 0;
        FOR (i, sz(s)) {
            if (ch[node][s[i] - '0'] == -1) ch[node][s[i] - '0'] = ++total;
            else if (i == sz(s) - 1) flag = 1;
            node = ch[node][s[i] - '0'];
            if (b[node]) flag = 1;
        }
        b[node] = 1;
    }
} T;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int tt; cin >> tt;
        T.init();
        while (tt--) {
            string s; cin >> s;
            T.insert(s);
        }
        if (!flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
