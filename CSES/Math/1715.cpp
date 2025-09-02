#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
 
#ifdef debug
#define dbg(...) cerr<<#__VA_ARGS__<<" = ", de(__VA_ARGS__);
template<typename T>
void de(T t) {
	cerr<<t<<endl;
}
template<typename T, typename...U>
void de(T t, U...u) {
	cerr<<t<<", ", de(u...);
}
#else
#define dbg(...)
#define endl "\n"
#endif
 
#define int ll
 
const int mxN=1e6, mod=1e9+7;
 
int c[mxN+1], c1[mxN+1];
map<char, int> mp;
 
int inv(int x) {
    return x==1?1:(mod-mod/x)*inv(mod%x)%mod;
}
 
void pre() {
    c[0]=c1[0]=1;
    for(int i=1; i<=mxN; i++) {
        c[i]=c[i-1]*i%mod;
    }
    c1[mxN]=inv(c[mxN]);
    for(int i=mxN-1; i>=1; i--) {
        c1[i]=c1[i+1]*(i+1)%mod;   
    }
}
 
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    pre();
    for(int i=0; i<s.size(); i++) {
        mp[s[i]]++;
    }
    int ans=c[s.size()];
    dbg(ans);
    for(int i=0; i<26; i++) {
        ans=ans*c1[mp['a'+i]]%mod;
    }
    cout<<ans;
    return 0;
}
