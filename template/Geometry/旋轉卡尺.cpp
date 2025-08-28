//https://open.kattis.com/problems/roberthood
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

double dist(pdd x, pdd y) {
    return sqrt((x.ff-y.ff)*(x.ff-y.ff)+(x.ss-y.ss)*(x.ss-y.ss));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
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
    if(n==2) {
        cout<<fixed<<setprecision(10)<<dist(stk[1], stk[0])<<endl;
        return 0;
    }
    int siz=sz(stk);
    for(int i=0; i<n; i++) {
        while(sz(stk)>siz&&cross(stk.back()-stk[sz(stk)-2], p[i]-stk.back())<=0) {
            stk.pop_back();
        }
        stk.push_back(p[i]);
    }
    stk.pop_back();
    n=sz(stk);
    double res=0;
    for(int i=0, j=1; i<n; i++) {
        while(cross(stk[(i+1)%n]-stk[i], stk[j]-stk[i])<cross(stk[(i+1)%n]-stk[i], stk[(j+1)%n]-stk[i])) {//注意是>不行為>=，不然會退到O(n^2)
            j=(j+1)%n;
        }
        res=max({res, dist(stk[i], stk[j]), dist(stk[i+1], stk[j])});
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
    return 0;
}
