#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e4;

int ch[mxN+1][26], nxt[mxN+1], cnt[mxN+1], idx;

void init() {
    idx=0;
    memset(ch, 0, sizeof(ch));
    memset(nxt, 0, sizeof(nxt));
    memset(cnt, 0, sizeof(cnt));
}

void add(string s) {
    int p=0;
    for(char c:s) {
        if(!ch[p][c-'a']) ch[p][c-'a']=++idx;
        p=ch[p][c-'a'];
    }
    cnt[p]++;
}

void build() {
    queue<int> q;
    for(int i=0; i<26; i++) {
        if(ch[0][i]) q.push(ch[0][i]);
    }
    while(q.size()) {
        int v=q.front(); q.pop();
        for(int i=0; i<26; i++) {
            int u=ch[v][i];
            if(u) {
                q.push(u);
                nxt[u]=ch[nxt[v]][i];
            } else {
                ch[v][i]=ch[nxt[v]][i];
            }
        }
    }
}

int qry(string s) {
    int ans=0, now=0;
    for(char c:s) {
        now=ch[now][c-'a'];
        for(int i=now; i&&~cnt[i]; i=nxt[i]) {
            ans+=cnt[i];
            cnt[i]=-1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        init();
        int n; cin>>n;
        for(int i=0; i<n; i++) {
            string s; cin>>s;
            add(s);
        }
        build();
        string ss; cin>>ss;
        cout<<qry(ss)<<"\n";
    }
    return 0;
}
