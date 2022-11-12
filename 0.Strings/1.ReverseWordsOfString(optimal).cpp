#include<bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    int left = 0;
    int right = s.size();

    string temp = "";
    string ans = "";

    s+=" ";
    while(left <= right)
    {
        char ch = s[left];
        if(ch == ' ')
        {
            if(ans == "")
            {
                ans = temp;
            }
            else
            {
                ans = temp + " " + ans;
            }
            temp = "";
        }
        else
        {
            temp += ch;
        }
        left++;
    }
    return ans;
}

int main()
{
    string s = "  ASUS is good for gaming  ";
    cout << "Before Reverse"<< endl;
    cout << s << endl;

    cout << "After Reverse"<< endl;
    cout << reverse(s) << endl;    
    return 0;
}