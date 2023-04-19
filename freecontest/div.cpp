#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fill(x,y) memset(x,y,sizeof(x))
const int N = 1e6+7;
int pre[N+7],arr[N+7];

void sieve(int l, int r)
{
    for (int i=1 ;i<=trunc(sqrt(r)); i++)
    {
        int k=i*i;
        if (k<l) k=((l-1)/i+1)*i;
        else pre[k-l]+=i,k+=i;
        for (k; k<=r; k+=i) pre[k-l]+=i+k/i;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("main.inp","r",stdin);
    freopen("main.out","w+",stdout);
    int n; cin>>n;
    int l=(int)1e18,r=-(int)1e18;
    for (int i=1; i<=n; i++) cin>>arr[i];
    for (int i=1 ;i<=n; i++) l=min(l,arr[i]),r=max(r,arr[i]);
    sieve(l,r);
    for (int i=1 ;i<=n; i++) cout<<pre[arr[i]-l]<<' ';
}

/* sàng nguyên tố + duyệt nguyên tố thưởng -> áp dụng dựa trên n<=1e6 và dãy liên tục */
