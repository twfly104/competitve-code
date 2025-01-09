#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e6;
ll t[mxN*4+1], add[mxN*4+1];

void push_up(int idx) {
	t[idx]=t[idx*2]+t[idx*2+1];
}

void push_down(int len, int idx) {
	if(add[idx]) {
		t[idx*2]+=add[idx]*(len-len/2);
		t[idx*2+1]+=add[idx]*(len/2);
		add[idx*2]+=add[idx];
		add[idx*2+1]+=add[idx];
		add[idx]=0;
	}
}

void build(int l, int r, int idx) {
	if(l==r) {
		cin>>t[idx];
		return;
	}
	int mid=(l+r)/2;
	build(l, mid, idx*2);
	build(mid+1, r, idx*2+1);
	push_up(idx);
}

void upd(int a, int b, int c, int l, int r, int idx) {
	if(a<=l&&r<=b) {
		add[idx]+=c;
		t[idx]+=1ll*c*(r-l+1);//notice adding 1ll
		return;
	}
	push_down(r-l+1, idx);
	int mid=(l+r)/2;
	if(a<=mid) upd(a, b, c, l, mid, idx*2);
	if(mid<b) upd(a, b, c, mid+1, r, idx*2+1);
	push_up(idx);
}

ll qry(int a, int b, int l, int r, int idx) {
	if(a<=l&&r<=b) {
		return t[idx];
	}
	push_down(r-l+1, idx);
	int mid=(l+r)/2;
	ll ans=0;
	if(a<=mid) ans+=qry(a, b, l, mid, idx*2);
	if(mid<b) ans+=qry(a, b, mid+1, r, idx*2+1);
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q; cin>>n>>q;
	build(1, n, 1);
	while(q--) {
		int ty; cin>>ty;
		if(ty==1) {
			int l, r, x; cin>>l>>r>>x;
			upd(l, r, x, 1, n, 1);
		} else {
			int l, r; cin>>l>>r;
			cout<<qry(l, r, 1, n, 1)<<"\n";
		}
	}
	return 0;
}
