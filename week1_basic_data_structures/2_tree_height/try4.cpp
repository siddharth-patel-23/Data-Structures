#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n), dp(n, 0), leaf(n,0), use;
	int root;
	
	for (i=0;i<n;i++) 
	{
	    cin>>v[i];
	    if (v[i]==-1) 
	    {
	        root=i;
	        continue;
	    }
	    leaf[v[i]]++;
	}
	for (i=0;i<n;i++) 
	{
	    if (leaf[i]==0) use.push_back(i);
	}
	int ans=0;
	
	for (i=0;i<use.size();i++)
	{
	        int cnt=1;
	        int j=use[i];
	       // cout<<j<<"\n";
	        while(v[j]!=-1 && dp[v[j]]<cnt)
	        {
	            dp[v[j]]=cnt;
	            cnt++;
	            j=v[j];
	        }
	       // cout<<cnt<<"\n";
	        ans=max(ans, cnt);
	}
	cout<<ans;
	
	return 0;
}
