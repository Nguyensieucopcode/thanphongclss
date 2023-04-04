#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fill(lt,x) memset(lt,x,sizeof(lt))
const int N = 3e5+7 , mod = 1000000007;
int arr[N+7],f[N+7];
vector< vector<int> > a(N),v(N);

void dfs(int id, int rt)
{
    if (f[id]) return;
    f[id]=1;
    v[rt].push_back(id);
    for (int i:a[id]) dfs(i,rt);
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);
    #define task "voi"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,m; cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>arr[i];
    while (m--)
    {
        int u,v; cin>>u>>v;
        a[u].push_back(v); a[v].push_back(u);
    }
    fill(f,0); int rt=0;
    for (int i=1; i<=n; i++)
    {
        if (f[i] == 0)
        {
            rt++; dfs(i,rt);
        }
    }
    int ans = 1, res = 0;
    for (int i=1; i<=rt; i++) 
    {
    	int mi = (int)1e10,tmp=0;
    	for (int j : v[i]) mi = min(mi,arr[j]);
    	res += mi;
    	for (int j : v[i]) tmp = (tmp % mod + (arr[j]==mi) % mod) % mod;
    	ans = ((ans % mod )* (tmp % mod))% mod;
	}
	cout<<res<<'\n'<<ans % mod ;
}
