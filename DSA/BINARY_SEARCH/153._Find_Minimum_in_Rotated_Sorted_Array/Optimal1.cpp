/*
* @Author: lenovo
* @Date:   2024-02-06 20:12:52
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-06 20:14:52
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = n-1;
        while(beg<end){
            int mid = (beg+end)/2;
            if(nums[beg]<=nums[mid]  && nums[mid+1]<=nums[end]){
                return min(nums[beg],nums[mid+1]);
            }else if(nums[beg]<=nums[mid]){
                beg = mid+1;
            }else{
                end = mid;
            }
        }
        return nums[beg];
    }
};

/**
 * Minimum number will always be present in the unsorted part of the array.
 * Except if the array is unsorted / the array is rotated till the middle
 *
 * Ex : [3,4,5,6] / [5,6,3,4]
 *
 * Time complexity : O(logN)
 * Space complexity : O(1)
 */