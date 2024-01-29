/*
* @Author: lenovo
* @Date:   2024-01-29 21:32:52
* @Last Modified by:   lenovo
* @Last Modified time: 2024-01-29 21:34:15
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int beg = 0, end = nums.size()-1;
        int ans=-1, ansr=-1;
        while(beg<=end){
            int mid = (beg+end)/2;
            if(nums[mid] == target){
                ans = mid;
                end = mid-1;
            }else if(nums[mid] > target) {
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        beg = 0, end = nums.size()-1;
        while(beg<=end){
            int mid = (beg+end)/2;
            if(nums[mid] == target){
                ansr = mid;
                beg = mid+1;
            }else if(nums[mid] > target) {
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        return {ans, ansr};
    }
};
