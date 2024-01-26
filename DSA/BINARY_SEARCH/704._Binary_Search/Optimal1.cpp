/*
* @Author: lenovo
* @Date:   2024-01-26 13:16:40
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-26 13:20:36
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size()-1;
        while(beg <= end){
            int mid = (beg+end)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                beg = mid+1;
            } else if(nums[mid]>target){
                end = mid-1;
            }
        }
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