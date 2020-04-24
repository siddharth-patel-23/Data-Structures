#include <bits/stdc++.h>
using namespace std;

void inorder(vector<int> left, vector<int> right, vector<int> key, int i, long long int &pre, bool &f)
{
    if (left[i]!=-1) inorder(left, right, key, left[i], pre, f);
    if (pre>key[i])
    {
        f=true;
        return;
    }
    pre=key[i];
    if (right[i]!=-1) inorder(left, right, key, right[i], pre, f);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> left(n), right(n), key(n);
// 	vector<int> check;
	for (i=0;i<n;i++)
	{
	    cin>>key[i]>>left[i]>>right[i];
	}
	
	bool f=false;
	if (n>0)
	{
	    long long int pre=key[0]-1;
	    inorder(left, right, key, 0, pre, f);
	}
	if (!f) cout<<"CORRECT\n";
	else cout<<"INCORRECT\n";
	return 0;
}
