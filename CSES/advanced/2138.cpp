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

const int mxN=5e4;

vector<int> adj[mxN];
int deg[mxN];
bitset<50000> b[mxN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	for(int i=0; i<n; i++) b[i].set(i);
	for(int i=0; i<m; i++) {
		int a, b; cin>>a>>b;
		--a, --b;
		deg[a]++;
		adj[b].push_back(a);
	}
	queue<int> q;
	for(int i=0; i<n; i++) {
		if(!deg[i]) {
			q.push(i);
		}
	}
	while(sz(q)) {
		int x=q.front();
		q.pop();
		for(int y : adj[x]) {
			b[y]|=b[x];
			if(--deg[y]==0) {
				q.push(y);
			}
		}
	}
	for(int i=0; i<n; i++) {
		cout<<b[i].count()<<' ';
	}
    return 0;
}
