#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
 
#ifdef debug
#define dbg(...) cerr<<#__VA_ARGS__<<" = ", de(__VA_ARGS__)
template<typename T>
void de(T t) {cerr<<t<<endl;}
template<typename T, typename ...U>
void de(T t, U...u) {cerr<<t<<", ", de(u...);}
#else
#define dbg(...)
#define endl "\n"
#endif
 
void usaco(string s) {
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt; cin>>tt;
    while(tt--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int x=0;
        for(int i=0; i<n; i++) x^=a[i];
        if(x) {
            cout<<"first"<<endl;
        } else {
            cout<<"second"<<endl;
        }
    }
    return 0;
}
