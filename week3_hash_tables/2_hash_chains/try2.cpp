#include <bits/stdc++.h>
using namespace std;

long long int hs(string s, vector<long long int> x, long long int p, long long int m)
{
    long long int ans=0;
    for (long long int i=0;i<s.size();i++)
    {
        ans+=(int)s[i]*x[i];
        ans%=p;
    }
    
    return ans%m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int m, n, i, j, p=1e9+7, check, mul=263;
	string a, b;
	cin>>m;
	cin>>n;
	vector<string> v[m];
	vector<long long int> x(15);
	x[0]=1;
	for (i=1;i<15;i++) 
	{
	   x[i]=mul;
	   mul*=263;
	   mul%=p;
	}
// 	string s1="HellO", s2="world";
	
// 	cout<<hs(s1, x, p, m)<<"\n";
// 	cout<<hs(s2, x, p, m)<<"\n";
	for (i=0;i<n;i++)
	{
	    cin>>a; 
	    if (a=="add")
	    {
	        cin>>b;
	        long long int h=hs(b, x, p, m);
	       // cout<<h<<"\n";
	        bool f=false;
	        for (j=0;j<v[h].size();j++)
	        {
	            if (b==v[h][j]) 
	            {
	                f=true;
	                break;
	            }
	        }
	        if (!f) v[h].push_back(b);
	    }
	    else if (a=="del")
	    {
	        cin>>b;
	        long long int h=hs(b, x, p, m);
	       // cout<<h<<"\n";
	        for (j=0;j<v[h].size();j++)
	        {
	            if (b==v[h][j]) 
	            {
	                v[h].erase(v[h].begin()+j);
	                break;
	            }
	        }
	    }
	    else if (a=="find")
	    {
	        cin>>b;
	        long long int h=hs(b, x, p, m);
	       // cout<<h<<"\n";
	        bool f=false;
	        for (j=0;j<v[h].size();j++)
	        {
	            if (b==v[h][j]) 
	            {
	                f=true;
	                break;
	            }
	        }
	        if (f) cout<<"yes\n";
	        else cout<<"no\n";
	    }
	    else if (a=="check")
	    {
	        cin>>check;
	        sort(v[check].begin(), v[check].end());
	        for (j=0;j<v[check].size();j++)
	        {
	            cout<<v[check][j]<<" ";
	        }
	        cout<<"\n";
	    }
	}
	return 0;
}
