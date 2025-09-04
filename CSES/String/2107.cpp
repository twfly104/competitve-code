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
    string s; cin>>s;
    vector<int> pi(sz(s)), z(sz(s));
    for(int i=0, l=0, r=0; i<sz(s); i++) {
        if(i<=r) z[i]=min(r-i+1, z[i-l]);
        while(i+z[i]<sz(s)&&s[i+z[i]]==s[z[i]]) {
            z[i]++;
            l=i;
            r=i+z[i]-1;
        }
    }
    for(int i=1, j=0; i<sz(s); i++) {//i=1
        while(j&&s[j]!=s[i]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    for(int i=0; i<sz(s); i++) {
        cout<<z[i]<<' ';
    }
    cout<<endl;
    for(int i=0; i<sz(s); i++) {
        cout<<pi[i]<<' ';
    }
    return 0;
}
