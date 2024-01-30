/*
* @Author: lenovo
* @Date:   2024-01-30 21:10:34
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-30 21:11:24
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size()-1;
        int ans = -1;
        while(beg <= end){
            int mid = (beg+end)/2;
            if(target <= nums[mid]){
                end = mid-1;
                ans = mid;
            }else{
                beg = mid+1;
            }
        }
        if(ans==-1)
        return nums.size();
        return ans;
    }
};

/**
 * Binary search to find first position with nums[i] >= target
 * 
 * Time complexity : O(logN)
 * Space complexity : O(1)
 */