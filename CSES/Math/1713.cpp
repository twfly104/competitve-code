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
    bitset<1000001> vis;
    vector<int> p;
    for(ll i=2; i<=1e6; i++) {
        if(vis[i]) continue;
        for(ll j=i*i; j<=1e6; j+=i) {
            vis[j]=1;
        }
        p.push_back(i);
    }
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        ll ans=1;
        for(int j : p) {
            if(1ll*j*j>x) break;//
            ll cnt=0;
            while(x%j==0) {
                x/=j;
                cnt++;
            } 
            ans=ans*(cnt+1);
        }
        if(x!=1) ans*=2;
        cout<<ans<<endl;
    }
    return 0;
}
