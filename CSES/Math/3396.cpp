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
    int t; cin>>t;
    bitset<1000001> p;
    p.set();
    vector<int> v;
    for(ll i=2; i<=1000000; i++) {
        if(!p[i]) continue;
        v.push_back(i);
        for(ll j=i*i; j<=1000000; j+=i) {
            p[j]=0;
        }
    }
    while(t--) {
        ll x; cin>>x;
        for(ll i=x+1; ; i++) {
            bool good=1;
            for(int y : v) {
                if(y>=i) break;
                if(i%y==0) {
                    good=0;
                    break;
                }
            }
            if(good) {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
