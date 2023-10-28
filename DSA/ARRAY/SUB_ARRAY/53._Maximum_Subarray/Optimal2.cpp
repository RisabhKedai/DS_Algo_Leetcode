/*
* @Author: lenovo
* @Date:   2023-10-27 23:08:57
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-27 23:09:00
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int su = 0;
        int ma = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            su += nums[i];
            ma = max(su,ma);
            if(su<0){
                su = 0;
            }
        }
        return ma;
    }
};

/**
 * This problem is solved by using Kadane's algorithm.
 * There are 2 variables. one stores the runnins sum and one stores the  
 * answer. whenever the running sum is positive, this can contribute to the
 * answer. If not then the running sum can be made 0 and can start the running sum again. 
 * 
 * Time complexity : O(N)
 * Space complexity : O(1)  
 */