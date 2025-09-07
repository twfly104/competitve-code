struct SA {
    string s;
    vector<pair<pair<int, int>, int>> suf;
    vector<int> lcp;
    SA(string _s) : s(_s+'$') {
        suf.resize(sz(s));
        lcp.resize(sz(s));
    }
    void radix_sort(vector<pair<pair<int, int>, int>> &suf) {
        for(int i=0; i<2; i++) {
            auto get=[&](auto x) -> int {
                if(i==0) return x.ff.ss;
                else return x.ff.ff;
            };
            int mx=0;
            for(int i=0; i<sz(suf); i++) {
                mx=max(mx, get(suf[i]));
            }
            vector<int> cnt(mx+1);
            for(int i=0; i<sz(suf); i++) {
                cnt[get(suf[i])]++;
            }
            for(int i=1; i<=mx; i++) {
                cnt[i]+=cnt[i-1];
            }
            vector<pair<pair<int, int>, int>> res(sz(suf));
            for(int i=sz(suf)-1; i>=0; i--) {
                res[--cnt[get(suf[i])]]=suf[i];
            }
            suf=res;
        }
    }   
    void sa() {
        s+='$';
        for(int i=0; i<sz(s); i++) {
            suf[i]={{s[i], 0}, i};
        }
        sort(all(suf));
        vector<int> rk(sz(s));
        for(int i=1; i<sz(s); i++) {
            auto [x, y]=suf[i-1];
            auto [x1, y1]=suf[i];
            rk[y1]=rk[y]+(x1>x);
        }
        for(int k=1; k<sz(s); k*=2) {
            for(auto &[x, y] : suf) {
                x={rk[y], rk[(y+k)%sz(s)]};
            }
            radix_sort(suf);
            for(int i=1; i<sz(s); i++) {
                auto [x, y]=suf[i-1];
                auto [x1, y1]=suf[i];
                rk[y1]=rk[y]+(x1>x);
            }    
        }
        for(int i=0, k=0; i<sz(s); i++) {
            if(k) k--;
            if(!rk[i]) continue;
            int j=suf[rk[i]-1].ss;
            while(s[i+k]==s[j+k]) k++;
            lcp[rk[i]]=k;
        }
    }
};
