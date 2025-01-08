#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=100;

int n, trie[mxN][2], endd[mxN], node=0;
string s;
bool check=0;

void init() {
    memset(trie, 0, sizeof(trie));
    memset(endd, 0, sizeof(endd));
    node=0;
    check=0;
}

void add(string s) {
    int now=0;
    for(int i=0; i<s.size(); i++) {
        int x=(s[i]=='1');
        if(trie[now][x]==0) {
            trie[now][x]=++node;
        } else {
            if(endd[trie[now][x]]) {
                check=1;
                break;
            } else if (i==s.size()-1) {
                check=1;
                break;
            }
        }
        now=trie[now][x];           
    }
    endd[now]=1;
}          
			          
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t=0;
    while(cin>>s) {
        if(s=="9") {
            if(!check) {
                cout<<"Set "<<++t<<" is immediately decodable"<<endl;
            } else {
                cout<<"Set "<<++t<<" is not immediately decodable"<<endl;
            }
            init();
            continue;
        }
        add(s);
    }
    return 0;
}
