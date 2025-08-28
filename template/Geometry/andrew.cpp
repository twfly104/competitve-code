//https://open.kattis.com/problems/convexhull
#define pdd pair<double, double>

pdd operator+(pdd x, pdd y) {
    return {x.ff+y.ff, x.ss+y.ss};
}

pdd operator-(pdd x, pdd y) {
    return {x.ff-y.ff, x.ss-y.ss};
}

double cross(pdd x, pdd y) {
    return x.ff*y.ss-x.ss*y.ff;
}

void solve(int n) {
    vector<pdd> p(n);
    for(int i=0; i<n; i++) {
        cin>>p[i].ff>>p[i].ss;
    }
    sort(all(p), [&](auto x, auto y) {
        if(x.ff==y.ff) return x.ss<y.ss;
        else return x.ff<y.ff;
    });
    p.erase(unique(p.begin(), p.end()), p.end());
    n=sz(p);
    vector<pdd> stk;
    for(int i=0; i<n; i++) {
        while(sz(stk)>1&&cross(stk.back()-stk[sz(stk)-2], p[i]-stk.back())<=0) {
            stk.pop_back();
        }
        stk.push_back(p[i]);
    }
    reverse(all(p));
    int siz=sz(stk);
    for(int i=0; i<n; i++) {
        while(sz(stk)>siz&&cross(stk.back()-stk[sz(stk)-2], p[i]-stk.back())<=0) {
            stk.pop_back();
        }
        stk.push_back(p[i]);
    }
    stk.pop_back();
    cout<<sz(stk)<<endl;
    for(int i=0; i<sz(stk); i++) {
        cout<<stk[i].ff<<' '<<stk[i].ss<<endl;
    }
}
