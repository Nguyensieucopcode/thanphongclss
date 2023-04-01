#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int N = 1e6+7;
int f[N+7];
typedef vector<int> v;
vector<v> a(N);

void traces(int id)
{
    cout<<id<<' ';
    f[id] = 1;
    for (int i = 0; i<a[id].size(); i++)
    {
    	int k = a[id][i];
    	if (f[k] == 0) traces(k);
    }
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    #define task "connect"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,m; cin>>n>>m;
    memset(f,0,sizeof(f));
    while (m--)
    {
        int u,v; cin>>u>>v; a[u].push_back(v);
    }
    for (int i=1; i<=n; i++)
    {
        if (f[i] == 0)
        {
            traces(i);   cout<<"\n";
        }
    }
}
