/*
* @Author: lenovo
* @Date:   2023-10-25 22:59:15
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-26 22:50:55
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            if(nums[i]<=0){
                i++;
                continue;
            }
            int correct = nums[i] - 1;
            if(nums[i]<=nums.size() && nums[i]!=nums[correct]){
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            }else{
                i++;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

/**
 * Cycle sort is applicable here. 
 * Take one index and if it is positive and in the given range,
 * Place it in its place. Now the replaced number is taken and checked for the same. 
 * If one cycle is done move to next index. 
 * 
 * After all the cycles have ended then we have all the numbers in their corresponding indices.
 * ind0->1, ind1->2 ...
 * If it is not in place it means there is a missing number and return i+1 
 * that is the number that should be there at that index. 
 * 
 * Time complexity : O(N)
 * Space complexity : O(1)
 */