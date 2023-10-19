/*
* @Author: lenovo
* @Date:   2023-10-19 22:06:35
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-19 22:12:26
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            ans.push_back(ans[i-1]*nums[i]);
        }
        int prod = 1;
        for(int i=n-1; i>=0 ;i--){
            int prev = i-1;
            ans[i] = (prev>=0?ans[prev]:1)*prod;
            prod *= nums[i];
        } 
        return ans;
    }
};
/**
 * We calculate the product of the array from left to right and store it.
 * Then compute it from right to left.
 * In the right to left operation we don't include the current index. 
 * Time Complexity : O(N)
 * Space Complecity : O(N)
 */