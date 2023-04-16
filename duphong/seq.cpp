#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5+7;
#define all(x) x.begin(),x.end()
#define fill(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)


signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "main"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,k; cin>>n>>k;
    int arr[n+7],pre[n+7],ss[n+7];
    fill(arr,0); fill(pre,(int)1e9+7);
    for (int i=1; i<=n; i++) cin>>arr[i];
    vector <pair<int,int> > v;
    for (int i=1; i<=n; i++) arr[i]=arr[i-1]+arr[i];
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if ( (arr[j]-arr[i-1]) / (j-i+1) >= k) ans=max(ans,j-i+1);
        }
    }
    cout<<ans;
}



