/*
* @Author: lenovo
* @Date:   2024-02-05 22:13:28
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-05 22:17:15
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0,end = n-1;
        int mid = (beg+end)/2;
        if(nums[beg] == nums[mid] && nums[mid]==nums[end]){
            return find(nums.begin(),nums.end(),target)!=nums.end();
        }
        while(beg<end){
            mid = (beg+end)/2;
            if(nums[beg]<=nums[mid]){
                if(nums[beg]<=target && target<=nums[mid]){
                    end = mid;
                }else{
                    beg = mid+1;
                }
            } else {
                if(nums[mid+1]<=target && target<=nums[end]){
                    beg = mid+1;
                }else{
                    end = mid;
                }
            }
        }
        return nums[beg]==target;
    }
}; 

/**
 * Use similar divide and conquer approach as in the previous variant
 * of the problem with no repeated elements.
 * If a portion is sorted, check in that one and proceed to other portion otherwise. 
 *
 * However this approach won't work in case there are duplicate element because then
 * the unsorted part may appear sorted.
 * 3,3,0,3,3,3,3
 * In this case the left part will appear sorted as arr[left]==arr[mid] but is actually not.
 *
 * In this case though arr[left]==arr[mid]==arr[end].
 * Check that condition. If that is true use linear search. 
 * Else use binary search
 *
 * Time complexity : O(N)
 * Space complexity : O(1)
 */