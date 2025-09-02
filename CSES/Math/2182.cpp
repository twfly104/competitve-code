#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
 
const int mod=1e9+7;
 
ll f(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<ll, ll>> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i].ff>>v[i].ss;//x k
    }
    ll res=1, res1=1, res2=1, cnt=1;
    for(int i=0; i<n; i++) {
        res=res*(v[i].ss+1)%mod;
        res1=res1*(f(v[i].ff, v[i].ss+1)%mod-1)%mod*f(v[i].ff-1, mod-2)%mod;
        res2=f(res2, v[i].ss+1)*f(f(v[i].ff, (v[i].ss*(v[i].ss+1)/2)%(mod-1)), cnt)%mod;
        cnt=(cnt*(v[i].ss+1))%(mod-1);
    }
    cout<<res<<' '<<res1<<' '<<res2;
    return 0;
