/*
* @Author: lenovo
* @Date:   2024-02-05 22:12:03
* @Last Modified by:   lenovo
* @Last Modified time: 2024-02-05 22:13:08
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }
}; 

/**
 * Use linear search to search through each element
 * 
 * Time complexity : O(N)
 * Space complexity : O(1)
 */