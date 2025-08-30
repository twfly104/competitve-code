mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
ll rng() {return uniform_int_distribution<ll>(1, 1e18)(mt);}
 
const int mxN=2e5;
 
struct TREAP {
    int l=0, r=0;
    int siz=0;
    char val;
    int pri;
} t[mxN+1];
 
int tot=0, rt=0;
 
void newNode(int &idx, char v) {
    idx=++tot;
    t[idx].pri=rng()%1000000000;
    t[idx].val=v;
    t[idx].siz=1;
}
 
void psh(int idx) {
    t[idx].siz=1+t[t[idx].l].siz+t[t[idx].r].siz;
}
 
void split_val(int idx, int v, int &x, int &y) {
    if(!idx) {
        x=y=0;
        return;
    }
    if(t[idx].val<=v) {
        x=idx;
        split_val(t[idx].r, v, t[idx].r, y);
    } else {
        y=idx;
        split_val(t[idx].l, v, x, t[idx].l);
    }
}
 
void split_siz(int idx, int v, int &x, int &y) {
    if(!idx) {
        x=y=0;
        return;    
    }
    if(v>=t[t[idx].l].siz+1) {
        x=idx;
        split_siz(t[idx].r, v-t[t[idx].l].siz-1, t[idx].r, y);
    } else {
        y=idx;
        split_siz(t[idx].l, v, x, t[idx].l);
    }
    psh(idx);
}
 
int merge(int x, int y) {
    if(!x||!y) return (x?x:y);
    if(t[x].pri<t[y].pri) {
        t[x].r=merge(t[x].r, y);
        psh(x);
        return x;
    } else {
        t[y].l=merge(x, t[y].l);
        psh(y);
        return y;
    }
}
