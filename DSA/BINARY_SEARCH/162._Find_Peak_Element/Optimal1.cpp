/*
* @Author: lenovo
* @Date:   2024-02-03 10:16:06
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-03 10:18:04
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(auto i=0; i<n; i++) {
            bool left = true, right=true;
            if(i>=1 && nums[i]<=nums[i-1]){
                left = false;
            }
            if(i<=n-2 && nums[i+1]>=nums[i]){
                right = false;
            }
            if(left && right){
                return i;
            }
        }
        return -1;
    }
};

/**
 * Thoufh the bunary search space is a bit large but
 * eventually as the search continues, the search space will be reduced 
 * to a mountain array only. 
 * Because we are checking the direction of slant and accordingly increasing /
 * decreasing the mid
 *
 * Time complexity:O(log(n))
 * Space complexity:O(1)
 */