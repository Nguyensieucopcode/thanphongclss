#include<bits/stdc++.h>

using namespace std;

#define int long long
#define base 31
const int maxn = 1e6+7;
const int mod = 1e9+7;
int hasht[maxn+7],hasht1[maxn+7],p[maxn+7],n;

int get1(int i, int j)
{
    return (hasht[j] - hasht[i-1]*p[j-i+1] + mod * mod ) % mod;
}

int get(int i, int j)
{
    return (hasht1[j] - hasht1[i-1]*p[j-i+1] + mod * mod ) % mod;
}

bool check(int length)
{
    int ss = length >> 1;
    int l = l + ss -1;
    length = n - length ;
    if (get1(1,ss) == get(length,length+ss-1)) return 1;
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "bai4"
    if (fopen(task".inp","r"))
    {
        (void)!freopen(task".inp","r",stdin);
        (void)!freopen(task".out","w+",stdout);
    }
    string s; cin>>s;
    s=' '+s; n = s.size()-1;
    memset(p,0,sizeof(p)); memset(hasht,0,sizeof(hasht)); memset(hasht1,0,sizeof(hasht1));
    p[0]=1;
    for (int i=1; i<=n; i++) p[i]=(p[i-1]*base)%mod;
    for (int i=1; i<=n; i++) hasht[i]=(hasht[i-1]*base + s[i] - 'a' + 1) % mod;
    reverse(s.begin(),s.end());
    for (int i=1 ;i<=n; i++) hasht1[i]=(hasht1[i-1]*base + s[i] - 'a' + 1) % mod;
    int ans = 2*n-1;
    for (int g=1; g<=n; g++)
    {
        if (check(g))
        {
            ans = min(ans, n + (n-g) );
        }
    }
    cout<<ans;
}
