/*
* @Author: lenovo
* @Date:   2024-02-02 22:38:39
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-02 22:41:21
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0, end = n-1;
        while(beg<=end){ 
            int mid = (beg+end)/2;
            // cout<<mid<<endl;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid]>=nums[beg]){
                if(nums[beg]<=target && target<=nums[mid]){
                    end = mid-1;
                }else{
                    beg = mid+1;
                }
            }else{
                if(nums[mid]<target && target<=nums[end]){
                    beg = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};

/**
 * There will be 2 halves of the array. 
 * Atleast one will always be sorted. 
 * We can leverage this. In case the first half is sorted we shall check ,
 * whether target lies in the 1st half or not. If not It will be in the 2nd unsorted half
 * Using this go down to a single element and return answer accordingly
 *
 * Time Complexity:O(logN)
 * Space Complexity:O(1)
 */