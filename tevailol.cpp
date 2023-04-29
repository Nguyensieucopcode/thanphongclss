#include<bits/stdc++.h>

using namespace std;

#define int long long
#define base 31
const int maxn = 1e6+7;
const int mod = 1e9+7;
int f[maxn+7],hasht[maxn+7],hasht1[maxn+7],p[maxn+7],n,pos[maxn+7];

int get(int i, int j)
{
    return (hasht[j] % mod  - (hasht[i-1] * p[j-i+1]) % mod + mod*mod) % mod;
}

int get1(int i, int j)
{
    return (hasht1[j] % mod  - (hasht1[i-1] * p[j-i+1]) % mod + mod*mod) % mod;
}

int checking(int l, int r)
{
    int ss = (r-l+1) >> 1;
    int x = get(l,l+ss-1);
    int y = get1(pos[r],pos[r-ss+1]);
    return x==y;
}


bool check(int length)
{
    for (int i=1; i<=n-length+1; i++)
    {
        int l=i,r=i + length-1;
        if (checking(l,r)) return 1;
    }
    return 0;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "passw2"
    if (fopen(task".inp","r"))
    {
        (void)!freopen(task".inp","r",stdin);
        (void)!freopen(task".out","w+",stdout);
    }
    string s; cin >> s;
    string s1="";
    for (int i=s.size()-1; i>=0; i--) s1=s1+s[i];
    n = s.size(); s = ' ' + s;
    memset(p,0,sizeof(p)); memset(hasht,0,sizeof(hasht)); memset(hasht1,0,sizeof(hasht1));
    p[0] = 1;
    for (int i=1; i<=n; i++) p[i] = (p[i-1] * base ) % mod;
    for (int i=1; i<=n; i++) hasht[i] = (hasht[i-1] * base + s[i] -'A' + 1) % mod ;
    for (int i=1; i<=n; i++) pos[i] = n - i + 1;
    s1=' '+s1;
    for (int i=1; i<=n ;i++) hasht1[i] = (hasht1[i-1] * base + s1[i] - 'A' +1) % mod ;
    for (int g=n; g>=1; g--)
    {
        if (check(g))
        {
            cout<<g; return 0;
        }
    }
}



