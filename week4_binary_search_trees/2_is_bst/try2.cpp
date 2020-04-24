#include <bits/stdc++.h>
using namespace std;

void inorder(vector<int> &check, vector<int> left, vector<int> right, vector<int> key, int i)
{
    if (left[i]!=-1) inorder(check, left, right, key, left[i]);
    check.push_back(key[i]);
    if (right[i]!=-1) inorder(check, left, right, key, right[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> left(n), right(n), key(n);
	vector<int> check;
	for (i=0;i<n;i++)
	{
	    cin>>key[i]>>left[i]>>right[i];
	}
	if (n>0)
	inorder(check, left, right, key, 0);
	bool f=false;
	for (i=1;i<n;i++)
	{
	    if (check[i]<check[i-1])
	    {
	        f=true;
	        break;
	    }
	}
	if (!f) cout<<"CORRECT\n";
	else cout<<"INCORRECT\n";
	return 0;
}
