//1-based
struct HLD {
    vector<vector<int>> adj;
    vector<int> fat, dep, son, top, siz, id, rid;
    vector<ll> t, t1, tag, a;
    int n;
    int now=0;
    HLD(int _n) : n(_n), adj(_n+1), fat(_n+1), dep(_n+1), son(_n+5), top(_n+1), siz(_n+1), id(_n+1), rid(_n+1), t(_n*4+1), t1(_n*4+1), tag(_n*4+1), a(_n+1) {}
    void add(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void dfs(int v, int fa) {
        dep[v]=dep[fa]+1;
        fat[v]=fa;
        siz[v]=1;
        for(int u : adj[v]) {
            if(u==fa) continue;
            dfs(u, v);
            siz[v]+=siz[u];
            if(siz[son[v]]<siz[u]) {
                son[v]=u;
            }
        }
    }
    void dfs1(int v, int tp) {
        top[v]=tp;
        id[v]=++now;
        rid[now]=v;
        if(son[v]) {
            dfs1(son[v], tp);
        }
        for(int u : adj[v]) {
            if(u==son[v]||u==fat[v]) continue;
            dfs1(u, u);
        }
    }
    void psh(int idx) {
        t[idx]=t[idx*2]+t[idx*2+1];
        t1[idx]=max(t1[idx*2], t1[idx*2+1]);
    }
    void app(int idx, int val, int len) {
        t[idx]=val*len;
        t1[idx]=val;
        tag[idx]=val;
    }
    void psd(int idx, int l, int r) {
        if(tag[idx]) {
            int mid=(l+r)/2;
            app(idx*2, tag[idx], mid-l+1);    
            app(idx*2+1, tag[idx], r-mid);
            tag[idx]=0;
        }
    }
    void build(int idx, int l, int r) {
        if(l==r) {
            t[idx]=t1[idx]=a[rid[l]];
            return;
        }
        int mid=(l+r)/2;
        build(idx*2, l, mid);
        build(idx*2+1, mid+1, r);
        psh(idx);
    } 
    void upd(int idx, int l, int r, int val, int L, int R) {
        if(l<=L&&R<=r) {
            app(idx, val, R-L+1);
            return;
        }
        psd(idx, L, R);
        int mid=(L+R)/2;
        if(l<=mid) upd(idx*2, l, r, val, L, mid);
        if(mid<r) upd(idx*2+1, l, r, val, mid+1, R);
        psh(idx);
    }
    int qry(int idx, int l, int r, int L, int R) {
        if(l<=L&&R<=r) {
            return t[idx];
        }
        psd(idx, L, R);
        int mid=(L+R)/2;
        int res=0;
        if(l<=mid) res+=qry(idx*2, l, r, L, mid);
        if(mid<r) res+=qry(idx*2+1, l, r, mid+1, R);
        return res;     
    }
    int qry1(int idx, int l, int r, int L, int R) {
        if(l<=L&&R<=r) {
            return t1[idx];
        }
        psd(idx, L, R);
        int mid=(L+R)/2;
        int res=-1e9;
        if(l<=mid) res=max(res, qry1(idx*2, l, r, L, mid));
        if(mid<r) res=max(res, qry1(idx*2+1, l, r, mid+1, R));
        return res;     
    }
    void upd_nd(int a, int val) {
        upd(1, id[a], id[a], val, 1, n);
    }
    int qry_sum(int a, int b) {
        int res=0;
        while(top[a]!=top[b]) {
            if(dep[top[a]]<dep[top[b]]) swap(a, b);
            res+=qry(1, id[top[a]], id[a], 1, n);
            a=fat[top[a]];
        }
        if(dep[a]<dep[b]) swap(a, b);
        res+=qry(1, id[b], id[a], 1, n);
        return res;
    }
    int qry_mx(int a, int b) {
        int res=-1e9;
        while(top[a]!=top[b]) {
            if(dep[top[a]]<dep[top[b]]) swap(a, b);
            res=max(res, qry1(1, id[top[a]], id[a], 1, n));
            a=fat[top[a]];
        }
        if(dep[a]<dep[b]) swap(a, b);
        res=max(res, qry1(1, id[b], id[a], 1, n));
        return res;
    }
};
