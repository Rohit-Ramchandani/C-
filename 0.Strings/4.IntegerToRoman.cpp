#include<bits/stdc++.h>
using namespace std;

/* 
Integer to Roman 
7 to VII
15 to XV

I   IV    V   IX    X   XL    L   XC     C    CD     D    CM     M
1   4     5    9   10   40   50   90   100   400   500   900  1000

2,856 -> 1,856 -> 856 -> 356 -> 256 -> 156 -> 56 -> 6 -> 1 -> 0
M           M       D      C      C      C     L    V    I

MMDCCCLVI
*/

string integertoroman(int n)
{
    string roman = "";
    vector<string> rom = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    vector<int> rom_value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};

    for(int i = 13; n>0; i--)
    {
        while(n >= rom_value[i])
        {
            roman += rom[i];
            n = n - rom_value[i];
        }
    }
    return roman;
}

int main()
{
    int n = 2856;
    cout << integertoroman(n)<< endl;
    return 0;
}
