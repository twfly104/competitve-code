#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
 
const int mod=1e9+7, mxN=1e6;
 
ll mul[mxN+1], inv[mxN+1];
 
ll f(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
 
void pre() {  
    inv[mxN]=f(mul[mxN], mod-2);
    for(int i=mxN-1; i>=0; i--) {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    mul[0]=1;
    for(int i=1; i<=mxN; i++) {
        mul[i]=mul[i-1]*i%mod;
    }
    pre();
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        cout<<mul[a]*inv[b]%mod*inv[a-b]%mod<<"\n";
    }
    return 0;
}
