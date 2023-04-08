#include<bits/stdc++.h>

using namespace std;

#define int long long 

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	#define task "sumx"
	if (fopen(task".inp","r"))
	{
		(void)freopen(task".inp","r",stdin);
		(void)freopen(task".out","w+",stdout);
	}
	int n,k; cin>>n>>k;
	int arr[n+7];
	for (int i=1; i<=n; i++) cin>>arr[i];
	map<int,int> mp;
	int ans = 0;
	for (int i=1; i<=n; i++)
	{
		ans += mp[k-arr[i]];
		mp[arr[i]]++;
	}
	cout<<ans;
}
