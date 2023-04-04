#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int N = 1e2+7;
int a1[4]={-1,0,1,0};
int a2[4]={0,-1,0,1};
int h[N+7][N+7],l[N+7][N+7],f[N+7][N+7],ans[N+7],n,m,k,dem,ps1,ps2;

void read_input(int n, int m)
{
	for (int i=1; i<=n; i++) 
	{
		for (int j=1; j<=m; j++) cin>>h[i][j];
	}
	k=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++) 
		{
			cin>>l[i][j];
			if (l[i][j]) 
			{
				ps1=i,ps2=j; k++;
			}
		}
	}
}

void dfs(int x, int y, int last, int val)
{
	if (x<=0 || x>n || y<=0 || y>m) return ;
	if (f[x][y]) return ;
	if (abs(h[x][y] - last) > val) return ;
	if (l[x][y]==1) 
	{
		dem++;
	}
	f[x][y]=1;
	for (int i=0; i<4; i++)  
	{
		int u=x+a1[i],v=y+a2[i];
		dfs(u,v,h[x][y],val);
	}
}

bool check(int val)
{
	dem=0;
	memset(f,0,sizeof(f));
	dfs(ps1,ps2,h[ps1][ps2],val);
	return dem==k;
}

void solve()
{
	int l=1,r=(int)1e9+7,ans=(int)1e10;
	while (l<=r)
	{
		int g = (l+r) >> 1;
		if (check(g))
		{
			ans=min(ans,g); r=g-1;
		}
		else l=g+1;
	}
	cout<<ans<<"\n";
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
    cin>>n>>m;
    read_input(n,m);
    solve();
}
