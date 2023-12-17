/*
* @Author: lenovo
* @Date:   2023-12-17 12:56:56
* @Last Modified by:   lenovo
* @Last Modified time: 2023-12-17 12:59:09
*/

class Solution {
public:
    bool isPalindrome(int x){
        int y = 0;
        int z = x;
        while(x){
            y*=10;
            y+=x%10;
            x/=10;
        }
        return z==y;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int temp1 = nums[(n-1)/2];
        int temp2 = nums[n/2];
        while(!isPalindrome(temp2)) temp2--;
        while(!isPalindrome(temp1)) temp1++;
        long long cost1 = 0;
        long long cost2 = 0;
        for(int i=0; i<n; i++){
            cost1 += abs(temp1-nums[i]);
            cost2 += abs(temp2-nums[i]);
        }
        return min(cost1,cost2);
    }
};

/**
 * The idea is to find the closes palindromes to the median. 
 * In case there is one median then find the palindromes the left and right of it. 
 * In case there are 2 medians then find palindromes to the right of 1st and left of second.
 * Thos palindromes will be closest to the center. 
 *
 * Find which of the palindromes will result in lower costs and print the cost
 *
 * Time Complexity : O(N)
 * Soace Complexity : O(1)
 */