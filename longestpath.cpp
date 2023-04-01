/* Copcode hết đấy :v
   Mơ mà tự code à, lêu lêu */

#include<bits/stdc++.h>

using namespace std;

#define int long long 
const int N = 1e5+7;
typedef vector <int> v;
vector < v > a(N);
int ans[N+7];

int traces(int x)
{
    if (ans[x]!=0) return ans[x];
    for (int i = 0; i < a[x].size(); i++)
    {
        int k = a[x][i];
        ans[x] = max(ans[x] , traces(k)+1);
    }
    return ans[x];
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);
    #define task "longest"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,m; cin>>n>>m;
    memset(ans,0,sizeof(ans));
    while (m--)
    {
        int u,v; cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        traces(i);
    }
    sort(ans+1,ans+n+1,greater<int>());
    cout<<ans[1];
}
