#include <bits/stdc++.h>
using namespace std;

struct use
{
    char data;
    int position;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	int n, i;
	cin>>s;
	stack<use> st;
	n=s.size();
	bool f=false;
	for (i=0;i<n;i++)
	{
	    if (s[i]=='(' || s[i]=='[' || s[i]=='{')
	    {
	        use u;
	        u.data=s[i];
	        u.position=i+1;
	        st.push(u);
	    }
	    else if (s[i]=='}' || s[i]==']' || s[i]==')')
	    {
	        if (st.empty())
	        {
	            f=true;
	            break;
	        }
	        if (s[i]=='}' && st.top().data=='{') st.pop();
	        else if (s[i]==']' && st.top().data=='[') st.pop();
	        else if (s[i]==')' && st.top().data=='(') st.pop();
	        else
	        {
	            f=true;
	            break;
	        }
	    }
	}
	if (f)
	cout<<i+1;
	else
	{
	    if (!st.empty())
	    {
	        use u;
	        while(!st.empty())
	        {
	            u=st.top();
	            st.pop();
	        }
	        cout<<u.position;
	    }
	    else 
	    cout<<"Success";
	}
	return 0;
}
