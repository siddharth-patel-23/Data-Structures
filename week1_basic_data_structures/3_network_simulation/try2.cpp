#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int s, n, i, tm=0;
	cin>>s>>n;
	queue<pair<int, int>> q;
// 	vector<int> ans(n);
	for (i=0;i<n;i++)
	{
	    int a, p, ans;
	    cin>>a>>p;
	    if (q.size()<s)
	    {
	        ans=max(tm, a);
	        tm=ans+p;
	        q.push({ans, p});
	    }
	    else
	    {
	        if (q.front().first+q.front().second<=a)
	        {
	            ans=max(tm, a);
	            tm=ans+p;
    	        q.pop();
    	        q.push({ans, p});
    	       // cout<<"ok ";
	        }
	        else
	        ans=-1;
	    }
	    cout<<ans<<"\n";
	    
	}
	return 0;
}
