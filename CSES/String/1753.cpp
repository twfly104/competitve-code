#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
 
#define ull unsigned long long
 
const int mxN=1e6, P=1e9+7, P1=1e9+9;
 
ull base=131;
ull b[mxN+1], b1[mxN+1], p[mxN+1], p1[mxN+1];
string s, s1;
 
void f() {//hashing 1
    for(int i=0; i<s.size(); i++) {
        p[i+1]=(p[i]*base+s[i]-'a')%P;
    }
}
 
void f1() {//hashing 2
    for(int i=0; i<s.size(); i++) {
        p1[i+1]=(p1[i]*base+s[i]-'a')%P1;
    }
}
 
pair<ull, ull> init() {
    ull val=0, val1=0;
    for(int i=0; i<s1.size(); i++) val=(val*base+s1[i]-'a')%P, val1=(val1*base+s1[i]-'a')%P1;
    f();
    f1();
    return {val, val1};
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    b[0]=1;
    b1[0]=1;
    for(int i=1; i<=mxN; i++) {
        b[i]=b[i-1]*base%P;
        b1[i]=b1[i-1]*base%P1;
    }
    cin>>s>>s1;
    ull len1=s1.size();
    pair<ull, ull> h=init();
    int ans=0;
    for(int i=len1; i<=s.size(); i++) {
        if(h==make_pair(((p[i]-p[i-len1]*b[len1]%P)+P)%P,((p1[i]-p1[i-len1]*b1[len1]%P1)+P1)%P1)) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
