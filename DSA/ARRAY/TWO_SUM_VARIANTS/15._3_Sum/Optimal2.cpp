/*
* @Author: lenovo
* @Date:   2023-10-21 00:04:36
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-21 00:08:06
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n-2;i++){
            int low = i+1;
            int high = n-1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high] < 0){
                    low++;
                }
                else if(nums[i]+nums[low]+nums[high] > 0){
                    high--;
                }else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    while(low<high && nums[low]==nums[low+1]) low++;
                    low++;
                    while(low<high && nums[high]==nums[high-1]) high--;
                    high--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};

/**
 * The i pointer increases steadily. 
 * The low and high pointer point to the 2 ends of the remaining array
 * If sum of 3 is more than 0 decrease high 
 * If sum of 3 is less than 0 increase low
 * If it is low means found a combination
 * To avoid something same, change low and high till they are both different 
 *
 * Same goes for i. Make it totally different. 
 * add each found combination to answer.
 * https://leetcode.com/problems/3sum/solutions/3186495/best-c-3-solution-two-pointers-sorting-hash-table-brute-force-optimize/
 *
 * Time Complexity: O(N^2)
 * Space complexity: O(N)
*/