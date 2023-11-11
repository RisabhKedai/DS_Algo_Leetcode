/*
* @Author: lenovo
* @Date:   2023-10-19 22:14:01
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-19 22:29:09
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0];
        int pro = 0;
        int n = prices.size();
        for(int i=1; i<n; i++){
            pro = max(pro,prices[i]-mi);  
            mi = min(prices[i],mi);
        }
        return pro;
    }
};
/**
 * Traverse from left to right
 * Then subtract the minimum price from the stock price on that day to get max profit
 * For each point keep storing the minimum price till that point
 * Repeat till the end and final profit is stored in the variable
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 */