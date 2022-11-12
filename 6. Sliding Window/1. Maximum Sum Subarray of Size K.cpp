#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int K, vector<int>& Arr , int N)
{
    int i=0;
    int j=0;
    int sum=0; 
    int max_sum = INT_MIN;
    
    while(j<N)
    {
        // Do the calculations(calculate the sum) and increase the window size
        sum += Arr[j];

        // If window size is not reached increase the window size
        if(j-i+1 < K)
            j++;

        // Window size reached do the calculations change max if new max found
        else if(j-i+1 == K)
        {
            max_sum = max(sum,max_sum);
            
            // Now remove the calculation
            sum = sum-Arr[i];

            // Slide the window
            i++;
            j++;
        }
    }
    return max_sum;
}

int main()
{
	int ans;
	vector<int> nums = {100, 200, 300, 400};
	int size = 2;
	ans = maximumSumSubarray(size,nums,4);
	cout << ans;
	return 0;
}