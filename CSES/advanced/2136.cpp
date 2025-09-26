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
    int n, k; cin>>n>>k;
	vector<int> a(n);
    for(int i=0; i<n; i++) {
    	string s; cin>>s;
    	for(int j=0; j<k; j++) {
    		if(s[j]=='1') a[i]|=1<<j;
		}
	}
	int ans=100;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			ans=min(ans, __builtin_popcount(a[i]^a[j]));
		}
	}
	cout<<ans<<endl;
    return 0;
}
