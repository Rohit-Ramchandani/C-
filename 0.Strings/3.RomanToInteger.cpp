#include<bits/stdc++.h>
using namespace std;

int romantoint(string s)
{
    int tmp = 0;
    int num = 0;
    int len = s.length();
    int itr = 0;

    /* Make a map of the already defined 
       values along with their values*/
    unordered_map <char,int> map;
    map.insert(pair<char,int> ('I',1));
    map.insert(pair<char,int> ('V',5));
    map.insert(pair<char,int> ('X',10));
    map.insert(pair<char,int> ('L',50));
    map.insert(pair<char,int> ('C',100));
    map.insert(pair<char,int> ('D',500));
    map.insert(pair<char,int> ('M',1000));
    
    while(itr<len)
    {
        /* If current value is greater than next value add it directly 
        to the number*/
        if(itr ==(len-1) || map[s[itr]] >= map[s[itr+1]])
        {
            tmp = map[s[itr]];
            itr++;
            num = num + tmp;
        }

        /* If current value is smaller than the next value then 
        subtract it from next value and add it to the number*/
        else
        {
            tmp = map[s[itr+1]]-map[s[itr]];
            itr = itr + 2;
            num = num + tmp;
        }
    }
    return num;
}

int main()
{
    string s = "IV";
    cout << romantoint(s);
    return 0;
}