#include <bits/stdc++.h>
using namespace std;

long long int m1=1e9+7, m2=1e9+9, x=263;

long long int pHash(string s, long long int m)
{
    long long int n=s.size(), ans=0;
    for (int i=0;i<n;i++)
    {
        ans=(ans*x+s[i])%m;
    }
    return ans;
}

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

long long int isPresent(long long int key, vector<long long int> v, long long int l, long long int r)
{
    while(l<=r)
    {
        long long int mid=(l+r)/2;
        if (v[mid]==key) return mid;
        else if (key<v[mid]) 
        {
            r=mid-1;
        }
        else l=mid+1;
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s, t;
	long long int n1, n2, i, j, k, x1, x2, pre1, pre2, cur1, cur2, cmp1, cmp2;
	while(cin>>s>>t)
	{
	    n1=s.size();
	    n2=t.size();
	    bool p=false;
	    if (n1>n2)
	    {
	        string tmp=s;
	        s=t;
	        t=tmp;
	        n1=s.size();
	        n2=t.size();
	        p=true;
	    }
	    bool f=false;
	    for (i=n1;i>0;i--)
	    {
	        
	        vector<long long int> vs1(n1-i+1), vs2(n1-i+1);
	       // string s1=s.substr(0, i);
	        x1=pow(i, m1);
	        x2=pow(i, m2);
	        vs1[0]=pHash(s.substr(0, i), m1);
	        vs2[0]=pHash(s.substr(0, i), m2);
	        for (j=1;j<n1-i+1;j++)
	        {
	            vs1[j]=((s[i+j-1]+x*vs1[j-1]-x1*s[j-1])%m1+m1)%m1;
	            vs2[j]=((s[i+j-1]+x*vs2[j-1]-x2*s[j-1])%m2+m2)%m2;
	        }
	        pre1=pHash(t.substr(0, i), m1);
	        pre2=pHash(t.substr(0, i), m2);
	        cmp1=isPresent(pre1, vs1, 0, n1-i);
	        cmp2=isPresent(pre2, vs2, 0, n1-i);
	        if (cmp1!=-1 && cmp2!=-1 && cmp1==cmp2)
	        {
	            if (p) cout<<0<<" "<<cmp1<<" "<<i<<"\n";
	            else cout<<cmp1<<" "<<0<<" "<<i<<"\n";
	            f=true;
	            break;
	        }
	        
	        for (j=1;j<n2-i+1;j++)
	        {
	            cur1=((t[i+j-1]+x*pre1-x1*t[j-1])%m1+m1)%m1;
	            cur2=((t[i+j-1]+x*pre2-x2*t[j-1])%m2+m2)%m2;
	            
	            cmp1=isPresent(cur1, vs1, 0, n1-i);
	            cmp2=isPresent(cur2, vs2, 0, n1-i);
	            
	            if (cmp1!=-1 && cmp2!=-1 && cmp1==cmp2)
    	        {
    	            if (p) cout<<j<<" "<<cmp1<<" "<<i<<"\n";
    	            else cout<<cmp1<<" "<<j<<" "<<i<<"\n";
    	            f=true;
    	            break;
    	        }
	            pre1=cur1;
	            pre2=cur2;
	        }
	        if (f) break;
	    }
	    if (!f) cout<<"0 0 0\n";
	}
	return 0;
}
