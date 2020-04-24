#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i, b;
	cin>>n;
	string a, c;
	
	unordered_map<int, string> m;

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
