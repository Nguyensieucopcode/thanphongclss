#include<bits/stdc++.h>

using namespace std;

#define int long long 

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	#define task "subseq"
	if (fopen(task".inp","r"))
	{
		(void)freopen(task".inp","r",stdin);
		(void)freopen(task".out","w+",stdout);
	}
	int n,l,r; cin>>n>>l>>r;
	int arr[n+7];
	for (int i=1; i<=n; i++) cin>>arr[i];
	
	sort(arr+1,arr+n+1,less<int>());
	int dp[n+7][r+8];memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=1 ; i<=n; i++)
	{
		dp[i][0]=1;
		for (int j=1; j<=r; j++)
		{
			if (j>=arr[i]) dp[i][j]=dp[i-1][j-arr[i]];
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	int ans =0;
	for (int i=l; i<=r ;i++) if (dp[n][i]) ans ++;
	cout<<ans;
}
