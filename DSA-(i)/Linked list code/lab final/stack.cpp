#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                cout << "not valid" << endl;
                return 0;
            }
            else
            {
                if(c==')' && st.top()=='(')
                {
                    st.pop();
                }
                else if(c=='}' && st.top()=='{')
                   st.pop();
                else if(c==']' && st.top()=='[')
                   st.pop();
                else 
                {
                    cout<<"not valid"<<endl;
                    return 0;
                }
            }
        }
    }
    if(st.empty())
    {
        cout<<"valid"<<endl;
    }
    else
    {
        cout<<"not valid"<<endl;
    }
    return 0;
}