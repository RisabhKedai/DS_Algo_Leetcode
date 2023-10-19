/*
* @Author: lenovo
* @Date:   2023-10-19 23:17:00
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-19 23:23:45
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for(int i=1; i<n; i++){
            if(prices[i]>=prices[i-1]){
                ans += prices[i]-prices[i-1];
            }
        }
        return ans;
    }
};

/**
 * Suppose a,b,c denote prices on 3 consecutive days. 
 *
 * If b>=a we can buy on a and sell on b and profit = b-a
 * Now if c is greater than b, c-b will make up the difference between 
 * c and a which is what we want because the tot profit is c-a.
 * Thus subtracting from the previous smaller element always completes the chain
 *
 * Now if c is smaller than b, the logic won't simply consider c and move on
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */