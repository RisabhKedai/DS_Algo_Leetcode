class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0;
        int r = n-1;
        int k = n-1;
        while(l<=r){
            if(abs(nums[l]) >= abs(nums[r])){
                ans[k] = nums[l]*nums[l];
                l++;
            }else{
                ans[k] = nums[r]*nums[r];
                r--;
            }
            k--;
        }
        return ans;
    }
};


/**
 * So the array can be divided into 2 halves:
 * Positive half and the negative half.
 * Each half is sorted because the entire array is sorted. 
 * Now upon squaring, numbers in each half would lose the sign
 * And both are sorted arrays. 
 * Now to find the sorted array overall we need to merge them using 2 pointers,
 * each pointing to the smallest element of their respective halves.
 * Time Complexity :O(n)
 * Space COmplexity: O(n)
 * */