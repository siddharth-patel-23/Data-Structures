#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n);
// 	hash(n);
	int root;
	for (i=0;i<n;i++) cin>>v[i];
	int ans=0;
	for (i=0;i<n;i++)
	{
	        int cnt=1;
	        int j=i;
	        while(v[j]!=-1)
	        {
	            cnt++;
	            j=v[j];
	        }
	        ans=max(ans, cnt);
	       // cout<<cnt<<" ";
	       // hash[i]=cnt;
	}
	cout<<ans<<"\n";
	
	return 0;
}
