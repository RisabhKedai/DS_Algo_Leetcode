/*
* @Author: lenovo
* @Date:   2023-10-24 22:26:39
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-24 22:31:27
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return ((n*(n+1))/2) - accumulate(nums.begin(),nums.end(),0);
    }
};

/**
 * Since there should be integers in the range 0 to n as mentioned.
 * Their total sum should be n*(n+1) / 2.
 * But what is the actual sum. If we have that sum 
 * We can subtract that to find the missing element or 
 * the deviation from the expected value. 
 *
 * Time Complexity: O(1) to find the sum of the array
 * Space Complexity: O(1)
 */