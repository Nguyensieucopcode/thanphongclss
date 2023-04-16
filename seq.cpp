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
    for (int i=1 ;i<=n; i++)
    {
        v.push_back({arr[i-1]-k*i,i});
    }
    sort(v.begin(),v.end(),[] (pair<int,int> x, pair<int,int> y)
         {
             return x.first < y.first || (x.first==y.first && x.second < y.second);
         });
    for (int i=0; i<v.size(); i++) pre[i+1]=min(pre[i],v[i].second);
    for (int i=0; i<v.size(); i++) ss[i+1]=v[i].first;
    pre[n+1]=pre[n]; ss[n+1]=(int)1e9+7; int ans=0;
    for (int i=1; i<=n; i++)
    {
        int x=arr[i]-k*i-k;
        int it=upper_bound(ss+1,ss+n+1,x)-ss-1;
        if (pre[it]<i) ans=max(ans,i-pre[it]+1);
    }
    cout<<ans;
}


