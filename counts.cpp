#include<bits/stdc++.h>

using namespace std;

#define int long long 
int n,ans;
const int N = 55+7;
int f[N+7];

bool check(string s)
{
    for (int i=0; i<s.size(); i++) if (s[i]=='1' && s[i-1]=='1') return 1; 
    return 0;
}

void dq(int id, string s)
{
    if (id==n+1) 
    {
        ans+=check(s); return;
    }
    dq(id+1,s+'0'); dq(id+1,s+'1');
}

int binpow(int a, int b)
{
    if (b==1) return a;
    int k = binpow(a,b/2);
    if (b%2==0) return k*k;
    return k*k*a;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "main"
    if (fopen(task".inp","r"))
    {
        (void)freopen(task".inp","r",stdin);
        (void)freopen(task".out","w+",stdout);
    }
    cin>>n; ans=0;
    memset(f,0,sizeof(f));
    f[1]=2,f[2]=3;
    if (n<=2) 
    {
        cout<<binpow(2,n)-f[n]; return 0;
    }
    for (int i=3; i<=n; i++) f[i]=f[i-1]+f[i-2];
    cout<<binpow(2,n)-f[n];
}
