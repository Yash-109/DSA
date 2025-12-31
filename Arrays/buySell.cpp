// LeetCode 121: Best Time to Buy and Sell Stock
// Time Complexity: O(n) - single pass through the array
// Space Complexity: O(1) - only using constant extra space

#include <vector>
#include <algorithm>    
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int bestBuy=prices[0];

        for(int i=1;i<prices.size();i++)
        {
           if(prices[i]>bestBuy)
           {
            maxProfit=max(maxProfit,prices[i]-bestBuy);
           }
           bestBuy=min(bestBuy,prices[i]);
        }
        return maxProfit;
    }
};