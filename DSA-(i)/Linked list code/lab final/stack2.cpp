#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> st;
    vector<char> v;
    string s;
    cin>>s;
    for(char c:s)
    {
        if(st.empty() || st.top()!=c)
        {
            st.push(c);
        }
    }
    string str = "";
    while(!st.empty())
    {
        str+=st.top();
        st.pop();
    }
    reverse(str.begin(),str.end());
    cout<<str;
    return 0;
}
