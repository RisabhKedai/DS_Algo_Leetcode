/*
* @Author: lenovo
* @Date:   2023-10-16 06:06:21
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-16 06:07:55
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if((nums[i]+nums[j] > nums[k]) && 
                    (nums[i]+nums[k] > nums[j]) &&
                    (nums[j]+nums[k] > nums[i])){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

/**
 * Take all the possible triplets and check if it is valid or not
 *
 * Time Complexity : O(n^3)
 * Space COmplexity : O(1)
 */