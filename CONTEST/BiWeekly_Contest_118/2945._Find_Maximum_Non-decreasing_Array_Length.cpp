/*
* @Author: lenovo
* @Date:   2023-11-26 14:25:51
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-26 21:27:15
*/


class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<pair<long long, long long>> dp(n,{0,INT_MAX});
        vector<long long> pref(n,0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = nums[i] + pref[i-1];
        }
        dp[0] = {1,nums[0]};
        for(int i=1; i<n; i++) {
            int prev_len = dp[i-1].first;
            int prev_sum = dp[i-1].second;
            if(nums[i] >= prev_sum) {
                dp[i].first = max(dp[i-1].first + 1, dp[i].first);
                if(dp[i].first == dp[i-1].first + 1){
                    dp[i].second = min((long long)nums[i], dp[i].second);
                }
            } else {
                dp[i].first = max(dp[i].first, dp[i-1].first);
                if(dp[i].first == dp[i-1].first) {
                    dp[i].second = min(dp[i].second, dp[i-1].second + (long long)nums[i]);
                }
            }
            int low = i, high = n-1, idx = -1;
            while(low<=high) { 
                int mid = (low+high)/2;
                if(pref[mid] - pref[i-1] >= dp[i-1].second) {
                    idx = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            if(idx != -1) {
                dp[idx].first = max(dp[idx].first, dp[i-1].first+1);
                if(dp[idx].first == dp[i-1].first + 1){
                    dp[idx].second = min(dp[idx].second ,(long long) pref[idx]-pref[i-1]);
                }
            }
        }
        return dp.back().first;
    }
};

/**
 * Intuition
 * =========
 * Assuming we're doing backtracking solution for this problem. Assuming we're at index i of nums, we're having an building array that satisfy the solution requirements (non-decreased). Let call last element we have in our building array is last_sum. There are 2 cases:
 * 	Case 1: nums[i] >= last_sum, we just push nums[i] to our building array.
 * 	Case 2: nums[i] < last_sum, we have 2 options:
 * 
 * 2.1: add nums[i] to last_sum, this will make our building array keeps being non-decreased. last_sum now will be nums[i] + last_sum
 * 2.2: we'll find the smallest j (j > i), such that:
 * 		nums[i] + nums[i + 1] + ... + nums[j] >= last_sum
 * 		and will jump to j + 1, last_sum now will be nums[i] + nums[i + 1] + ... + nums[j].
 * 		
 * In case 2.2, it's easy to see that there's no point to go further than j for now. Even if nums[j + 1] + ... + nums.back() < nums[i] + nums[i + 1] + ... + nums[j], we can go back to case 2.1 later when we're at j+1, it's not a problem to care when we're at i.
 * 
 * Approach
 * ========
 * 
 * Based on the backtracking solution, we'll go into the dp solution. Let dp[i] is the answer for the problem at index i. But we will keep another value indicates the minimum last_sum we can have. So our dp[i] is actually a pair of {answer at i, last_sum}. Case 2.2 can be optimized with binary search + prefix sum. The solution is quite straight forward from the backtracking solution.
 * You may ask: "What if I have another solution at index i that have less elements, but my last_sum is smaller, so it can be optimized further?". My answer is there's no case like that :). It's not hard to prove it.
 * 
 * Complexity
 * ==========
 * Time complexity: O(nlogn)
 * Space complexity O(n)
 */