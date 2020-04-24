#include <bits/stdc++.h>
using namespace std;

void moveDown(vector<int> &v, int id, int n, vector<int> &ans1, vector<int> &ans2)
{
    while(v[id]>v[2*id+1] && v[id]>v[2*id+2] && (2*id+2)<n)
    {
        if (v[2*id+1]<v[2*id+2])
        {
	        swap(v[2*id+1], v[id]); 
	       
	        ans1.push_back(id);
	        ans2.push_back(2*id+1);
	       
	        id=2*id+1;
        }
	    else 
	    {
	        swap(v[2*id+2], v[id]);
	       
	        ans1.push_back(id);
	        ans2.push_back(2*id+2);
	       
	        id=2*id+2;
	    }
    }
    while (v[id]>v[2*id+1] && (2*id+1)<n)
	{
        swap(v[2*id+1], v[id]);
        
        ans1.push_back(id);
	    ans2.push_back(2*id+1);
        
        id=2*id+1;
	}
	while (v[id]>v[2*id+2] && (2*id+2)<n)
	{
	    swap(v[2*id+2], v[id]);
	   
	    ans1.push_back(id);
	    ans2.push_back(2*id+2);
	   
	    id=2*id+2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	int cnt=0;
	vector<int> ans1, ans2;
	for (i=n/2;i>=0;i--)
	{ 
	    moveDown(v, i, n, ans1, ans2);
	}
	int sz=ans1.size();
	cout<<sz<<"\n";
	for (i=0;i<sz;i++)
	cout<<ans1[i]<<" "<<ans2[i]<<"\n";
	return 0;
}
