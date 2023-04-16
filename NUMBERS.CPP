#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "NUMBERS"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    int n,m; cin>>n>>m; n=n+m;
    int x=n-(n&1),y=n-(n&0);
    int sl=(x-1)/2+1,sc=y/2+1;
    cout<<(sl/2)*sc+sc/3;
}
