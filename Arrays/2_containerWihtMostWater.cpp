// LeetCode 11: Container With Most Water
// Time Complexity: O(n^2) - brute force approach
// Space Complexity: O(1) - only using constant extra space

#include<bits/stdc++.h>
using namespace std;

// brute force approach  
int container(int arr[], int size)
{
    int ans = 0;
    int width, height, currWater;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        { 
            width = j - i;
            height = min(arr[i], arr[j]);
            currWater = width * height;

            ans = max(ans, currWater);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(arr) / sizeof(arr[0]);  
    cout << container(arr, size);
    return 0;
}

// bruteforce:o(n^2) means 10^5*2=10^20 which is greater than 10^8 so Time  Limit Exciding (TLE)  we have to make it optimal

//optimal TC: O(n)  using two pointer approach,

class Solution{
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int lp=0,rp=height.size()-1;
        while(lp<rp)
        {
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int currWater= w*ht;
            maxWater=max(maxWater,currWater);

            height[lp]<height[rp] ? lp++ : rp--;  //ternary operator
        }

        return maxWater;
    }
};
 