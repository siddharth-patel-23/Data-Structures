#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	string a,b,c;
	unordered_set<string> s;

	unordered_map<string, string> m;

	for (i=0;i<n;i++)
	{
	    cin>>a;
	    if (a=="add")
	    {
	        cin>>b>>c;
	        if (s.find(b)==s.end() && s.find(c)==s.end())
	        {
	            s.insert(b);
	            s.insert(c);
	            m[b]=c;
	            m[c]=b;
	        }
	        else if (s.find(b)==s.end())
	        {
	            s.insert(b);
	            s.erase(m[c]);
	            m[c]=b;
	        }
	        else if (s.find(c)==s.end())
	        {
	            s.insert(c);
	            s.erase(m[b]);
	            m[b]=c;
	        }
	    }
	    else if (a=="find")
	    {
	        cin>>b;
	        if (s.find(b)!=s.end())
	        cout<<m[b]<<"\n";
	        else cout<<"not found\n";
	    }
	    else if (a=="del")
	    {
	        cin>>b;
	        if (s.find(b)!=s.end())
	        {
	            s.erase(b);
	            s.erase(m[b]);
	            string tmp=m[b];
	            m.erase(m[b]);
	            m.erase(m[tmp]);
	        }
	    }
	}
	return 0;
}
