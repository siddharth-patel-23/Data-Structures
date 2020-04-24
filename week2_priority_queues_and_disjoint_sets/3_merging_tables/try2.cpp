#include <bits/stdc++.h>
using namespace std;

struct use
{
    int r;
    int ad;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, j, d, s, mx=0;
	cin>>n>>m;
	vector<use> v(n+1);
	v[0].r=0;
	v[0].ad=0;
	for (i=1;i<=n;i++) cin>>v[i].r, v[i].ad=0, mx=max(mx, v[i].r);
	for (i=0;i<m;i++)
	{
	    cin>>d>>s;
	    if (d==s)
	    cout<<mx<<"\n";
	    else
	    {
	        int t=d;
	        while(v[d].ad!=0)
	        {
	            d=v[d].ad;
	        }
	        if (t!=d)
	        v[t].ad=d;
    	    if (v[s].r>0)
    	    {
    	        v[d].r+=v[s].r;
    	        v[s].r=0;
    	        v[s].ad=d;
    	        mx=max(mx, v[d].r);
    	    }
    	    else
    	    {
    	        if (v[s].ad==0)
    	        v[s].ad=d;
    	        else
    	        {
    	            while(v[s].ad!=0 && v[s].ad!=d)
    	            {
    	                int tmp=s;
    	                s=v[s].ad;
    	                v[tmp].ad=d;
    	            }
    	            if (v[s].ad==0)
    	            {
    	                v[d].r+=v[s].r;
    	                v[s].r=0;
    	                v[s].ad=d;
    	                mx=max(mx, v[d].r);
    	            }
    	        }
    	    }
    	    cout<<mx<<"\n";
	    }
	}
	return 0;
}
