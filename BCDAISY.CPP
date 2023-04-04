#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 257;
vector< vector<int> > a(N);
bool f[N+7];

void dfs(int p)
{
    if (f[p]==1) return;
    f[p]=1;
    for (int i=0; i<a[p].size(); i++)
    {
        int k=a[p][i];
        dfs(k);
    }
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);
    #define task "BCDAISY"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,m; cin>>n>>m;
    memset(f,0,sizeof(f));
    while (m--)
    {
        int u,v; cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    vector<int> v;
    for (int i=1; i<=n; i++) if (!f[i]) v.push_back(i);
    if (v.size()==0) v.push_back(0);
    for (int i=0; i<v.size(); i++) cout<<v[i]<<'\n';
}
