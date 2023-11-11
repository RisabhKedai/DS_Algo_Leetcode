/*
* @Author: lenovo
* @Date:   2023-10-19 23:14:04
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-19 23:16:36
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1,0);
        int ans = 0;
        for(int i=2; i<=n; i++){
            for(int j=1;j<i;j++){
                dp[i] = max(prices[i-1]-prices[j-1]+dp[j-1],dp[i]);
                ans = max(ans,dp[i]);
            }
                    cout<<dp[i]<<" ";
        }
        return ans;
    }
};
/**
 * DP i stores the profit upto the given day. 
 * For each day of 'sale', we check which day it can be bought previously to make max profit. 
 *
 * Time Complexity : O(n^2)
 * Space Complexity : O(n)
 *
 * Results in TLE
 */