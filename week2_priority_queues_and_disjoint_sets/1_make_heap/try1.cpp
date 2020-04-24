#include <bits/stdc++.h>
using namespace std;

void moveDown(vector<long long int> &v, long long int id, long long int n, vector<pair<long long int, long long int>> &ans)
{
    while((2*id+1)<n && (2*id+2)<n && v[id]>v[2*id+1] && v[id]>v[2*id+2])
    {
        if (v[2*id+1]<v[2*id+2])
        {
	        swap(v[2*id+1], v[id]); 
	       
	        ans.push_back(make_pair(id, 2*id+1));
	       
	        id=2*id+1;
        }
	    else 
	    {
	        swap(v[2*id+2], v[id]);
	       
	        ans.push_back(make_pair(id, 2*id+2));
	       
	        id=2*id+2;
	    }
    }
    while ((2*id+1)<n && v[id]>v[2*id+1])
	{
        swap(v[2*id+1], v[id]);
        
        ans.push_back(make_pair(id, 2*id+1));
        
        id=2*id+1;
	}
	while ((2*id+2)<n && v[id]>v[2*id+2])
	{
	    swap(v[2*id+2], v[id]);
	   
	    ans.push_back(make_pair(id, 2*id+2));
	   
	    id=2*id+2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int n, i;
	cin>>n;
	vector<long long int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	long long int cnt=0;
	vector<pair<long long int, long long int>> ans;
	for (i=n/2;i>=0;i--)
	{ 
	    moveDown(v, i, n, ans);
	}
	long long int sz=ans.size();
	cout<<sz<<"\n";
	for (i=0;i<sz;i++)
	cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}
