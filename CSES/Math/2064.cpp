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

const int mxN=1e6, mod=1e9+7;

ll c[mxN+1], c1[mxN+1];

ll f(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) {
            res=res*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);    
    ll n; cin>>n;
    if(n&1) {
        cout<<0;
        return 0;
    }
    c[0]=1;
    for(int i=1; i<=n; i++) {
        c[i]=c[i-1]*i%mod;    
    }
    c1[n]=f(c[n], mod-2);
    for(int i=n-1; i>=1; i--) {
        c1[i]=c1[i+1]*(i+1)%mod;
    }
    cout<<c[n]*c1[n/2]%mod*c1[n/2]%mod*f(n/2+1, mod-2)%mod;
    return 0;
}
