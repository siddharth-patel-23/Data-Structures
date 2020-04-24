#include <bits/stdc++.h>
using namespace std;

long long int m1=1e9+7, m2=1e9+9, x=263;

// long long int pHash(string s, long long int m)
// {
//     long long int n=s.size(), ans=0;
//     for (int i=0;i<n;i++)
//     {
//         ans=(ans*x+s[i])%m;
//     }
//     return ans;
// }

long long int pow(long long int l, long long int m)
{
    long long int ans=1, tmp=x;
    while(l>0)
    {
        if (l&1) ans=(ans*tmp)%m;
        tmp=(tmp*tmp)%m;
        l/=2;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int q, i, n, a, b, l, am1, am2, bm1, bm2;
	string s;
	cin>>s;
	cin>>q;
	n=s.size();
	vector<long long int> phm1(n), phm2(n);
	phm1[0]=s[0];
	phm2[0]=s[0];
	for (i=1;i<n;i++)
	{
	    phm1[i]=(phm1[i-1]*x+s[i])%m1;
	    phm2[i]=(phm2[i-1]*x+s[i])%m2;
	}
	for (i=0;i<q;i++)
	{
	    cin>>a>>b>>l;
	    if (l==0)
	    {
	        cout<<"Yes\n";
	        continue;
	    }
	    if (a>0)
	    {
	        am1=((phm1[a+l-1]-(pow(l, m1)*phm1[a-1]))%m1+m1)%m1;
	        am2=((phm2[a+l-1]-(pow(l, m2)*phm2[a-1]))%m2+m2)%m2;
	    }
	    else
	    {
	        am1=phm1[a+l-1];
	        am2=phm2[a+l-1];
	    }
	    if (b>0)
	    {
	        bm1=((phm1[b+l-1]-(pow(l, m1)*phm1[b-1]))%m1+m1)%m1;
	        bm2=((phm2[b+l-1]-(pow(l, m2)*phm2[b-1]))%m2+m2)%m2;
	    }
	    else
	    {
	        bm1=phm1[b+l-1];
	        bm2=phm2[b+l-1];
	    }
	    
	    if (am1==bm1 && am2==bm2) cout<<"Yes\n";
	    else cout<<"No\n";
	}
	return 0;
}
