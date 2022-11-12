#include<bits/stdc++.h>
using namespace std;

int convertToInteger(string s)
{
    int ans = 0;

    for(int i=0; i<s.size(); i++)
    {
        int x = s[i]-'0';
        if(x<=9 && x >=0)
        {
            ans = ans*10 + x;
        }
        else
        {
            return -1;
        }
    }
    return ans;
}

int main()
{
    string s = "1a24";
    cout << convertToInteger(s) << endl;
    return 0;
}