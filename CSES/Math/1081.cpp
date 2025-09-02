#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
 
const int mxX=1e6;
 
int cnt[mxX+1];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }
    for(int i=mxX; i>=0; i--) {
        int cnt1=0;
        for(int j=i; j<=mxX; j+=i) {
            cnt1+=cnt[j];
        }
        if(cnt1>=2) {
            cout<<i;
            break;
        }
    }
    return 0;
}
