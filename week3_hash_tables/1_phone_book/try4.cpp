#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	string a,b,c;
	unordered_map<string, string> m;

	for (i=0;i<n;i++)
	{
	    cin>>a;
	    if (a=="add")
	    {
	        cin>>b>>c;
	        m[b]=c;
	    }
	    else if (a=="find")
	    {
	        cin>>b;
	        if (m.find(b)!=m.end())
	            cout<<m[b]<<"\n";
	        else cout<<"not found\n";
	    }
	    else if (a=="del")
	    {
	        cin>>b;
	        m.erase(b);
	    }
	}
	return 0;
}
