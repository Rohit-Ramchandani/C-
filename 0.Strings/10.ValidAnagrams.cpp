#include<bits/stdc++.h>
using namespace std;

bool validAnagram(string s, string t)
{
    if(s.length()!=t.length())
        return false;

    unordered_map<char,int> map;
    for(int i=0; i<s.size(); i++)
    {
        map[s[i]]++;
        map[t[i]]--;
    }

    for(auto x : map)
    {
        if(x.second)
            return false;
    }

    return true;
}

int main()
{
    string s = "rohitX";
    string t = "tihor";


    if(validAnagram(s,t))
    {
        cout << "Valid Anagram"<< endl;
    }
    else
    {
        cout << "Not a valid Anagram" << endl;
    }
}