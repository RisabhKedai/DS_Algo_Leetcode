/*
* @Author: lenovo
* @Date:   2023-11-18 23:24:53
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-18 23:29:56
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-1;
        for(; i>=0; i--){
            if(i>=1 && nums[i]>nums[i-1]){
                break;
            }
        }
        i = max(i,0);
        i--;
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        // cout<<i<<endl;
        for(int j=n-1; j>i; j--){
            if(nums[j]>nums[i]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};

/**
 * Considering that we need to find the next larger permutation we must maintain the prefix as similar a possible.
 * Thus we check from behind when is the first time an element can be exchanged with the elements beyond it to get larger result. 
 * This means we check when is the index from the back where the increment only is happening. The first element from back shorter than its next element is changed,
 * With the next larger elements among the elements preceeding it. 
 *
 * After now that we have increased the permutuation, we want to keep is as low as possible. So we sort the remaining right half in inc order, 
 * easily done by revesing whatever elements are there. 
 *
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 */