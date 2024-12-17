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

const int mxN = 4e5;
int a[mxN], ch[mxN * 32 + 1][2], l[mxN + 1], r[mxN + 2];

struct trie {
    int total;
    void init() {
        memset(ch, -1, sizeof(ch));
        total = 0;
    }
    void insert(int x) {
        int idx = 0;
        for (int i = 31; i >= 0; i--) {
            int state = (x >> i) & 1;
            if (ch[idx][state] == -1) {
                ch[idx][state] = ++total;
            }
            idx = ch[idx][state];
        }
    }
    int sum(int x) {
        int idx = 0, res = 0;
        for (int i = 31; i >= 0; i--) {
            int state = (x >> i) & 1;
            if (~ch[idx][!state]) {
                idx = ch[idx][!state];
                res += 1 << i;
            } else {
                idx = ch[idx][state];
            }
        }
        return res;
    }
} T;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    FOR (i, n) cin >> a[i];
    T.init();
    FOR (i, n) {
        T.insert(a[i]);
        l[i + 1] = max(l[i], T.sum(a[i]));
    }
    T.init();
    for (int i = n - 1; i >= 0; i--) {
        T.insert(a[i]);
        r[i + 1] = max(r[i + 2], T.sum(a[i]));
    }
    int ans = 0;
    FOR1 (i, 1, n) ans = max(l[i] + r[i], ans);
    cout << ans;
    return 0;
}
