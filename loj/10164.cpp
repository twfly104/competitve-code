#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[32][10][2][2], a[32];

int dfs(int pos, int pre, int lead, int lim) {
	if(pos==-1) return 1;
	if(~dp[pos][pre][lead][lim]) return dp[pos][pre][lead][lim];
	int ans=0;
	int x=(lim ? a[pos] : 9);
	for(int i=0; i<=x; i++) {
		if(i==0&&lead) {
			ans+=dfs(pos-1, 0, 1, 0);
			continue;
		}
		if(pre>i) continue;
		ans+=dfs(pos-1, i, 0, lim&&(i==a[pos]));
	}
	return ans;
}

int solve(int x) {
	int cnt=0;
	while(x) {
		a[cnt++]=x%10;
		x/=10;
	}
	return dfs(cnt-1, 0, 1, 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b;
	memset(dp, -1, sizeof(dp));
	while(cin>>a>>b) {
		cout<<solve(b)-solve(a-1)<<"\n";
	}
	return 0;
}
