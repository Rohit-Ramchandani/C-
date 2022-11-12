#include<bits/stdc++.h>
using namespace std;

string reverse(string s)
{   
    stack<string> st;
    string str="";
    s +=" ";
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]==' ')
        {
            st.push(str);
            str="";            
        }
        else str+=s[i];
    }

    string ans = "";
    while(st.size()!=1)
    {
        ans += st.top() + " ";
        st.pop();
    }

    ans += st.top();
    return ans;
}

int main()
{
    string st = "Asus is good for gaming";
    cout << "Before Reversing the String" << endl;
    cout << st << endl;

    cout << "After Reversing the String" << endl;
    cout << reverse(st) << endl;

    return 0;
}