/*
* @Author: lenovo
* @Date:   2023-11-18 22:06:36
* @Last Modified by:   lenovo
* @Last Modified time: 2023-11-18 22:59:36
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ctr1= 0;
        int ctr2= 0;
        int el1 = -1;
        int el2 = -1;
        for(int i=0; i<n; i++){
            if(ctr1==0  && nums[i]!=el2){
                ctr1=1;
                el1 = nums[i];
            }else if(ctr2==0 && nums[i]!=el1){
                ctr2 = 1;
                el2 = nums[i];
            }else if(nums[i] == el1){
                ctr1++;
            }else if(nums[i] == el2){
                ctr2++;
            }else{
                ctr1--;
                ctr2--;
            }
        }
        ctr1=0,ctr2=0;
        for(auto x : nums){
            if(x==el1){
                ctr1++;
            }else if(x==el2){
                ctr2++;
            }
        }
        vector<int> ans;
        if(ctr1>n/3){
            ans.push_back(el1);
        }
        if(ctr2>n/3){
            ans.push_back(el2);
        }
        return ans;
    }
};

/**
 * If we closely observe, in the given array, there can be a maximum of two integers that can occur more than floor(N/3) times.
 * 
 * If the array contains the majority of elements, their occurrence must be greater than the floor(N/3). 
 * Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. 
 * So when we traverse through the array we try to keep track of the counts of elements and the elements themselves 
 * for which we are tracking the counts. 
 * 
 * After traversing the whole array, we will check the elements stored in the variables. 
 * Then we need to check if the stored elements are the majority elements or not by manually checking their counts.
 *
 * This intuition is simply the logic of cancellation i.e. a variation of Moore’s Voting Algorithm 
 * that we used in the problem Majority Element (> N/2).
 *
 * Why we are adding extra checks like el2 != v[i] and el1 != v[i] in the first if statements?
 * Let’s understand it using an example:
 * Assume the given array is: {2, 1, 1, 3, 1, 4, 5, 6}. Now apply the algorithm without the checks:
 *
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 */