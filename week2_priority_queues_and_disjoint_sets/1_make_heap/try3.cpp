#include <bits/stdc++.h>
using namespace std;

void moveDown1(vector<int> &v, int id, int n, int &cnt)
{
    while(v[id]>v[2*id+1] && v[id]>v[2*id+2] && (2*id+2)<n)
    {
        if (v[2*id+1]<v[2*id+2])
        {
	        swap(v[2*id+1], v[id]); 
	       // cout<<id<<" "<<2*id+1<<"\n";
	        cnt++;
	        id=2*id+1;
        }
	    else 
	    {
	        swap(v[2*id+2], v[id]);
	       // cout<<id<<" "<<2*id+2<<"\n";
	        cnt++;
	        id=2*id+2;
	    }
    }
    while (v[id]>v[2*id+1] && (2*id+1)<n)
	{
        swap(v[2*id+1], v[id]);
        // cout<<id<<" "<<2*id+1<<"\n";
        cnt++;
        id=2*id+1;
	}
	while (v[id]>v[2*id+2] && (2*id+2)<n)
	{
	    swap(v[2*id+2], v[id]);
	   // cout<<id<<" "<<2*id+2<<"\n";
	    cnt++;
	    id=2*id+2;
	}
}

void moveDown2(vector<int> &v, int id, int n)
{
    while(v[id]>v[2*id+1] && v[id]>v[2*id+2] && (2*id+2)<n)
    {
        if (v[2*id+1]<v[2*id+2])
        {
	        swap(v[2*id+1], v[id]); 
	        cout<<id<<" "<<2*id+1<<"\n";
	       // cnt++;
	        id=2*id+1;
        }
	    else 
	    {
	        swap(v[2*id+2], v[id]);
	        cout<<id<<" "<<2*id+2<<"\n";
	       // cnt++;
	        id=2*id+2;
	    }
    }
    while (v[id]>v[2*id+1] && (2*id+1)<n)
	{
        swap(v[2*id+1], v[id]);
        cout<<id<<" "<<2*id+1<<"\n";
        // cnt++;
        id=2*id+1;
	}
	while (v[id]>v[2*id+2] && (2*id+2)<n)
	{
	    swap(v[2*id+2], v[id]);
	    cout<<id<<" "<<2*id+2<<"\n";
	   // cnt++;
	    id=2*id+2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n), tmp(n);
	for (i=0;i<n;i++) cin>>v[i], tmp[i]=v[i];
	int cnt=0;
	for (i=n/2;i>=0;i--)
	{ 
	    moveDown1(tmp, i, n, cnt);
	}
	cout<<cnt<<"\n";
	for (i=n/2;i>=0;i--)
	{ 
	    moveDown2(v, i, n);
	}
	return 0;
}
