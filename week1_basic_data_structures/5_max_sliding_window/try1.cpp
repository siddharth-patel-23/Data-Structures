#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	cin>>m;
	deque<int> dq;
	for (i=0;i<m;i++)
	{
	    while(!dq.empty() && v[i]>=v[dq.back()])
	        dq.pop_back();
	    dq.push_back(i);
	}
	while(i<n)
	{
	    cout<<v[dq.front()]<<" ";
	    
	    while(!dq.empty() && dq.front()<=i-m)
	        dq.pop_front();
	    
	    while(!dq.empty() && v[i]>=v[dq.back()])
	        dq.pop_back();
	  
	    dq.push_back(i);
	    i++;
	}
	cout<<v[dq.front()]<<" ";
	return 0;
}
