#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
 
const int mod=1e9+7;
 
struct mat {
    ll a[6][6];
    mat() {
        memset(a, 0, sizeof(a));
    }
    mat operator*(mat b) {
        mat c;
        for(int i=0; i<6; i++) {
            for(int j=0; j<6; j++) {
                for(int k=0; k<6; k++) {
                    c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j])%mod;
                }
            }
        }
        return c;
    }
};
 
mat f(mat a, ll k) {
    mat res;
	res.a[5][0]=1;
    while(k) {
        if(k&1) {
            res=a*res;
        }
        a=a*a;
        k/=2;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    mat s;
    s.a[0][1]=1;
    s.a[1][2]=1;
    s.a[2][3]=1;
    s.a[3][4]=1;
    s.a[4][5]=1;
	for(int i=0; i<6; i++) {
		s.a[5][i]=1;
	}
    mat ans=f(s, n+5);
    cout<<ans.a[0][0];
    return 0;
}
