#include <bits/stdc++.h>
using namespace std;

struct st
{
    int k, l, r;
};

void inorder(vector<st> v, int i, long long int &pre, bool &f)
{
    if (v[i].l!=-1) inorder(v, v[i].l, pre, f);
    // cout<<pre<<" "<<key[i]<<"\n";
    if (pre>v[i].k)
    {
        f=true;
        return;
    }
    pre=v[i].k;
    if (v[i].r!=-1) inorder(v, v[i].r, pre, f);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
// 	vector<int> left(n), right(n), key(n);
// 	vector<int> check;
vector<st> v(n);
	for (i=0;i<n;i++)
	{
	    cin>>v[i].k>>v[i].l>>v[i].r;
	}
	
	bool f=false;
	if (n>0)
	{
	    long long int pre=LONG_MIN;
	    inorder(v, 0, pre, f);
	}
	if (!f) cout<<"CORRECT\n";
	else cout<<"INCORRECT\n";
	return 0;
}
