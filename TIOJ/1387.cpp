#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())

#ifdef debug
#define dbg(...) cerr<<#__VA_ARGS__<<" = ", de(__VA_ARGS__);
template<typename T>
void de(T t) {cerr<<t<<endl;}
template<typename T, typename ...U>
void de(T t, U...u) {cerr<<t<<", ", de(u...);}
#else
#define dbg(...)
#define endl "\n"
#endif

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n), w(n), c(n);
    for(int i=0; i<n; i++) {
        cin>>v[i]>>w[i]>>c[i];
    }
    int m; cin>>m;
    vector<int> dp(10001), ndp(10001);
    for(int i=0; i<n; i++) {
        for(int j=0; j<v[i]; j++) {
            deque<pair<int, int>> dq;
            for(int k=j; k<=m; k+=v[i]) {
                if(sz(dq)&&(k-dq.front().ss)/v[i]>c[i]) {
                    dq.pop_front();
                }                
                while(sz(dq)&&dp[k]-w[i]*(k-j)/v[i]>dq.back().ff) {
                    dq.pop_back();
                }
                dq.push_back({dp[k]-w[i]*(k-j)/v[i], k});
                ndp[k]=max(ndp[k], dq.front().ff+w[i]*(k-j)/v[i]);
            }
        }
        dp=ndp;
    }
    cout<<*max_element(all(ndp));
    return 0;
}
