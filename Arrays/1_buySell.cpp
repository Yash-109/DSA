// LeetCode 121: Best Time to Buy and Sell Stock
// Time Complexity: O(n) - single pass through the array
// Space Complexity: O(1) - only using constant extra space

/*
 * Approach (Track Minimum Price + Max Profit)
 * ------------------------------------------
 * - We want to choose a day to buy and a later day to sell to maximize profit.
 * - Maintain:
 *     bestBuy   -> minimum price seen so far (best day to buy up to i)
 *     maxProfit -> maximum profit achievable so far.
 * - For each price on day i (starting from 1):
 *     - Possible profit if bought at bestBuy and sold today is
 *         prices[i] - bestBuy.
 *     - Update maxProfit with this if it is larger.
 *     - Update bestBuy to be min(bestBuy, prices[i]) for future days.
 * - At the end, maxProfit is the answer (0 if no profitable transaction).
 *
 * Pseudocode
 * ---------
 *   function maxProfit(prices):
 *       bestBuy = prices[0]
 *       maxProfit = 0
 *
 *       for i from 1 to prices.size()-1:
 *           profitToday = prices[i] - bestBuy
 *           if profitToday > maxProfit:
 *               maxProfit = profitToday
 *
 *           if prices[i] < bestBuy:
 *               bestBuy = prices[i]
 *
 *       return maxProfit
 */

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