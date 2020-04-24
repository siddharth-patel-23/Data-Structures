#include <bits/stdc++.h>
using namespace std;

long long int hs(string s, long long int mod)
{
    long long int ans=0, x=263;
    for (long long int i=s.size()-1;i>=0;i--)
    {
        ans=(ans*x+s[i])%mod;
    }
    return ans%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int m=203, mod=1e9+7, pHs, t, p, y=1, i, x=263;
	string P, T;
	cin>>P;
	cin>>T;
	pHs=hs(P, mod);
	t=T.size();
	p=P.size();
	vector<long long int> useHs(t-p+1);
	for (i=1;i<=p;i++)
	{
	    y=(y*x)%mod;
	}
	useHs[t-p]=hs(T.substr(t-p, p), mod); 
// 	cout<<useHs[t-p]<<"\n";
	for (i=t-p-1;i>=0;i--)
	{
	    useHs[i]=((useHs[i+1]*x+T[i]-y*T[i+p])%mod+mod)%mod;
	   // cout<<useHs[i]<<" ";
	}
// 	cout<<"\n";
// 	cout<<pHs<<"\n";
// 	cout<<useHs[4]<<"\n";
	for (i=0;i<t-p+1;i++)
	{
	   // cout<<T.substr(i, p)<<"\n";
	    if (useHs[i]!=pHs)
	    continue;
	    if (T.substr(i, p)==P)
	    cout<<i<<" ";
	}
	return 0;
}
