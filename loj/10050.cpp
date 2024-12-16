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
int ch[32 * mxN + 1][2], a[mxN];

struct trie {
    int total = 0;
    void insert(int x) {
        int node = 0;
        for (int i = 31; i >= 0; i--) {
            int state = (x >> i) & 1; //instead of int state = x & (1 << i)
            if (!ch[node][state]) ch[node][state] = ++total;
            node = ch[node][state];
        }
    }
    int sum(int x) {
        int ans = 0;
        int node = 0;
        for (int i = 31; i >= 0; i--) {
            int state = (x >> i) & 1;
            if (ch[node][!state]) {
                ans += (1 << i);
                node = ch[node][!state];
            } else {
                node = ch[node][state];
            }
        }
        return ans;
    }
} T;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    FOR (i, n) {
        cin >> a[i];
        T.insert(a[i]);
    }
    int ans = 0;
    FOR (i, n) {
        ans = max(ans, T.sum(a[i]));
    }
    cout << ans;
    return 0;
}
