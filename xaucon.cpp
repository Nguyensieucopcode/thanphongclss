#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e6+7;
int a[N+7],pres[N+7];

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "main"
    freopen(task".inp","r",stdin);
    freopen(task".out","w+",stdout);
    int n,k; cin>>k;
    memset(a,0,sizeof(a));
    memset(pres,0,sizeof(pres));
    string s; cin>>s; s=' '+s; n=s.size()-1;
    int ans=0,cnt=0;
    if (k==0)
    {
        int dm=1;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]=='0')
            {
                ans+=dm; dm++;
            }
            else dm=1;
        }
        cout<<ans; return 0;
    }
    int dm=0;
    for (int i=1; i<=n; i++)
    {
        if (s[i]=='0') dm++;
        else
        {
            int t=pres[cnt];
            pres[++cnt]=t+dm; dm=0;
        }
        if (i==n)
        {
            int t=pres[cnt];
            pres[++cnt]=t+dm; break;
        }
    }
    for (int i=k; i<cnt; i++)
    {
        int x=pres[i-k+1]-pres[i-k] , y = pres[i+1] - pres[i];
        ans++;
        ans+=x+y+x*y;
    }
    cout<<ans;
}
