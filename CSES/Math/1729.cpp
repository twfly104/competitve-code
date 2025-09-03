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

int p[100], sg[1000001];
int n, k;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);    
    cin>>n>>k;
    for(int i=0; i<k; i++) {
        cin>>p[i];
    }
    sg[0]=0;
    for(int i=1; i<=n; i++) {
        bitset<101> vis;
        for(int j=0; j<k; j++) {
            if(i-p[j]>=0) {
                vis[sg[i-p[j]]]=1;
            } 
        }
        for(int j=0; ; j++) {
            if(!vis[j]) {
                sg[i]=j;
                break;
            }
        }
        if(sg[i]) {
            cout<<"W";
        } else {
            cout<<"L";
        }
    }
    return 0;
}
