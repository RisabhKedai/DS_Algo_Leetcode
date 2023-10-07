/*
* @Author: lenovo
* @Date:   2023-10-02 23:18:55
* @Last Modified by:   lenovo
* @Last Modified time: 2023-10-02 23:20:54
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                c++;
                int temp = nums[c];
                nums[c] = nums[i];
                nums[i] = temp;
            }
        }
    }
};

/**
 * Similar to partition function of the Quick sort
 * Store the last index were a non zero was found. 
 * Next time a non zero is found excnage it with the space next to the stored position. 
 */