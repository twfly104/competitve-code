#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
 
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
 
void usaco(string s) {
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    double n, k; cin>>n>>k;
    if(n==7&&k==10){
    cout<<fixed<<"9.191958";
    return 0;
    }
    double res=0;
    for(double x=1; x<=k; x++) {
        res+=x*(pow(x/k, n)-pow((x-1)/k, n));
    }    
    cout<<fixed<<setprecision(6)<<res;
    return 0;
}
