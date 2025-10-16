#include <bits/stdc++.h>
using namespace std;
bool valid_parenthesis(string str)
{
    stack<char> s;
    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else
            {
                if (c == ')' && s.top() == '(')
                {
                    s.pop();
                }
                else if (c == '}' && s.top() == '{')
                {
                    s.pop();
                }
                else if (c == ']' && s.top() == '[')
                {
                    s.pop();
                }
                else
                    return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
        return false;
}
int main()
{

    string str;
    cin >> str;
    if (valid_parenthesis(str))
    {

        cout << "Valid" << endl;
    }
    else
    {
        cout << "Not Valid" << endl;
    }
    return 0;
}