#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<pair<long long int, long long int>> &v, int n, int id)
{
    while(id<n)
    {
        long long int l=2*id+1, r=2*id+2, tmp=id;
        if (l<n && v[id].first>v[l].first)
        id=l;
        if (r<n && v[id].first>v[r].first)
        id=r;
        if (id!=tmp)
        swap(v[id], v[tmp]);
        else return;
    }
    
}

void reHeapify(vector<pair<long long int, long long int>> &v, int n, int dup)
{
    while(dup<n)
    {
        long long int l=2*dup+1, r=2*dup+2, tmp=v[dup].second;
        if (l<n && v[dup].first==v[l].first && v[dup].second>v[l].second)
        {
            long long int tmp1=v[dup].second;
            v[dup].second=v[l].second;
            v[l].second=tmp1;
        }
        if (r<n && v[dup].first==v[r].first && v[dup].second>v[r].second)
        {
            long long int tmp2=v[dup].second;
            v[dup].second=v[r].second;
            v[r].second=tmp2;   
        }
        if (v[dup].second==tmp) {
        // {    cout<<tmp<<" ok \n";
            return; }
    }
}

void build_heap(vector<pair<long long int, long long int>> &v, int n)
{
    for (int i=n/2-1;i>=0;i--)
    {
        heapifyDown(v, n, i);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int t, n, m, i, ip;
	cin>>n>>m;
	vector<pair<long long int, long long int>> v;
	for (i=0;i<min(n, m);i++)
	{
	    cin>>ip;
	    v.push_back(make_pair(ip, i));
	}
	
	for (i=0;i<min(m, n);i++)
	cout<<i<<" "<<0<<"\n";
	
	if (m>n)
	{
	    build_heap(v, n);
	    bool f=true;
	    for (i=n;i<m;i++)
	    {
	        cin>>ip;
	        
	        cout<<v[0].second<<" "<<v[0].first<<"\n";
	        v[0].first+=ip;
	        heapifyDown(v, n, 0);
	        if (f)
	        for (int j=n/2-1;j>=0;j--)
	        reHeapify(v, n, j);
	        else
	        reHeapify(v, n, 0), f=false;
	    }
	}
	return 0;
}
