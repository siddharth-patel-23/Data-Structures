#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n);
	int root;
	for (i=0;i<n;i++) 
	{
	    cin>>v[i];
	    if (v[i]==-1) root=i;
	}
	int ans=0;
	
	for (i=0;i<n;i++)
	{
	        int cnt=1;
	        int j=i;
	        while(v[j]!=root and v[j]!=-1)
	        {
	            cnt+=2;
	            j=v[v[j]];
	        }
	        if (v[j]==root) cnt++; 
	        ans=max(ans, cnt);
	}
	cout<<ans;
	
	return 0;
}
