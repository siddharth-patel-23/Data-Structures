#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<long long int> &v, long long int n, long long int id, vector<pair<long long int, long long int>> &ans)
{
    while(id<n)
    {
        long long int l=2*id+1, r=2*id+2, tmp=id;
        if (l<n && v[id]>v[l])
        id=l;
        if (r<n && v[id]>v[r])
        id=r;
        if (id!=tmp)
        swap(v[id], v[tmp]), ans.push_back(make_pair(tmp, id));
        else return;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int n, i;
	cin>>n;
	vector<long long int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	vector<pair<long long int, long long int>> ans;
	for (i=((n/2)-1);i>=0;i--)
	{
	    heapifyDown(v, n, i, ans);
	}
	int sz=ans.size();
	cout<<sz<<"\n";
	for (i=0;i<sz;i++)
	cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}
