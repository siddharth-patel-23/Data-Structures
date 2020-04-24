#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	stack<int> st;
	int n, i;
	cin>>n;
	int mx=0;
	for (i=0;i<n;i++)
	{
	    string s;
	    int data;
	    cin>>s;
	    if (s=="push")
	    {
	        cin>>data;
	        if (mx<data) mx=data;
	        st.push(mx);
	    }
	    else if (s=="pop")
	    st.pop();
	    else if (s=="max")
	    cout<<st.top()<<"\n";
	}
	return 0;
}
