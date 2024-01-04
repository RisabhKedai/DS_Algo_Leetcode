/*
* @Author: lenovo
* @Date:   2024-01-04 21:35:27
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-05 22:33:26
*/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = -1;
        int i = 0; 
        int j = n-1;
        while(i<j) {
            ans = max(nums[i++]+nums[j--],ans);
        }
        return ans;
    }
};

/**
 * Sort the array and then pair maximum element with minimum one
 *
 * Time complexity: O(N log N)
 * Space complexity : O(1)
 */