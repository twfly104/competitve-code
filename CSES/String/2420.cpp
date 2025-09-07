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

const int mxN=2e5, mod=1e9+7, g=37;

int n, m;
ll t[mxN*4+1], t1[mxN*4+1], p[mxN+1];
string s;

void psh(int idx) {
    t[idx]=(t[idx*2]+t[idx*2+1])%mod;
    t1[idx]=(t1[idx*2]+t1[idx*2+1])%mod;
}

void upd(int idx, int pos, int val, int L, int R) {
    if(L==R) {
        t[idx]=p[pos]*val%mod;
        t1[idx]=p[n-pos+1]*val%mod;
        return;
    }
    int mid=(L+R)/2;
    if(pos<=mid) upd(idx*2, pos, val, L, mid);
    else upd(idx*2+1, pos, val, mid+1, R);
    psh(idx);
}

pair<ll, ll> qry(int idx, int l, int r, int L, int R) {
    if(l<=L&&R<=r) {
        return {t[idx], t1[idx]};
    }
    pair<ll, ll> res={0, 0}, res1={0, 0};
    int mid=(L+R)/2;
    if(l<=mid) res=qry(idx*2, l, r, L, mid);
    if(mid<r) res1=qry(idx*2+1, l, r, mid+1, R);
    return {res.ff+res1.ff, res.ss+res1.ss};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    p[0]=1;
    for(int i=1; i<=n; i++) {
        p[i]=p[i-1]*g%mod;
    }
    for(int i=1; i<=n; i++) upd(1, i, s[i]-'a'+1, 1, n);
    for(int i=0; i<m; i++) {
        int ty; cin>>ty;
        if(ty==1) {
            int pos;
            char c;
            cin>>pos>>c;
            upd(1, pos, c-'a'+1, 1, n);
        } else {
            int l, r; cin>>l>>r;
            pair<int, int> res=qry(1, l, r, 1, n);
            if(n-r+1>=l) {
                if(res.ff*p[n-r+1-l]%mod==res.ss) {
                    cout<<"YES"<<endl;
                } else {
                    cout<<"NO"<<endl;
                }
            } else {
                if(res.ss*p[l-(n-r+1)]%mod==res.ff) {
                    cout<<"YES"<<endl;
                } else {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}
