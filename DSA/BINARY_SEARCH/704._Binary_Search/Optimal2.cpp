/*
* @Author: lenovo
* @Date:   2024-01-26 13:16:40
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-26 13:17:58
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(ans<nums.size() && nums[ans]==target)
        return ans;
        return -1;
    }
};

/**
 * Use the STL lower bound method to find maximum number in the array
 * which is less than or equals to the target element.
 *
 * Time complexity : O(LogN)
 * Space complexity : O(1)
 */