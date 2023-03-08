#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n,m,fa[N];

struct edge{
    int u,v,w;
    bool operator < (const edge &t) const {
        return w < t.w;
    }
}e[N];

int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int kruskal(){
    sort(e,e+m);
    for(int i = 1;i <= n;i++) fa[i] = i;
    int cnt = 0,ans = 0;
    for(int i = 0;i < m;i++){
        int u = find(e[i].u),v = find(e[i].v),w = e[i].w;
        if(u != v){
            fa[u] = v;
            cnt++,ans += w;
        }
        if(cnt == n-1) break;
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    printf("%d\n",kruskal());
    return 0;
}
