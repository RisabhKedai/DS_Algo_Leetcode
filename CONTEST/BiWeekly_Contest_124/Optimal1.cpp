/*
* @Author: lenovo
* @Date:   2024-02-18 11:40:22
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-18 11:43:37
*/

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        map<int,int> dp;
        for(int i=0; i<n; i++){
            int a = dp[nums[i]-1] + 1, b=dp[nums[i]]+1;
            dp[nums[i]] = max(dp[nums[i]],a);
            dp[nums[i]+1] = max(dp[nums[i]+1],b);
            ans = max(max(dp[nums[i]],dp[nums[i]+1]),ans);
        }
        return ans;
    }
};

/**
 * Intuition
 * The intution for this problem was to consider every number to stay in two states, 
 * this is num[i], or nums[i] + 1, now consider the defination of DP variable as 
 * DP[a] = maximum length of consicutive nums we can create by considering a as the end of that sequence
 * 
 * Approach
 * Now if you sort the nums and apply iteratively the upper defination of DP and keep on finding the maximum value for 
 * DP[nums[i]] or DP[nums[i] + 1] by this approach 
 * DP[nums[i]] = max(DP[nums[i] - 1], DP[nums[i]]) 
 * you can find the ans, by taking max of DP.
 *
 * Time Complexity : O(N)
 * Space complexity : O(N)
 */