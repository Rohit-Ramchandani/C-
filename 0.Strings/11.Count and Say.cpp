#include<bits/stdc++.h>
using namespace std;

string countSay(int n)
{
    if(n==1) return "1";
    if(n==2) return "11";

    string ans = "11";
    //Run loop till the nth integer
    for(int i=3; i<=n; i++)
    {
        //Temporary string for initialization  
        string temp = "";
        ans += '&';

        //Initialize count to 1
        int count = 1;

        // Iterate through the ans length
        for(int j=1; j<ans.length(); j++)
        {
            //Increase the count of equal to the last number
            if(ans[j] == ans[j-1])
            {
                count++;
            }
            //If not equal to last number
            if(ans[j] != ans[j-1])
            {
                //convert count to char and add to Temporary answer
                temp += count + '0';

                //append the number also
                temp += ans[j-1];
                
                //Reinitialize the count variable
                count = 1;
            }
        }
        // Insert the string calculated into the answer
        ans = temp;
    }
    return ans;
}

int main()
{
    int n = 5;
    cout << countSay(n)<< endl;
    return 0;
}

