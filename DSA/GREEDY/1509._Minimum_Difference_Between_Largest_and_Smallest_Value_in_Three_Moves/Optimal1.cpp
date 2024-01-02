/*
* @Author: lenovo
* @Date:   2024-01-02 21:54:52
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-02 21:57:50
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums.size()<=4){
            return 0;
        }
        int poss1 = nums[n-1] - nums[3];
        int poss3 = nums[n-2] - nums[2];
        int poss4 = nums[n-3] - nums[1];
        int poss2 = nums[n-4] - nums[0];
        return min(min(poss1,poss2),min(poss3,poss4));
    }
};

/**
 * if the array length is less than equal to 4 all the elements can be made equal and thus difference can be 0.
 * For 5 or more than that, the changed elements can all be on the left side, all on right side, 2 left 1 right or 1 left 2 right.
 * Accordingly find the minimum possibility.
 * 
 * Time complexity : O(nlog(n))
 * Space complexity : O(1)
 */