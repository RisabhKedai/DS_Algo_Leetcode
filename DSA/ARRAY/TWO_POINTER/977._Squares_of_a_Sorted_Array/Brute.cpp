class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};

/**
 * Simple approach is that we take each element in the array and square it up. 
 * After that we just sort it up and return the answer
 * Time complexity: O(n) [for squaring] + O(nlog(n)) [sorting] = O(nlog(n))
 * Space complexity: O(1)
 */