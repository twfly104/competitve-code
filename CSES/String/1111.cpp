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

const int mxN=1e6;

int ma[mxN*2+1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);    
    string s; cin>>s;
    int n=sz(s);
    string t;
    t+="#";
    for(int i=0; i<n; i++) {
        t+=s[i];
        t+="#";
    }
    for(int i=0, l=0, r=0; i<sz(t); i++) {
        if(i<=r) ma[i]=min(ma[r-i+l], r-i+1);
        while(i+ma[i]<sz(t)&&i-ma[i]>=0&&t[i+ma[i]]==t[i-ma[i]]) {
            ma[i]++;
            l=i-ma[i]+1;
            r=i+ma[i]-1;
        }
    }
    int pos=1;
    for(int i=0; i<sz(t); i++) {
        if(ma[i]>ma[pos]) {
            pos=i;
        }
    }
    for(int i=pos-ma[pos]+1; i<=pos+ma[pos]-1; i++) {
        if(t[i]!='#')
            cout<<t[i];
    }
    return 0;
}
